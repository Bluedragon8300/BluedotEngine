#include <SFML/Graphics.hpp> //Incluimos la libreria de SFML en nuestro "Moving Box".
#include "BluedotWorld.h" //Incluimos nuestra libreria de BluedotEngine > BluedotWorld.h para generar la fisica implementada.

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Sona having issues understanding what are you doing..."); //Creamos una ventana con dimensiones 800x600.
	window.setFramerateLimit(60);

	sf::Event event; //Creamos un objeto tipo evento. 
	sf::Clock clock; //Creamos Clock para llevar acabo el conteo de los frames.

	//Carga de las imagenes "Sprites"
	sf::Texture boxTex1;
	sf::Sprite boxSprite1;

	//Ingresamos nuestro sprite mediante LoadFromFile(), debemos tener un orden en nuestras carpetas.
	if (!boxTex1.loadFromFile("Assets/Sprites/zeunblx1vil11.png"))
	{
		//En caso de que el mismo no sea encontrado, se le avisara al usuario.
		std::cout << "Couldn't load texture. . ." << std::endl;
		system("pause");
	}

	//Configuracion de World.
	World w1;
	//Establecemos la gravedad.
	w1.setGravity(Vec2(0.0f, 900.0f));

	float Mass;
	float Pos;
	float Vel;

	istream& getMass();
	istream& getPos();
	istream& getVel();

	//Establecemos nuestro valores iniciales para Masa, Posicion y velocidad.
	Body b1;
	b1.setMass(1.0f);
	b1.setPos(Vec2(400.0f, 0.0f));
	b1.setVel(Vec2(0.0f, 0.0f));

	w1.addBody(&b1);


	//Configuracion de sprites.

	boxSprite1.setTexture(boxTex1);
	boxSprite1.setScale(sf::Vector2f(0.35f, 0.35f));

	//Establecemos nuestro punto origen dentro al sprite.
	sf::Rect<float> size = boxSprite1.getGlobalBounds();
	boxSprite1.setOrigin(sf::Vector2f(size.width / 2, size.height / 2));

	//Inicializamos colocando nuestra cajita en la parte superior de la pantalla dependiendo de nuestro valores dados
	//a nuestro body position.
	boxSprite1.setPosition(sf::Vector2f(b1.getPos().getX(), b1.getPos().getY()));


	//Lo que ocurrira en pantalla se vera:
	while (window.isOpen()) //El ciclo de mientras... las pantalla este abierta.
	{
		while (window.pollEvent(event)) //Lee algun tipo de entrada como presion de teclado, uso de Joystick o clickeo del raton.
		{
			if (event.type == sf::Event::Closed) //Cerrar la ventana por medio de "x" a la esquina de nuestra pantalla.
			{	//Continuando a nuestra condicion.
				window.close(); //El cierre de la ventana.
			}
		}

		//Calculamos el tiempo tomado para completar un frame de nuestro cuerpo.
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		//Tiempo calculado que le toma a Step() en realizar toda la operacion.
		w1.Step(dt);

		boxSprite1.setPosition(sf::Vector2f(b1.getPos().getX(), b1.getPos().getY()));

		//Vistaso de la pantalla.
		window.clear(sf::Color::Green);
		//Dibujamos el sprite.
		window.draw(boxSprite1);
		//Mostramos nuestra pantalla.
		window.display();
	}

	return 0;
}