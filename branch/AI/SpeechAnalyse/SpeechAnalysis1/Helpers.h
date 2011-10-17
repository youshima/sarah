#pragma once

#include <string>
#include <vector>

#define DWORD unsigned short
#define UINT unsigned int
#define HRESULT DWORD
#define E_FAIL 0x00
#define S_OK 0x01
#define E_FILENOTFOUND 0x02
#define E_OUTOFMEMORY 0x03

#define DESTROY_P(x) { if(x) x->~x() ;}
#define DESTROY(x) { if(x) x.~x() ;}