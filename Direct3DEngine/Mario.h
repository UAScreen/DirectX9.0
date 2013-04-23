#include "DirectXHeader.h"

#pragma once
#include <windows.h>
class Mario
{

	IDirect3DDevice9 *pDevice; // �������� �� �����
	LPDIRECT3DVERTEXBUFFER9 MarioVertexBuffer; // ����� ��� ��������� ���� ����� 
	LPDIRECT3DTEXTURE9     CurrentMarioTexture; // �������� ���� ��� ���� �������������� �� ������ ��������  Texture()
	LPDIRECT3DTEXTURE9     MarioTextures[10]; // ����� ����� ������� ����, ������ ���������������� ���� 2, ���� �� ���� �� 15

	D3DVERTEX MarioVertices[12]; // ����� �����
	long MarioVerticesSize; // ������� �����
	
public:
	float GravityAcceleration;
	float Vaccelerarion;
	float StartVelocity;
	
	float Speed;
	float left;
	float top;
	bool Jumping;
	unsigned long StartTime;
	Mario(IDirect3DDevice9 *device);
	bool LoadTexture();
	void UpdatePosition();
	void UpdateSpeed();
	void TurnLeft();
	void TurnRight();
	void Jump();
	void CreateVertices();
	void Draw();

	void StopMario();

	long VerticesCount() { return MarioVerticesSize/3; }
	LPDIRECT3DVERTEXBUFFER9 VertexBuffer() { return MarioVertexBuffer;}
	LPDIRECT3DTEXTURE9 Texture() { return CurrentMarioTexture; }
	~Mario(void);
};

