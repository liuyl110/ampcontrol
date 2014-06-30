#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include "adc.h"
#include "fft.h"

static int16_t f_l[FFT_SIZE];			/* Real values for left channel */
static int16_t f_i[FFT_SIZE];			/* Imaginary values */
static uint8_t buf[FFT_SIZE / 2];		/* Previous fft results: both left and right */

static const uint8_t hannTable[] PROGMEM = {
	  0,   1,   3,   6,  10,  16,  22,  30,
	 38,  48,  58,  69,  81,  93, 105, 118,
	131, 143, 156, 168, 180, 191, 202, 212,
	221, 229, 236, 242, 247, 251, 254, 255,
};

void adcInit()
{
	TCCR0 = 0b001;						/* Timer0 prescaller = 1 (8 MHz) */

	ADCSRA |= (1<<ADEN);
	ADCSRA |= (1<<ADPS2) | (1<<ADPS0);	/* ADC prescaler=32 (500 kHz) */

	ADMUX |= (1<<ADLAR);				/* Adjust result to left */

	return;
}

ISR (TIMER0_OVF_vect)
{
	ADCSRA |= 1<<ADSC;

	return;
};

static uint8_t revBits(uint8_t x)
{
	x = ((x & 0x15) << 1) | ((x & 0x2A) >> 1);	/* 00abcdef => 00badcfe */
	x = (x & 0x0C) | swap(x & 0x33);			/* 00badcfe => 00fedcba */

	return x;
}

static void getValues()
{
	uint8_t i = 0, j;
	uint8_t hv;
	TCNT0 = 0;							/* Reset timer */
	TIMSK |= (1<<TOIE0);				/* Enable compare/match interrupt */

	ADMUX &= ~(1<<MUX0);				/* Switch to left channel */
	while (!(ADCSRA & (1<<ADSC)));		/* Wait for start measure */

	do {
		j = revBits(i);
		if (i < FFT_SIZE / 2)
			hv = pgm_read_byte(&hannTable[i]);
		else
			hv = pgm_read_byte(&hannTable[FFT_SIZE - 1 - i]);

		while (ADCSRA & (1<<ADSC));				/* Wait for finish measure */
		f_l[j] = ADCH - DC_CORR;				/* Read left channel value */
		f_l[j] = (hv * f_l[j]) >> 6;	/* Apply Hann window */
		while (!(ADCSRA & (1<<ADSC)));			/* Wait for start measure */

		f_i[i++] = 0;
	} while (i < FFT_SIZE);

	TIMSK &= ~(1<<TOIE0);				/* Disable compare/match interrupt */

	return;
}

/* NEW value is displayed if bigger then OLD. Otherwise OLD-1 is displayed */
static void slowFall()
{
	uint8_t i;
	for (i = 0; i < FFT_SIZE / 2; i++) {
		if (f_l[i] < buf[i])
			buf[i]--;
		else
			buf[i] = f_l[i];
	}

	return;
}

uint8_t *getSpData()
{
	getValues();

	fftRad4(f_l, f_i);
	cplx2dB(f_l, f_i);

	slowFall();

	return buf;
}
