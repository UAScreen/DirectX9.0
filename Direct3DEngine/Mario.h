#include "DirectXHeader.h"

#pragma once
#include <windows.h>
class Mario
{

	IDirect3DDevice9 *pDevice; // вказівник на відяху
	LPDIRECT3DVERTEXBUFFER9 MarioVertexBuffer; // буфер для заливання туди точок 
	LPDIRECT3DTEXTURE9     CurrentMarioTexture; // такстура маріо яка буде експортуватися на рендер функцією  Texture()
	LPDIRECT3DTEXTURE9     MarioTextures[10]; // масив різних текстур маріо, покищо використовуються лише 2, потім їх буде до 15

	D3DVERTEX MarioVertices[12]; // масив точок
	long MarioVerticesSize; // кількість точок
	
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

