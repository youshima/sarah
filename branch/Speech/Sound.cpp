#include "StdAfx.h"
#include "Sound.h"


Sound::Sound(void)
{
	this->voice = Voice();
	this->ears = Ears();
}

void Sound::say(string message) {
	this->getVoice().speak(message);
}

void Sound::setVoiceSpeed(long speed) {
	this->getVoice().setRate(speed);
}


Sound::~Sound(void)
{
	this->voice.~Voice();
	this->ears.~Ears();
}
