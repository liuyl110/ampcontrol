#include "tda731x.h"

#include "../i2c.h"

static uint8_t _input, _loudness;

void tda731xSetVolume(void)
{
	I2CStart(TDA731X_I2C_ADDR);
	I2CWriteByte(TDA731X_VOLUME | -sndPar[MODE_SND_VOLUME].value);
	I2CStop();

	return;
}

void tda731xSetBass(void)
{
	int8_t val = sndPar[MODE_SND_BASS].value;
	I2CStart(TDA731X_I2C_ADDR);
	I2CWriteByte(TDA731X_BASS | (val > 0 ? 15 - val : 7 + val));
	I2CStop();

	return;
}

void tda731xSetTreble(void)
{
	int8_t val = sndPar[MODE_SND_TREBLE].value;
	I2CStart(TDA731X_I2C_ADDR);
	I2CWriteByte(TDA731X_TREBLE | (val > 0 ? 15 - val : 7 + val));
	I2CStop();

	return;
}

void tda731xSetSpeakers(void)
{
	int8_t spFrontLeft = 0;
	int8_t spFrontRight = 0;

	int8_t spRearLeft = 0;
	int8_t spRearRight = 0;

	if (sndPar[MODE_SND_BALANCE].value > 0) {
		spFrontLeft -= sndPar[MODE_SND_BALANCE].value;
		spRearLeft -= sndPar[MODE_SND_BALANCE].value;
	} else {
		spFrontRight += sndPar[MODE_SND_BALANCE].value;
		spRearRight += sndPar[MODE_SND_BALANCE].value;
	}
	if (sndPar[MODE_SND_FRONTREAR].value > 0) {
		spRearLeft -= sndPar[MODE_SND_FRONTREAR].value;
		spRearRight -= sndPar[MODE_SND_FRONTREAR].value;
	} else {
		spFrontLeft += sndPar[MODE_SND_FRONTREAR].value;
		spFrontRight += sndPar[MODE_SND_FRONTREAR].value;
	}

	I2CStart(TDA731X_I2C_ADDR);
	I2CWriteByte(TDA731X_SP_FRONT_LEFT | -spFrontLeft);
	I2CWriteByte(TDA731X_SP_FRONT_RIGHT | -spFrontRight);
	I2CWriteByte(TDA731X_SP_REAR_LEFT | -spRearLeft);
	I2CWriteByte(TDA731X_SP_REAR_RIGHT | -spRearRight);
	I2CStop();

	return;
}

void tda731xSetGain(void)
{
	I2CStart(TDA731X_I2C_ADDR);
	I2CWriteByte(TDA731X_SW | (3 - sndPar[MODE_SND_GAIN0 + _input].value) << 3 | !_loudness << 2 | _input);
	I2CStop();

	return;
}

void tda731xSetInput(uint8_t in)
{
	_input = in;
	tda731xSetGain();

	return;
}

void tda731xSetMute(uint8_t val)
{
	I2CStart(TDA731X_I2C_ADDR);
	if (val) {
		I2CWriteByte(TDA731X_SP_FRONT_LEFT | TDA731X_MUTE);
		I2CWriteByte(TDA731X_SP_FRONT_RIGHT | TDA731X_MUTE);
		I2CWriteByte(TDA731X_SP_REAR_LEFT | TDA731X_MUTE);
		I2CWriteByte(TDA731X_SP_REAR_RIGHT | TDA731X_MUTE);
	} else {
		tda731xSetSpeakers();
	}
	I2CStop();

	return;
}

void tda731xSetLoudness(uint8_t val)
{
	_loudness = val;
	tda731xSetGain();

	return;
}
