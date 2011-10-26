#pragma once
#ifndef SOUND_H
#define SOUND_H

#include "Voice.h"
#include "Ears.h"

class Sound : public Voice, public Ears
{
public:
	Sound();
	~Sound();
};

/*
	void say(string);
	//say() --> pour faire parler Sarah, prend des strings en entrée.

	void setVoiceSpeed(long);
	//Pour changer la vitesse de la voix, [-10;10]

	void setVoiceVolume(int);
	//Pour changer le volume de la voix, [0,100]
*/

#endif