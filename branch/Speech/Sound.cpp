#include "StdAfx.h"
#include "Sound.h"


Sound::Sound(void)
{
	this->voice = Voice();
	this->ears = Ears();
}


Sound::~Sound(void)
{
	this->voice.~Voice();
	this->ears.~Ears();
}
