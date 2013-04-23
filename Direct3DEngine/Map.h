#include "DirectXHeader.h"

#include "IRender.h"
#pragma once
class Map : public IRender
{

protected :
	IDirect3DDevice9 *pDevice; // вказівник на відеокарту, потрібен для виділення буфера під текстури
	LPDIRECT3DTEXTURE9  texture; // вказівник на текстуру
	LPDIRECT3DVERTEXBUFFER9 MapVertexBuffer; //буфер у пам'яті відеокарти для виводу зображення
	D3DVERTEX MapVertices[10000]; // масив з точок, які формують трикутники
	long MapVerticesSize; // кількість точок у масиві
	
	int **_MapArray; // масив який тримає карту (її частину, залежно від типу наслідуючого класу - тобто або землю, або блоки або воду і тп...)
	int _Lenght; // довжина масиву
	int _Height; // висота масиву
	int _Level; // рівень гри, треба для завантаження правильного файлу карти !!!!
	int _BlockSize; // розмір одного блока карти
	

public:
	Map(int level, int block_size, IDirect3DDevice9 *device);
	~Map(void);

	
	////////////////////////////////////////////////////////////
	// Функція-магія - перевірка фізики і графітації
	// Імплементить її Остап і Віталік, тому якщо Вам треба більше параметрів чи ще щось - звертайтеся, всі методи щодо Маріо я дороблю
	////////////////////////////////////////////////////////////
	virtual point GetPossibleMoveLenght( int &distance_traveled_pixels,int poz_top, int hor_speed, int ver_speed, int MarioWidht, int MarioHeight ) {return point();};
	
	
	
	virtual bool Load(){return true;};
	virtual void LoadTexture(){};
	virtual void CreateVerticesArray( float distance_traveled){};
	virtual void Draw(){};
	virtual bool AlphaChannel() {return false;}

	// функція додає на карту два квадрати - чорний позаду - тирішки більший, слугує рамкою, потрібний спереду
	void AddBox( float x, float y,float widht , float height);
	
	
	long VerticesCount() { return MapVerticesSize/3; }
	LPDIRECT3DVERTEXBUFFER9 mapVertexBuffer() { return MapVertexBuffer;}
	LPDIRECT3DTEXTURE9 Texture() { return texture; }
};

