#pragma once
#ifndef VOICE_H
#define VOICE_H

#include "stdafx.h"
#include "SAPI.h"
#include <atlbase.h>
#include "sphelper.h"
#include <string>
using namespace std;

class Voice
{
private:
	CComPtr<ISpObjectToken> cpVoiceToken;
	CComPtr<ISpVoice> cpVoice;
public:
	Voice(string voiceName = "Microsoft Anna");
	void say(string message = "I have nothing to say"); // TODO Mood?
	void setVoiceSpeed(long speed = 1);
	void setVoiceVolume(int volume = 50);
	~Voice();
};

#endif