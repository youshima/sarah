// Speech.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SAPI.h"
#include <atlbase.h>
#include "sphelper.h"

int _tmain(int argc, _TCHAR* argv[])
{
	HRESULT                        hr = S_OK;
	CComPtr<ISpObjectToken>        cpVoiceToken;
	CComPtr<ISpVoice>              cpVoice;

SOToken: ISpeechObjectToken;
SOTokens: ISpeechObjectTokens;

	::CoInitialize(NULL);


	hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&cpVoice);
	if( SUCCEEDED( hr ) )
	{
		hr = SpFindBestToken(SPCAT_VOICES, L"Name=ScanSoft Virginie_Dri40_16kHz", L"", &cpVoiceToken);
		if( !SUCCEEDED(hr)) return 1; // Voix pas installée
		cpVoice->SetVoice(cpVoiceToken);
		cpVoice->SetRate(0.2);
		hr = cpVoice->Speak(L"Bonjour, je suis Sarah.\
							 Je suis une intelligence artificielle destinée à vous aider.\
							 Je peux vous assister dans l'utilisation de votre ordinateur.\
							 Je peux répondre à vos questions.\
							 Je peux effectuer des calculs pour vous.", 0, NULL);

		//cpVoice->Release(); <= Marche pas ? Wtf ?
		cpVoice = NULL;
	}

	::CoUninitialize();
	return 0;
}

