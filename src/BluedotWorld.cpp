#include "BluedotWorld.h"

void World::setGravity(const Vec2& v)
{
	gravity = v;
}

void World::addBody(Body* b)
{
	bodies.push_back(b); //Va agregando elementos al vector bodies.
}

void World::Step(float dt)
{

	if ((int)bodies.size() == 0) { std::cout << "NO BODIES FOUND IN THIS WORLD." << std::endl; }

	//integra velocidades.
	for (int i = 0; i < (int)bodies.size(); i++) //iterando sobre el vector "bodies".
	{
		bodies[i]->velocity += dt * (gravity + bodies[i]->InvMass * bodies[i]->force);
	}
	//integra posicion.
	for (int i = 0; i < (int)bodies.size(); i++) //iterando sobre el vector "bodies".
	{
		bodies[i]->position += dt * bodies[i]->velocity;
		bodies[i]->force = Vec2(0.0f, 0.0f);

	}
}