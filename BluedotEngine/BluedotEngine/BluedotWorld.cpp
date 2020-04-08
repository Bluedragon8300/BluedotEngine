#include "BluedotWorld.h"

void World::setGravity(Vec2 v)
{
	gravity = v;
}

void World::addBody(Body* b)
{
	bodies.push_back(b); //Va agregando elementos al vector bodies.
}

void World::Step(float dt)
{

	if ((int)bodies.size() == 0) {std::cout << "NO BODIES FOUND IN THIS WORLD." << std::endl; }
	
		float ax = gravity.getX();
		float ay = gravity.getY();

	for (int i = 0; i < (int)bodies.size(); i++) //iterando sobre el vector "bodies".
	{ 
		float px = bodies[i]->getPos().getX(); //Posicion en x del cuerpo en bodies[i].
		float py = bodies[i]->getPos().getY(); //Posicion en y del cuerpo en bodies[i].

		float vx = bodies[i]->getVel().getX(); //Velocidad en x del cuerpo en bodies[i].
		float vy = bodies[i]->getVel().getY(); //Velocidad en y del cuerpo en bodies[i].

		bodies[i]->setPos(Vec2(px + vx * dt, py + vy * dt));
		bodies[i]->setVel(Vec2(ax * dt + vx, ay * dt + vy));
	}
}
