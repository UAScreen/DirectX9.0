#include "DirectXHeader.h"


#pragma once

#include "Map_Ground.h"

#include "Mario.h"

#include "Map.h"


 class D3DObject
{
	HWND     hWnd; // ���� � ����� ���� �������� DirectX
	HINSTANCE g_hinst;  // �� ����� ��㳿 :)
	IDirect3D9     *pD3D; // Used to create the D3DDevice
	IDirect3DDevice9 *pDevice; // �������� �� ������ ��������� DIrectX
	IDirect3DSurface9 *BackBuffer; // �������� �� ����� ����� ����������
	IDirect3DSurface9 *CurrentMainSurface;
	
public:

	

	Map_Ground *map_Ground;
	Mario *mario;


	bool RenewSurface;

	float DistanceTraveled;

	WNDCLASSEX wc;

	D3DObject(void);
	~D3DObject(void);
	bool InitD3D();	
	void CleanupD3D();
	VOID Render();
	void ProcessKeyPressed();
	char * Draw();
	void CheckPosition();
	bool  SetHistance( HWND window) { if (window == NULL) return false; hWnd = window; return true;};
};
extern D3DObject g_D3D;


