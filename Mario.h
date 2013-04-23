#pragma once
class Mario
{

	
public:
	
	float Vaccelerarion;
	static	const int GravityAcceleration = -3;
	float Speed;
	float left;
	float top;
	bool Jumping;
	unsigned long StartTime;
	Mario(void);
	void Rendered();
	void UpdatePosition();
	~Mario(void);
};

