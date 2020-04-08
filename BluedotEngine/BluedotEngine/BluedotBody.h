#include "BluedotMath.h"

struct Body
{
public:
	//Constructores
	Body() : mass(1.0f) {}
	Body(float mass): mass(mass) {}

	//Establecer el valor de la masa
	void setMass(float m);

	//Establecer posicion y velocidad.
	void setVel(Vec2 v);
	void setPos(Vec2 v);

	//Obtener los valores de masa, posicion y velocidad.
	float getMass();
	float getInvMass();
	Vec2 getVel();
	Vec2 getPos();

	//Mostrar informacion del cuerpo
	void DisplayInfo();

	//Aplicacion de fuerzas
	void addForce(Vec2 v);

private:
	float mass;
	float InvMass = 1 / mass;
	Vec2 position;
	Vec2 velocity;
	Vec2 force;

};