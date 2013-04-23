#include "stdafx.h"
#include "Mario.h"


Mario::Mario(IDirect3DDevice9 *device)
{
	MarioVerticesSize = 12;
	pDevice = device;
	Jumping = false;
	Speed = 0.0;
	left = 350.0;
	top = 360.0;
	GravityAcceleration = -4;
	StartVelocity = 0;
	Speed = 0;
	StartTime = GetTickCount64();
}


Mario::~Mario(void)
{
}


void Mario::UpdatePosition()
{
	 
	


	
	// Остап - поковиряєш оце, забереш взагалі вще що після цього коменту - без нього маріо буде провалюватися вниз - що нам і треба для тесту графітації
	if(Speed<0)
	{
		if(top<300)
		{
			top -= Speed;
		}

	}
	else
		top -= Speed;

	if(top > 300) Jumping = false;;
	
}


void Mario::UpdateSpeed()
{
	long time = GetTickCount64(); // теперішній час, від нього віднімемо час у який почався стрибок


	Speed = StartVelocity + GravityAcceleration* (((double)time/250 - (double)StartTime/250) );
}

void Mario::StopMario() // занулює стартову швидкість маріо і час початку відліку прискорення 
{
	// Остап - будуть питання - пиши
	StartTime = GetTickCount64();
	StartVelocity = 0;
}

void Mario::Jump()
{
	StartVelocity = 10;
	StartTime = GetTickCount64();
	Jumping = true;
}

void Mario::CreateVertices()
{

	float x = left;
	float y = top - 50;
	float widht=50;
	float height = 50;

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
	
	//0xffd700;
	for(int i=0;i<12;i++)
	{
		MarioVertices[i] = vertices[i];
	}
	

	return;
}

void Mario::Draw()
{
	
		MarioVertexBuffer = NULL;
		void *pVertexBuffer = NULL;

		if(FAILED(pDevice->CreateVertexBuffer(MarioVerticesSize*sizeof(D3DVERTEX), D3DUSAGE_WRITEONLY, 
			NULL, D3DPOOL_MANAGED, &MarioVertexBuffer, NULL)))
		return;

		if(FAILED(MarioVertexBuffer->Lock(0, MarioVerticesSize*sizeof(D3DVERTEX), &pVertexBuffer, 0)))
		return;

		memcpy(pVertexBuffer, MarioVertices, MarioVerticesSize*sizeof(D3DVERTEX));
		
		MarioVertexBuffer->Unlock();
	
}

bool Mario::LoadTexture()
{
	if( FAILED( D3DXCreateTextureFromFileExA( pDevice, 
		"textures\\Mario_right.bmp",
		128,
		128,
		D3DX_DEFAULT,NULL,
		D3DFMT_UNKNOWN,   
               D3DPOOL_MANAGED,   //memory class
                             D3DX_DEFAULT,      //filter
                             D3DX_DEFAULT,      //mip filter
                             0xff00ff00,        //color key
                             NULL,              //source info
                             NULL,   
							 &MarioTextures[0]) ) )
    { 
		return false;
	}

	if( FAILED( D3DXCreateTextureFromFileExA( pDevice, 
		"textures\\Mario_left.bmp",
		128,
		128,
		D3DX_DEFAULT,NULL,
		D3DFMT_UNKNOWN,   
               D3DPOOL_MANAGED,   //memory class
                             D3DX_DEFAULT,      //filter
                             D3DX_DEFAULT,      //mip filter
                             0xff00ff00,        //color key
                             NULL,              //source info
                             NULL,   
							 &MarioTextures[1]) ) )
    { 
		return false;
	}

	CurrentMarioTexture = MarioTextures[0];
}

void Mario::TurnLeft()
{
	CurrentMarioTexture = MarioTextures[1];
}
void Mario::TurnRight()
{
	CurrentMarioTexture = MarioTextures[0];
}
	


