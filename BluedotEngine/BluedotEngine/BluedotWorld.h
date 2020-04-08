#include "BluedotBody.h"

struct World //Realiza las iteraciones que sean necesarias en nuestro objeto.
{
	//Costructores
	World() : gravity(Vec2(0.0f, 9.81f)) {}
	World(Vec2 gravity) : gravity(gravity) {}

	// Establecer gravedad
	void setGravity(Vec2 v);

	// Body creation.
	void addBody(Body* b);

	// Simulation.
	void Step(float dt);

private:
	Vec2 gravity;
	std::vector< Body* > bodies;
};
