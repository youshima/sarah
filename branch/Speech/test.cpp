#include "StdAfx.h"
#include "stdafx.h"
#include "SAPI.h"
#include <atlbase.h>
#include "sphelper.h"

#include "Sound.h"
#include <string>
#include <iostream>
using namespace std;

int main() {

	::CoInitialize(NULL);


	Sound * sound = new Sound();
	sound->setVoiceSpeed(1);
	sound->say("This is a test program");


	::CoUninitialize();
	return 0;
}