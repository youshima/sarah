#pragma once
#ifndef VOICE_H
#define VOICE_H

#include "stdafx.h"
#include "SAPI.h"
#include <atlbase.h>
#include "sphelper.h"
#include <string>
using namespace std;

/*
	Classe gérant la synthèse vocale (TTS).
	Speech synthesis class.
*/
class Voice
{
private:
	CComPtr<ISpObjectToken> cpVoiceToken;
	CComPtr<ISpVoice> cpVoice;
public:
	Voice(string voiceName = "Microsoft Anna");
	//constructeur

	void say(string message = "I have nothing to say"); // TODO Mood?
	//say() --> pour faire parler Sarah, prend des strings en entrée.

	void setVoiceSpeed(long speed = 1);
	//Pour changer la vitesse de la voix, [-10;10]

	void setVoiceVolume(int volume = 50);
	//Pour changer le volume de la voix, [0,100]

	~Voice();
};

#endif