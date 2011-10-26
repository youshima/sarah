#pragma once
#ifndef SOUND_H
#define SOUND_H


#include "Voice.h"
#include "Ears.h"

class Sound
{
private:
	Voice voice;
	Ears ears;
public:
	Sound(void);
	~Sound(void);

	Voice getVoice() {
		return voice;
	}

	inline Ears getEars() {
		return ears;
	}
};

#endif