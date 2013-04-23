

#include "DirectXHeader.h"
#include "Map.h"

#pragma once
using namespace System;


class Map_Ground :  public Map
{

public:
	Map_Ground(int level, int block_size, IDirect3DDevice9 *device) : Map(level,  block_size,  device){};
	bool LoadTexture( wchar_t * path );
	bool Load();
	void CreateVerticesArray(float DistanceTraveled);
	void Draw();
	bool AlphaChannel() {return true;}
	point GetPossibleMoveLenght(int &distance_traveled_pixels,int poz_height_pixels, int hor_speed, int ver_speed, int MaioWidht, int MarioHeight);

};

