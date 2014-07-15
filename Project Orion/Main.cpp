#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Orion.hpp"

using namespace Orion::Resources;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Project Orion");
	sf::Vector2i resolution(1280, 720);

	try
	{
		ResourceManager::getInstance().Textures.load("background", "background1.jpg");
		ResourceManager::getInstance().Textures.load("planet", "planet.png");
	}
	catch (std::runtime_error& e)
	{
		printf("Exception: %s\n", e.what());
		return 1;
	}


	sf::Sprite background;
	background.setTexture(ResourceManager::getInstance().Textures.get("background"));
	background.setOrigin(background.getTextureRect().width / 2, background.getTextureRect().height / 2);
	background.setPosition(resolution.x / 2, resolution.y / 2);

	sf::Sprite planet;
	planet.setTexture(ResourceManager::getInstance().Textures.get("planet"));
	planet.setOrigin(planet.getTextureRect().width / 2, planet.getTextureRect().height / 2);
	planet.setPosition(1000, 550);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(background);
		window.draw(planet);
		window.display();
	}

	return 0;
}