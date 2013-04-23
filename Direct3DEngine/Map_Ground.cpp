#include "stdafx.h"
#include "Map_Ground.h"

bool Map_Ground::Load()
{
	String ^path = "map" + _Level + ".txt";
	System::IO::StreamReader ^reader = gcnew System::IO::StreamReader(path);

	if(reader != nullptr)
	{

		String ^ line = reader->ReadLine();
	
		_Height =Int32::Parse(line); 
		
		line = reader->ReadLine();
		_Lenght = Int32::Parse(line); 
	
		_MapArray = new int *[_Height];
	
		for(int i=0;i<_Height;i++)
		{
			line = reader->ReadLine();
			_MapArray[i] = new int [_Lenght];

			for(int j=0;j<_Lenght;j++)
			{
				if(line[j]=='1') _MapArray[i][j] = 1;
				else
					_MapArray[i][j] = 0;
			}
		}

			
			return true; // звітуємо про успішне завантаження карти
	}
	return false; // звітуємо про помилку завантаження карти
}

point Map_Ground::GetPossibleMoveLenght( int &distance_traveled_pixels,int poz_top, int hor_speed, int ver_speed, int MarioWidht, int MarioHeight)
{
	point result;
	int block_number = (distance_traveled_pixels + MarioWidht + hor_speed)/_BlockSize;

	int row_number = (poz_top+ver_speed)/_BlockSize;


	
	if(hor_speed>=0)
	{
		int block_number = (distance_traveled_pixels + MarioWidht + hor_speed)/_BlockSize;
		int row_number = (poz_top+ver_speed)/_BlockSize;
		if(_MapArray[row_number][block_number] == 0) 
		{
			result.x = hor_speed;
			result.y = ver_speed;
			return result ;
		}
		else
		{
			result.x = (_BlockSize*block_number - distance_traveled_pixels + MarioWidht );
			result.y = ver_speed;
			return result;
		}
	}
	else
	{
		if(ver_speed>=0)
		{

		}
		else
		{

		}
	}
		

	result.x = hor_speed;
	result.y = ver_speed;
	return result ;
	
}

bool Map_Ground::LoadTexture(wchar_t * path)
{
	void * textureptr = (void *)texture;
	if( FAILED( D3DXCreateTextureFromFile( pDevice, path, (LPDIRECT3DTEXTURE9 *) &textureptr) ) )
    { 
		return false;
	}
	texture = (LPDIRECT3DTEXTURE9 ) textureptr;
	return true;
}

void Map_Ground::CreateVerticesArray(float DistanceTraveled)
{
	MapVerticesSize = 0;
	for(int i=0;i<_Height;i++)
	{
		for(int j=0;j<_Lenght;j++)
		{
			if(_MapArray[i][j]==1)
			if((j*_BlockSize+ 400-DistanceTraveled )>0)
					if((j*_BlockSize-DistanceTraveled )<800)
			{
					AddBox(j*_BlockSize-DistanceTraveled ,(i*50)+300,50, 50);
						
			}
					
		}
	}
}

void Map_Ground::Draw()
{

	
		MapVertexBuffer = NULL;
		void *pVertexBuffer = NULL;

		if(FAILED(pDevice->CreateVertexBuffer(MapVerticesSize*sizeof(D3DVERTEX), D3DUSAGE_WRITEONLY, 
			NULL, D3DPOOL_MANAGED, &MapVertexBuffer, NULL)))
		return;

		if(FAILED(MapVertexBuffer->Lock(0, MapVerticesSize*sizeof(D3DVERTEX), &pVertexBuffer, 0)))
		return;

		memcpy(pVertexBuffer, MapVertices, MapVerticesSize*sizeof(D3DVERTEX));
			MapVertexBuffer->Unlock();


}

