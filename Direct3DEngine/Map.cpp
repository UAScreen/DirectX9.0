#include "stdafx.h"
#include "Map.h"


Map::Map(int level, int block_size, IDirect3DDevice9 *device)
{
	pDevice = device;
	_Level = level;
	_BlockSize = block_size;
	MapVerticesSize = 0;
}


Map::~Map(void)
{
	for(int i=0;i<_Height;i++)
		delete _MapArray[i];

	delete _MapArray;
	_MapArray = NULL;
}

void Map::AddBox( float x=0, float y=0,float widht=50 , float height = 50)
{
	float border = 2;
	

	D3DVERTEX  vertices[12];

	vertices[0].x = x+widht - border; 
	vertices[0].y =y - border; 
	vertices[0].z = 0; 
	vertices[0].rhw = 1.0f; 
	vertices[0].color = 0x000000;
	vertices[0].tu = 0.0;
	vertices[0].tv = 0.0;

	vertices[1].x = x+ 2*widht + border; 
	vertices[1].y =y - border; 
	vertices[1].z = 0; 
	vertices[1].rhw = 1.0f; 
	vertices[1].color = 0x000000;
	vertices[1].tu = 1;
	vertices[1].tv = 0.0;

 

	vertices[2].x = x+ widht - border; 
	vertices[2].y =y+ height + border; 
	vertices[2].z = 0; 
	vertices[2].rhw = 1.0f;
	vertices[2].color = 0x000000;
	vertices[2].tu = 0.0;
	vertices[2].tv = 1.0;

	//D3DVERTEX  vertices2[3];

	vertices[3].x =x+ 2*widht + border; 
	vertices[3].y = y -  border; 
	vertices[3].z = 0; 
	vertices[3].rhw = 1.0f; 
	vertices[3].color = 0x000000;

 

	vertices[4].x =x+ 2*widht +border; 
	vertices[4].y =y+ height + border; 
	vertices[4].z = 0; 
	vertices[4].rhw = 1.0f; 
	vertices[4].color = 0x000000;

 

	vertices[5].x =x+ widht - border; 
	vertices[5].y =y+ height + border; 
	vertices[5].z = 0; 
	vertices[5].rhw = 1.0f;
	vertices[5].color = 0x000000;

	

	vertices[6].x = x+widht; 
	vertices[6].y =y; 
	vertices[6].z = 0; 
	vertices[6].rhw = 1.0f; 
	vertices[6].color = 0xffffff;
	vertices[6].tu = 0.0;
	vertices[6].tv = 0.0;
 

	vertices[7].x = x+ 2*widht; 
	vertices[7].y =y; 
	vertices[7].z = 0; 
	vertices[7].rhw = 1.0f; 
	vertices[7].color = 0xffffff;
	vertices[7].tu = 1.0;
	vertices[7].tv = 0.0;
 

	vertices[8].x = x+ widht; 
	vertices[8].y =y+ height; 
	vertices[8].z = 0; 
	vertices[8].rhw = 1.0f;
	vertices[8].color = 0xffffff;
	vertices[8].tu = 0.0;
	vertices[8].tv = 1.0;
	//D3DVERTEX  vertices2[3];

	vertices[9].x =x+ 2*widht; 
	vertices[9].y = y; 
	vertices[9].z = 0; 
	vertices[9].rhw = 1.0f; 
	vertices[9].color = 0xffffff;
	vertices[9].tu = 1.0;
	vertices[9].tv = 0.0;
 

	vertices[10].x =x+ 2*widht; 
	vertices[10].y =y+height; 
	vertices[10].z = 0; 
	vertices[10].rhw = 1.0f; 
	vertices[10].color = 0xffffff;
	vertices[10].tu = 1.0;
	vertices[10].tv = 1.0;
 

	vertices[11].x =x+ widht; 
	vertices[11].y =y+height; 
	vertices[11].z = 0; 
	vertices[11].rhw = 1.0f;
	vertices[11].color = 0xffffff;
	vertices[11].tu = 0.0;
	vertices[11].tv = 1.0;
	

	for(int i=0;i<12;i++)
	{
		MapVertices[i+MapVerticesSize] = vertices[i];
	}
	MapVerticesSize+=12;

	return;
}
