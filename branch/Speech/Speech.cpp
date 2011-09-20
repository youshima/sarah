// Speech.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SAPI.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ISpVoice * pVoice = NULL;

	 SOToken: ISpeechObjectToken;
	 SOTokens: ISpeechObjectTokens;

    ::CoInitialize(NULL);
	

    HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
    if( SUCCEEDED( hr ) )
    {
		 pVoice->SetRate(0.2);
		 hr = pVoice->Speak(L"Bonjour, je suis Sarah.\
							 Je suis une intelligence artificielle destinée à vous aider.\
							 Je peux vous assister dans l'utilisation de votre ordinateur.\
							 Je peux répondre à vos questions.\
							 Je peux effectuer des calculs pour vous.", 0, NULL);
		
        pVoice->Release();
        pVoice = NULL;
    }

    ::CoUninitialize();
	return 0;
}

