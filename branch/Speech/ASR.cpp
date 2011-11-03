#include <windows.h>
#include <sphelper.h>
#include <atlbase.h>
#include "stdafx.h"

#pragma warning(disable:4995)
#include<iostream>
using namespace std;

bool done = false;

BOOL WINAPI HandlerRoutine(DWORD dwCtrlType)
{
	wcout << "exiting..." << endl;
	done = true;

	return true;
}

int wmain(int argc, wchar_t **argv)
{
	LPWSTR pszText;
	HANDLE hEvent;
	HRESULT hr;
	CSpEvent evt;
	SPPHRASE *pParts;
	ISpPhrase *pPhrase;
	ULONGLONG ullEvents;
	CComPtr<ISpRecognizer> cpEngine;
	CComPtr<ISpRecoContext> cpRecoCtx;
	CComPtr<ISpRecoGrammar> cpGram;

	if (argc != 2)
	{wcout << "enter the name of a grammar file to test." << endl;}

	else
	{
		SetConsoleCtrlHandler (HandlerRoutine, TRUE);

		wcout << "Speak phrases defined in the grammar being tested" << endl;
		wcout << "ctrl+c to quit" << endl;

		CoInitialize(0);

		hr = cpEngine.CoCreateInstance(CLSID_SpSharedRecognizer);
		hr = cpEngine->CreateRecoContext(&cpRecoCtx);

		hr = cpRecoCtx->SetNotifyWin32Event();
		hEvent = cpRecoCtx->GetNotifyEventHandle();
		ullEvents=SPFEI(SPEI_RECOGNITION) | SPFEI(SPEI_FALSE_RECOGNITION);
		hr = cpRecoCtx->SetInterest(ullEvents,ullEvents);

		hr = cpRecoCtx->CreateGrammar(1, &cpGram);
		hr = cpGram ->LoadCmdFromFile(argv[1], SPLO_STATIC); //charger grammaire depuis un fichier, à changer.

		hr = cpGram->SetRuleState(0, 0, SPRS_ACTIVE);

		while (!done)
		{
			WaitForSingleObject(hEvent, 10000);

			while (evt.GetFrom(cpRecoCtx) == S_OK)
			{
				if (evt.eEventId == SPEI_FALSE_RECOGNITION)
					wcout << "No recognition" << endl;
				else
				{
					pPhrase = evt.RecoResult();
					hr = pPhrase->GetPhrase(&pParts);

					hr = pPhrase->GetText(SP_GETWHOLEPHRASE, SP_GETWHOLEPHRASE, FALSE, &pszText, 0);

					wcout << pszText << " (" << pParts->Rule.Confidence << ") " << endl;

					CoTaskMemFree(pParts);
					CoTaskMemFree(pszText);
				}
			}
		}

		cpGram.Release();
		cpRecoCtx.Release();
		cpEngine.Release();

		CoUninitialize();
	}

}