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
	Sound * sound = new Sound();
	sound->getVoice().speak("This is a test program");
	return 0;
}