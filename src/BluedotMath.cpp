#include "BluedotMath.h"

void Vec2::Set(float x_, float y_)
{
	x = x_;
	y = y_;
	// Setting the x and y values
}

float Vec2::Length()
{
	return sqrt(x * x + y * y);
	// Returning x and y values
}

float Vec2::LengthSquared()
{
	return x * x + y * y;
	// Returning x and y values without the square root.
}

void Vec2::Display()
{
	std::cout << "El vector es: (" << x << ", " << y << ")" << std::endl;
	// Checking if everything works "for now".
}


//Definir operaciones con vectores.


void Vec2::operator+=(const Vec2& v)
{
	x += v.x;
	y += v.y;
}

void Vec2::operator-=(const Vec2& v)
{
	x -= v.x;
	y -= v.y;
}


float Vec2::Dot(const Vec2& a, const Vec2& b)
{
	return a.x * b.x + a.y * b.y;
}

float Vec2::Cross(const Vec2& a, const Vec2& b)
{
	return a.x * b.y - a.y * b.x;
}

