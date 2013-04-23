#include "DirectXHeader.h"


// ��������� ��� ����-����� ��'���� ���, ���� ���� �����������
// ����� �� ��'���� ��� (�� �����, ���� � ������ ��� ������) ������ ���������� ����� ���� (���������)
// �������� �� ������ ���� ������ - ���� ������ ������� ���� ����������� �� ����������
#pragma once
class IRender
{
public:
	
	
	
	
	virtual bool Load(){return false;};
	virtual void LoadTexture(){};
	virtual void CreateVerticesArray( float distance_traveled){};
	virtual void Draw(){};
	virtual bool AlphaChannel() {return false;}
	long VerticesCount() {}
	LPDIRECT3DVERTEXBUFFER9 mapVertexBuffer() { }
	LPDIRECT3DTEXTURE9 Texture() { }
};

