#pragma once

#pragma warning( disable : 4996 ) //enleve le message d'erreur de functions 'unsafe'

#include <winsock2.h> //reseau
#include <string>
#include <vector>

namespace AI
{

#define WORD unsigned short
#define UINT unsigned int
#define HRESULT WORD
//#define E_FAIL 0x00
//#define S_OK 0x01
#define E_FILENOTFOUND 0x6a
//#define E_OUTOFMEMORY 0x03

#define DESTROY(x) { (x).~x() ;}
}