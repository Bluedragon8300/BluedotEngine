#ifndef BODY_H
#define BODY_H

#include "BluedotMath.h"

struct Body
{
public:
	//Constructores
	Body() {}

	//Mostrar informacion del cuerpo
	void DisplayInfo();

	//Aplicacion de fuerzas
	void addForce(const Vec2& v);

	float mass;
	float InvMass = 1 / mass;
	Vec2 position;
	Vec2 velocity;
	Vec2 force = Vec2(0.0f, 0.0f); //La mejoraremos enventualmente.
};

#endif // ! BODY_H
