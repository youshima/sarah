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

#endif