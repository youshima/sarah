#include "StdAfx.h"
#include "Voice.h"
#include "util.h"


Voice::Voice(string voiceName)
{
	HRESULT hr = S_OK;

	hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&(this->cpVoice));
	if (!SUCCEEDED(hr)) {
		//Exception : on a pas r�ussi �... J'en sais rien. Mais en tout cas �a a pas march�.
	} else {
		wstring stmp = string_to_wstring("Name=" + voiceName);
		hr = SpFindBestToken(SPCAT_VOICES, stmp.c_str(), L"", &(this->cpVoiceToken));
		if (!SUCCEEDED(hr)) {
			//Exception : on a pas trouv� de voix
		}
	}
}

void Voice::say(string message)
{
	HRESULT hr = S_OK;
	wstring stmp = string_to_wstring(message);
	hr = this->cpVoice->Speak((stmp.c_str()), 0, NULL);
	if (!SUCCEEDED(hr)) {
		//Exception : on a pas pu parler (mal de gorge ?)
	}
}

void Voice::setVoiceSpeed(long speed) {
	this->cpVoice->SetRate(speed);
}

void Voice::setVoiceVolume(int volume) {
	USHORT vol;
	if (volume<0) {
		vol = 0;
	} else if (volume>100) {
		vol = 100;
	} else {
		vol = volume;
	}
	this->cpVoice->SetVolume(vol);
}


Voice::~Voice()
{
	this->cpVoice = NULL;
	this->cpVoiceToken = NULL;
}
