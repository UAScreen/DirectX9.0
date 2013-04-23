#include "DirectXHeader.h"


// Інтерфейс для будь-якого об'єкта гри, який буде рендеритися
// тобто усі об'єкти гри (всі блоки, моби і взагалі все видиме) повинні наслідувати даний клас (інтерфейс)
// прохання не цапати його руками - зміни будемо вносити після обговорення їх доцільності
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

