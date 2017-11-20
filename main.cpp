#include <SFML/Graphics.hpp>
//pour le compiler:
//g++ -c main.cpp
//g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

float moveKnadair (sf::Sprite sprite);

int main()
{
	sf::RenderWindow window(sf::VideoMode(1369, 744), "titre de la fenetre");
	
	sf::RectangleShape texte(sf::Vector2f(1369, 744));
	texte.setFillColor(sf::Color::Red);

	sf::Font font;
	font.loadFromFile("police/arial.ttf");
	sf::Text text2;
	text2.setString("PERDU");
	text2.setCharacterSize(24);
	text2.setColor(sf::Color::Blue);
	text2.setFont(font);
	text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text2.setPosition(250, 300);

	sf::RectangleShape rectangleBis(sf::Vector2f(200, 100));
	rectangleBis.setFillColor(sf::Color::Magenta);
	rectangleBis.setPosition(200, 250);
	
	sf::RectangleShape rectangle2(sf::Vector2f(200, 100));
	rectangle2.setFillColor(sf::Color::Green);
	rectangle2.setPosition(600, 500);

	int a =0;
	int b=0;
	int vitesse=10; //la vitesse de l'avion (du défilement des décords)
	int demarrage=1; //indique si la cinématique de début de jeu est fini ou pas
	int down=0;	//indique si la touche down est enfoncé (1) ou pas (0)
	int up=0; 	//indique si la touche up est enfoncé (1) ou pas (0)
	
	//knadair
	sf::Sprite spriteKnadair;
	sf::Texture textKnadair;
	if(!textKnadair.loadFromFile("img/Knadaire.png",sf::IntRect(0,0,152,52)))
		printf("\n\nerreur lors du chargement de l'image\n\n");
	spriteKnadair.setTexture(textKnadair);
	spriteKnadair.setPosition(200, 650);

	
	//fond 1
	sf::Sprite spriteFond1;
	sf::Texture textFond1;
	if(!textFond1.loadFromFile("img/start.png",sf::IntRect(0,0,1369,744)))
		printf("\n\nerreur lors du chargement de l'image\n\n");
	spriteFond1.setTexture(textFond1);

	//fond 2
	sf::Sprite spriteFond2;
	sf::Texture textFond2;
	if(!textFond2.loadFromFile("img/Ttm.png",sf::IntRect(0,0,1369,744)))
		printf("\n\nerreur lors du chargement de l'image\n\n");
	spriteFond2.setTexture(textFond2);
	spriteFond2.setPosition(1368, 0);

	//fond 3
	sf::Sprite spriteFond3;
	sf::Texture textFond3;
	if(!textFond3.loadFromFile("img/eau.png",sf::IntRect(0,0,1369,744)))
		printf("\n\nerreur lors du chargement de l'image\n\n");
	spriteFond3.setTexture(textFond3);
	spriteFond3.setPosition(2736, 0);

	//fond 4
	sf::Sprite spriteFond4;
	sf::Texture textFond4;
	if(!textFond4.loadFromFile("img/Tmt.png",sf::IntRect(0,0,1369,744)))
		printf("\n\nerreur lors du chargement de l'image\n\n");
	spriteFond4.setTexture(textFond4);
	spriteFond4.setPosition(4104, 0);

	//fond 5
	sf::Sprite spriteFond5;
	sf::Texture textFond5;
	if(!textFond5.loadFromFile("img/foret1.png",sf::IntRect(0,0,1369,744)))
		printf("\n\nerreur lors du chargement de l'image\n\n");
	spriteFond5.setTexture(textFond5);
	spriteFond5.setPosition(5472, 0);

	//fond 6
	sf::Sprite spriteFond6;
	sf::Texture textFond6;
	if(!textFond6.loadFromFile("img/feu1.png",sf::IntRect(0,0,1369,744)))
		printf("\n\nerreur lors du chargement de l'image\n\n");
	spriteFond6.setTexture(textFond6);
	spriteFond6.setPosition(6837, 0);
	



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
			
            if (event.type == sf::Event::Closed)
                window.close();
            //~ if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			//~ {
				//~ rectangle.move(-5,0);
				
			//~ }
			//~ if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			//~ {
				//~ rectangle.move(+5,0);
			//~ }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				down=1;
				
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				up=1;
				
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				b=1;
			}
			//relache espace
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
				b=0;
				}
			}
			//relache le up
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down)
				{
				up=0;
				}
			}
			//relache le down
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Down)
				{
				down=0;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				window.close();
			}
			
        }
        //cinematique du debut :
        if (demarrage==1){
			if (spriteKnadair.getPosition().y==300)
				demarrage=0;
			else{
				spriteKnadair.setPosition(spriteKnadair.getPosition().x,spriteKnadair.getPosition().y-5);
			}
		}else{
			//down
			//incline plus ou moins le canadaire vers le bas celon son inclinaison actuelle (ou ne s'incline pas si deja trop incliné)
			if(up==1)
			{
				if(spriteKnadair.getRotation()+0.5<10 || spriteKnadair.getRotation()+0.5>350){
					spriteKnadair.setRotation(spriteKnadair.getRotation()+0.5);
					rectangleBis.setRotation(rectangleBis.getRotation()+0.5);}
				if(spriteKnadair.getRotation()+1>350){
					spriteKnadair.setRotation(spriteKnadair.getRotation()+1);
					rectangleBis.setRotation(rectangleBis.getRotation()+1);}
			}

			//Up
			//incline plus ou moins le canadaire vers le bas haut son inclinaison actuelle (ou ne s'incline pas si deja trop incliné)
			if(down==1)
			{
				if(spriteKnadair.getRotation()>350 || spriteKnadair.getRotation()<10){
					spriteKnadair.setRotation(spriteKnadair.getRotation()-0.5);
					rectangleBis.setRotation(rectangleBis.getRotation()-0.5);}
				if(spriteKnadair.getRotation()<10){
					spriteKnadair.setRotation(spriteKnadair.getRotation()-1);
					rectangleBis.setRotation(rectangleBis.getRotation()-1);}
			}
			
			
			spriteKnadair.move(0,moveKnadair(spriteKnadair));
			//~ rectangleBis.move(0,moveKnadair(rectangle));
			sf::Vector2f position = rectangle2.getPosition();
			if(position.x==-200)
				rectangle2.setPosition(600, 500);
			rectangle2.move(-1,0);
			//la collision 
			sf::FloatRect rectanglecol = spriteKnadair.getGlobalBounds();
			sf::FloatRect rectangle2col = rectangle2.getGlobalBounds();
			if (rectangle2col.intersects(rectanglecol))
			{
				a=1;
			}
		}
		spriteFond1.move(-vitesse,0);
		spriteFond2.move(-vitesse,0);
		spriteFond3.move(-vitesse,0);
		spriteFond4.move(-vitesse,0);
		spriteFond5.move(-vitesse,0);
		spriteFond6.move(-vitesse,0);
		
		window.clear(sf::Color(255, 255, 255));
		//~ window.clear();
		//affiche le fond 1 uniquement au debut
		if (spriteFond1.getPosition().x>-1369)
			window.draw(spriteFond1);
		if (spriteFond2.getPosition().x>-1369 && spriteFond2.getPosition().x<=2736)
			window.draw(spriteFond2);
		else if(spriteFond2.getPosition().x<-1369)
			spriteFond2.setPosition(spriteFond2.getPosition().x+6837,0);
		if (spriteFond3.getPosition().x>-1369 && spriteFond3.getPosition().x<=2736)
			window.draw(spriteFond3);
		else if(spriteFond3.getPosition().x<-1369)
			spriteFond3.setPosition(spriteFond3.getPosition().x+6837,0);
		if (spriteFond4.getPosition().x>-1369 && spriteFond4.getPosition().x<=2736)
			window.draw(spriteFond4);
		else if(spriteFond4.getPosition().x<-1369)
			spriteFond4.setPosition(spriteFond4.getPosition().x+6837,0);
		if (spriteFond5.getPosition().x>-1369 && spriteFond5.getPosition().x<=2736)
			window.draw(spriteFond5);
		else if(spriteFond5.getPosition().x<-1369)
			spriteFond5.setPosition(spriteFond5.getPosition().x+6837,0);
		if (spriteFond6.getPosition().x>-1369 && spriteFond6.getPosition().x<=2736)
			window.draw(spriteFond6);
		else if(spriteFond6.getPosition().x<-1369)
			spriteFond6.setPosition(spriteFond6.getPosition().x+6837,0);
		window.draw(spriteKnadair);
		window.draw(rectangle2);
		if (a==1){
			window.draw(texte);
			window.draw(text2);
		}
		if (b==1){
			window.draw(rectangleBis);
		}
		
		
	
		

// mettre les draw ici: dans la boucle de dessin, entre window.clear() et window.display()
        window.display();
    }

    return 0;
}

//~ fonction qui fait monter et descendre le canadair plus ou moins vite en fonction de son inclinaison
//~ prend en argument notre structure du canadaire et renvoi un float qui correspond au déplacement horizontal du canadaire

float moveKnadair (sf::Sprite sprite)
{
	switch((int)sprite.getRotation())
	{
		case (1):
			return(0.1);
			break;
		case (2):
			return(0.2);
			break;
		case (3):
			return(0.3);
			break;
		case(4):
			return(0.4);
			break;
		case(5):
			return(0.5);
			break;
		case(6):
			return(0.6);
			break;
		case(7):
			return(0.7);
			break;
		case(8):
			return(0.8);
			break;
		case(9):
			return(0.9);
			break;
		case(10):
			return(1);
			break;
		case(350):
			return(-1);
			break;
		case(351):
			return(-0.9);
			break;
		case(352):
			return(-0.8);
			break;
		case(353):
			return(-0.7);
			break;
		case(354):
			return(-0.6);
			break;
		case(355):
			return(-0.5);
			break;
		case(356):
			return(-0.4);
			break;
		case(357):
			return(-0.3);
			break;
		case(358):
			return(-0.2);
			break;
		case(359):
			return(-0.1);
			break;
	}
	return 0.1;
}


