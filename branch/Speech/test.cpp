#include "StdAfx.h"
#include "stdafx.h"
#include "SAPI.h"
#include <atlbase.h>
#include "sphelper.h"

#include "Sound.h"
#include <string>
#include <iostream>
using namespace std;


#include "ASR.h"

int main(int argc, wchar_t **argv) {
	/*
	::CoInitialize(NULL);

	string message;
	cout << "Speed=1, Volume=100" << endl;
	cout << "Enter a text : " << endl;
	getline(cin, message);

	Sound * sound = new Sound();
	sound->setVoiceSpeed(1);
	sound->setVoiceVolume(100);
	sound->say(message);

	::CoUninitialize();
	*/
	return wmain(2,argv);
}