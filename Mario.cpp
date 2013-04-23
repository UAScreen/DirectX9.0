#include "Mario.h"


Mario::Mario(void)
{
	Jumping = false;
	Speed = 0.0;
	left = 350.0;
	top = 360.0;
	
}


Mario::~Mario(void)
{
}

void Mario::Rendered()
{

}

void Mario::UpdatePosition()
{
	long time = GetTickCount64();

	Speed = Speed + (float)GravityAcceleration* (( time - StartTime)/1000);

	top -= Speed;
	
}

