#pragma once

#include <d3d9.h>
#pragma warning( disable : 4996 ) // disable deprecated warning 
#include <strsafe.h>
#pragma warning( default : 4996 )
#include <windows.h>
#include <string>
#include <d3dx9.h>
#include <d3dx9tex.h>
#include "dinput.h"
#include "time.h"
#include "DXGI.h"
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

struct point
{
	int x;
	int y;
};

struct D3DVERTEX
{
   float x, y, z, rhw;
   DWORD color;
   FLOAT tu, tv; // змінні для правильного накладання текстур - магія кароче:)
};
