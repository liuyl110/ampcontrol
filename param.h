#ifndef PARAM_H
#define PARAM_H

#include <inttypes.h>

/* Integral circuits definitions */

#define TDA7439_IC				0x00
#define TDA7313_IC				0x01
#define TDA7318_IC				0x02

#define TDA7439_ADDR			0b10001000
#define TDA7313_ADDR			0b10001000

/* TDA7439 function selection */
#define TDA7439_INPUT_SELECT	0x00
#define TDA7439_INPUT_GAIN		0x01
#define TDA7439_PREAMP			0x02
#define TDA7439_BASS			0x03
#define TDA7439_MIDDLE			0x04
#define TDA7439_TREBLE			0x05
#define TDA7439_VOLUME_RIGHT	0x06
#define TDA7439_VOLUME_LEFT		0x07

/* TDA7313 data bytes */
#define TDA7313_VOLUME	0x00
#define TDA7313_SP_FRONT_LEFT	0x80
#define TDA7313_SP_FRONT_RIGHT	0xA0
#define TDA7313_SP_REAR_LEFT	0xC0
#define TDA7313_SP_REAR_RIGHT	0xE0
#define TDA7313_SW	0x40
#define TDA7313_BASS			0x60
#define TDA7313_TREBLE			0x70

#define MUTE_ON					1
#define MUTE_OFF				0

#define LOUDNESS_ON				0
#define LOUDNESS_OFF			1

typedef struct {
	int8_t value;
	int8_t min;
	int8_t max;
	uint8_t step;
	void *label;
	void (*set)(int8_t value);
} regParam;

regParam volume;
regParam bass;
regParam middle;
regParam treble;
regParam preamp;
regParam balance;
regParam gain[4];

uint8_t chan;
uint8_t loud;
uint8_t mute;
uint8_t chanCnt;

uint8_t tdaIC;

void loadParams(void);
void saveParams(void);

void incParam(regParam *param);
void decParam(regParam *param);

void nextChan(void);
void setChan(uint8_t ch);

void muteVolume(void);
void unmuteVolume(void);

void switchMute(void);
void switchLoudness(void);

void showBoolParam(uint8_t value, const uint8_t *parLabel);
void showParam(regParam *param);

#endif /* PARAM_H */
