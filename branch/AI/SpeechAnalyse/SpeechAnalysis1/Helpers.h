#pragma once

#pragma warning( disable : 4996 ) //enleve le message d'erreur de functions 'unsafe'

#include <string>
#include <vector>
#include <winsock2.h> //reseau
#include <windows.h>


namespace AI
{
/*#ifndef WORD
#define WORD unsigned short
#endif
#ifndef UINT
#define UINT unsigned int
#endif

#ifndef HRESULT
#define HRESULT WORD
#endif

#ifndef E_FAIL
#define E_FAIL 0x00
#endif

#ifndef S_OK
#define S_OK 0x01
#endif

#ifndef E_OUTOFMEMORY
#define E_OUTOFMEMORY 0x03
#endif*/

#ifndef E_FILENOTFOUND
#define E_FILENOTFOUND 0x6a
#endif

#define DESTROY(x) { (x).~x() ;}
}