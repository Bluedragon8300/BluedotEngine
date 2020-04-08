#include <iostream>
#include <math.h>
#include <vector>


struct Vec2
{
	//Definir los constructores.
	Vec2() : x(0.0f), y(0.0f) {} //Constructor default
	Vec2(float x, float y) : x(x), y(y) {}

	//Estableciendo valores de nuestro vector
	void Set(float x_, float y_);

	//Propiedades.
	float Length();
	float LengthSquared();
	void Display();

	//Tomar los valores de X, Y.
	float getX();
	float getY();

	//Operadores con vectores (Suma de vectores, Prod.Punto, Prod.Cruz).
	void operator += (Vec2 v);
	void operator -= (Vec2 v);
	float Dot(Vec2 a, Vec2 b);
	float Cross(Vec2 a, Vec2 b);

private:
	float x, y;
};