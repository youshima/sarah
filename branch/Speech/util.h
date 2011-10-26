#pragma once
#ifndef UTIL_H
#define UTIL_H

#include "SAPI.h"
#include "stdafx.h"
#include <string>
using namespace std;

/*
Fonction utilitaires
*/

std::wstring string_to_wstring(const std::string& s);
	// Convert a string to a wstring

#endif