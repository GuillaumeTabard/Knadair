#include <SFML/Graphics.hpp>
//pour le compiler:
//g++ -c main.cpp
//g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system



int main()
{
	sf::RectangleShape texte(sf::Vector2f(600, 600));
	texte.setFillColor(sf::Color::Red);
    sf::RenderWindow window(sf::VideoMode(600, 600), "titre de la fenetre");
    sf::RectangleShape rectangle(sf::Vector2f(200, 100));
	rectangle.setFillColor(sf::Color::Yellow);
	rectangle.setPosition(10, 50);
	int a =0;
	sf::RectangleShape rectangle2(sf::Vector2f(200, 100));
	rectangle2.setFillColor(sf::Color::Green);
	rectangle2.setPosition(600, 500);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
			
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				rectangle.move(-5,0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				rectangle.move(+5,0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				rectangle.move(0,5);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				rectangle.move(0,-5);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				window.close();
			}
			
        }
        sf::Vector2f position = rectangle2.getPosition();
        if(position.x==-200)
			rectangle2.setPosition(600, 500);
        rectangle2.move(-1,0);
		sf::FloatRect rectanglecol = rectangle.getGlobalBounds();
		sf::FloatRect rectangle2col = rectangle2.getGlobalBounds();
		if (rectangle2col.intersects(rectanglecol))
		{
			a=1;
		}
		
        window.clear();
        
        window.draw(rectangle);
        window.draw(rectangle2);
        if (a==1)
			 window.draw(texte);
        window.display();
    }

    return 0;
}
