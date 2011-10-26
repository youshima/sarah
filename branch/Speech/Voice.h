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
	void speak(string message); // TODO Mood?
	void setRate(long speed);
	~Voice(void);
};

#endif