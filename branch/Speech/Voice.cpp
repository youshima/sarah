#include "StdAfx.h"
#include "Voice.h"
#include "util.h"


Voice::Voice(string voiceName)
{
	HRESULT hr = S_OK;

	::CoInitialize(NULL);

	hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&(this->cpVoice));
	if (!SUCCEEDED(hr)) {
		//Exception : on a pas réussi à... J'en sais rien. Mais en tout cas ça a pas marché.
	} else {
		wstring stmp = string_to_wstring("Name=" + voiceName);
		hr = SpFindBestToken(SPCAT_VOICES, stmp.c_str(), L"", &(this->cpVoiceToken));
		if (!SUCCEEDED(hr)) {
			//Exception : on a pas trouvé de voix
		}
	}
}

void Voice::speak(string message)
{
	HRESULT hr = S_OK;
	wstring stmp = string_to_wstring(message);
	hr = this->cpVoice->Speak((stmp.c_str()), 0, NULL);
	if (!SUCCEEDED(hr)) {
		//Exception : on a pas pu parler (mal de gorge ?)
	}
}


Voice::~Voice(void)
{
	::CoUninitialize();
}
