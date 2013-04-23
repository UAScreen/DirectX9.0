#include "DirectXHeader.h"

#include "IRender.h"
#pragma once
class Map : public IRender
{

protected :
	IDirect3DDevice9 *pDevice; // �������� �� ���������, ������� ��� �������� ������ �� ��������
	LPDIRECT3DTEXTURE9  texture; // �������� �� ��������
	LPDIRECT3DVERTEXBUFFER9 MapVertexBuffer; //����� � ���'�� ��������� ��� ������ ����������
	D3DVERTEX MapVertices[10000]; // ����� � �����, �� �������� ����������
	long MapVerticesSize; // ������� ����� � �����
	
	int **_MapArray; // ����� ���� ����� ����� (�� �������, ������� �� ���� ����������� ����� - ����� ��� �����, ��� ����� ��� ���� � ��...)
	int _Lenght; // ������� ������
	int _Height; // ������ ������
	int _Level; // ����� ���, ����� ��� ������������ ����������� ����� ����� !!!!
	int _BlockSize; // ����� ������ ����� �����
	

public:
	Map(int level, int block_size, IDirect3DDevice9 *device);
	~Map(void);

	
	////////////////////////////////////////////////////////////
	// �������-���� - �������� ������ � ����������
	// ������������ �� ����� � ³����, ���� ���� ��� ����� ����� ��������� �� �� ���� - �����������, �� ������ ���� ���� � �������
	////////////////////////////////////////////////////////////
	virtual point GetPossibleMoveLenght( int &distance_traveled_pixels,int poz_top, int hor_speed, int ver_speed, int MarioWidht, int MarioHeight ) {return point();};
	
	
	
	virtual bool Load(){return true;};
	virtual void LoadTexture(){};
	virtual void CreateVerticesArray( float distance_traveled){};
	virtual void Draw(){};
	virtual bool AlphaChannel() {return false;}

	// ������� ���� �� ����� ��� �������� - ������ ������ - ������ ������, ����� ������, �������� �������
	void AddBox( float x, float y,float widht , float height);
	
	
	long VerticesCount() { return MapVerticesSize/3; }
	LPDIRECT3DVERTEXBUFFER9 mapVertexBuffer() { return MapVertexBuffer;}
	LPDIRECT3DTEXTURE9 Texture() { return texture; }
};

