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

	inline Voice getVoice() {
		return voice;
	}

	inline Ears getEars() {
		return ears;
	}

	void say(string message = "I have nothing to say");

	void setVoiceSpeed(long speed = 1);
		// -10 <= speed <= 10
};

#endif