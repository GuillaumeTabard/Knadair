#include <SFML/Graphics.hpp>
//pour le compiler:
//g++ -c main.cpp
//g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

float moveKnadair (sf::Sprite sprite);
sf::Texture* initTexture (void);
sf::Sprite* initSprite (sf::Texture* tabTexture);
sf::Sprite afficheFond(sf::Sprite sprite, sf::RenderWindow* window);

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
	rectangleBis.setPosition(1369, 250);
	
	sf::RectangleShape rectangle2(sf::Vector2f(200, 100));
	rectangle2.setFillColor(sf::Color::Green);
	rectangle2.setPosition(1369, 500);

	int a =0;
	int b=0;
	int vitesse=20; //la vitesse de l'avion (du défilement des décords)
	int demarrage=1; //indique si la cinématique de début de jeu est fini ou pas
	int down=0;	//indique si la touche down est enfoncé (1) ou pas (0)
	int up=0; 	//indique si la touche up est enfoncé (1) ou pas (0)
	int right=0;//indique si la touche right est enfoncé (1) ou pas (0)
	int left=0; //indique si la touche left est enfoncé (1) ou pas (0)
	
	//knadair
	sf::Sprite spriteKnadair;
	sf::Texture textKnadair;
	if(!textKnadair.loadFromFile("img/Knadaire.png",sf::IntRect(0,0,152,52)))
		printf("\n\nerreur lors du chargement de l'image\n\n");
	spriteKnadair.setTexture(textKnadair);
	spriteKnadair.setPosition(200, 650);

	//initialise les texture des fonds
	sf::Texture* tabTexture;
	tabTexture= (sf::Texture*)malloc(sizeof(sf::Texture )*6);
	tabTexture= initTexture ();

	//initialise les sprite des fonds
	sf::Sprite* tabSprite;
	tabSprite= (sf::Sprite*)malloc(sizeof(sf::Sprite )*6);
	tabSprite=initSprite(tabTexture);
	sf::Sprite sprite0=tabSprite[0];
	sf::Sprite sprite1=tabSprite[1];
	sf::Sprite sprite2=tabSprite[2];
	sf::Sprite sprite3=tabSprite[3];
	sf::Sprite sprite4=tabSprite[4];
	sf::Sprite sprite5=tabSprite[5];


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
			
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				left=1;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				right=1;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				down=1;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				up=1;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				b=1;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				window.close();
			if (event.type == sf::Event::KeyReleased)//relache espace
			{
				if (event.key.code == sf::Keyboard::Space)
				b=0;
			}
			if (event.type == sf::Event::KeyReleased)//relache le up
			{
				if (event.key.code == sf::Keyboard::Up)
				up=0;
			}
			if (event.type == sf::Event::KeyReleased)//relache le down
			{
				if (event.key.code == sf::Keyboard::Down)
				down=0;
			}
			if (event.type == sf::Event::KeyReleased)//relache le right
			{
				if (event.key.code == sf::Keyboard::Right)
				right=0;
			}
			if (event.type == sf::Event::KeyReleased)//relache le left
			{
				if (event.key.code == sf::Keyboard::Left)
				left=0;
			}
			
        }
        //cinematique du debut (empeche de bouger le canadair pendant la cinematique) :
        if (demarrage==1){
			if (spriteKnadair.getPosition().y==300)
				demarrage=0; //sort de la boucle de démarrage
			else{
				spriteKnadair.setPosition(spriteKnadair.getPosition().x,spriteKnadair.getPosition().y-5); //fait décoler l'avion
			}
		}else{
			//down
			//incline plus ou moins le canadaire vers le bas celon son inclinaison actuelle (ou ne s'incline pas si deja trop incliné)
			if(up==1){
				if(spriteKnadair.getRotation()+0.5<10 || spriteKnadair.getRotation()+0.5>350){
					spriteKnadair.setRotation(spriteKnadair.getRotation()+0.5);
					rectangleBis.setRotation(rectangleBis.getRotation()+0.5);}
				if(spriteKnadair.getRotation()+1>350){
					spriteKnadair.setRotation(spriteKnadair.getRotation()+1);
					rectangleBis.setRotation(rectangleBis.getRotation()+1);}
			}

			//up
			//incline plus ou moins le canadaire vers le bas haut son inclinaison actuelle (ou ne s'incline pas si deja trop incliné)
			if(down==1){
				if(spriteKnadair.getRotation()>350 || spriteKnadair.getRotation()<10){
					spriteKnadair.setRotation(spriteKnadair.getRotation()-0.5);
					rectangleBis.setRotation(rectangleBis.getRotation()-0.5);}
				if(spriteKnadair.getRotation()<10){
					spriteKnadair.setRotation(spriteKnadair.getRotation()-1);
					rectangleBis.setRotation(rectangleBis.getRotation()-1);}
			}

			//right
			//accélère l'avion jusquà un maximum
			if (right==1 && vitesse<=40)
				vitesse+=1;
			//left
			//décélère jusqu'à un minimum
			if (left==1 && vitesse >10)
				vitesse-=1;
			spriteKnadair.move(0,moveKnadair(spriteKnadair));
			//~ rectangleBis.move(0,moveKnadair(rectangle));
			
			//la collision 
			sf::FloatRect rectanglecol = spriteKnadair.getGlobalBounds();
			sf::FloatRect rectangle2col = rectangle2.getGlobalBounds();
			if (rectangle2col.intersects(rectanglecol))
			{
				a=1;
			}
		}
		///////////////////
		if(rectangle2.getPosition().x<=-200)
			rectangle2.setPosition(1300, 500);
		rectangle2.move(-30,0);
			///////////////////
		sprite0.move(-vitesse,0);
		sprite1.move(-vitesse,0);
		sprite2.move(-vitesse,0);
		sprite3.move(-vitesse,0);
		sprite4.move(-vitesse,0);
		sprite5.move(-vitesse,0);
		
		window.clear(sf::Color(255, 255, 255));
		//~ window.clear();
		
		//affiche le fond 1 uniquement au debut
		if (sprite0.getPosition().x>-1369)
			window.draw(sprite0);
		//affiche les autres fond
		sprite1=afficheFond(sprite1,&window);
		sprite2=afficheFond(sprite2,&window);
		sprite3=afficheFond(sprite3,&window);
		sprite4=afficheFond(sprite4,&window);
		sprite5=afficheFond(sprite5,&window);

		window.draw(spriteKnadair);//affiche le canadaire
		window.draw(rectangle2);
		if (a==1){
			window.draw(texte);
			window.draw(text2);
		}
		if (b==1){
			window.draw(rectangleBis);
		}
		
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
			return(0.3);
			break;
		case (2):
			return(0.4);
			break;
		case (3):
			return(0.5);
			break;
		case(4):
			return(0.6);
			break;
		case(5):
			return(0.7);
			break;
		case(6):
			return(0.8);
			break;
		case(7):
			return(0.9);
			break;
		case(8):
			return(1);
			break;
		case(9):
			return(2.5);
			break;
		case(10):
			return(3);
			break;
		case(350):
			return(-3);
			break;
		case(351):
			return(-2.5);
			break;
		case(352):
			return(-2);
			break;
		case(353):
			return(-0.9);
			break;
		case(354):
			return(-0.8);
			break;
		case(355):
			return(-0.7);
			break;
		case(356):
			return(-0.6);
			break;
		case(357):
			return(-0.5);
			break;
		case(358):
			return(-0.4);
			break;
		case(359):
			return(-0.3);
			break;
	}
	return 0.1;
}

//fonction qui créé les texture pour les fonds et le renvoie dans un tableau de texture
sf::Texture* initTexture (void){
	sf::Texture* tabTexture;
	tabTexture= (sf::Texture*)malloc(sizeof(sf::Texture )*6);
		
	if(!tabTexture[0].loadFromFile("img/start.png",sf::IntRect(0,0,1369,744)))
		printf("\n\nerreur lors du chargement de l'image 0\n\n");

	if(!tabTexture[1].loadFromFile("img/Ttm.png",sf::IntRect(0,0,1369,744)))
		printf("\n\nerreur lors du chargement de l'image 1\n\n");

	if(!tabTexture[2].loadFromFile("img/eau.png",sf::IntRect(0,0,1369,744)))
		printf("\n\nerreur lors du chargement de l'image 2\n\n");

	if(!tabTexture[3].loadFromFile("img/Tmt.png",sf::IntRect(0,0,1369,744)))
		printf("\n\nerreur lors du chargement de l'image 3\n\n");

	if(!tabTexture[4].loadFromFile("img/foret1.png",sf::IntRect(0,0,1369,744)))
		printf("\n\nerreur lors du chargement de l'image 4\n\n");

	if(!tabTexture[5].loadFromFile("img/feu1.png",sf::IntRect(0,0,1369,744)))
		printf("\n\nerreur lors du chargement de l'image 5\n\n");
		
	return tabTexture;
}

//fonction qui créé les sprite pour les fonds et le renvoie dans un tableau de sprite (prend en argument le tableau des textures des fonds)
sf::Sprite* initSprite (sf::Texture* tabTexture){
	sf::Sprite* tabSprite;
	tabSprite= (sf::Sprite*)malloc(sizeof(sf::Sprite )*6);
	sf::Sprite sprite0;
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	sf::Sprite sprite3;
	sf::Sprite sprite4;
	sf::Sprite sprite5;
	sprite0.setTexture(tabTexture[0]);
	
	sprite1.setTexture(tabTexture[1]);
	sprite1.setPosition(1368, 0);
	
	sprite2.setTexture(tabTexture[2]);
	sprite2.setPosition(2735, 0);
	
	sprite3.setTexture(tabTexture[3]);
	sprite3.setPosition(4104, 0);
	
	sprite4.setTexture(tabTexture[4]);
	sprite4.setPosition(5472, 0);
	
	sprite5.setTexture(tabTexture[5]);
	sprite5.setPosition(6837, 0);
	tabSprite[0]=sprite0;
	tabSprite[1]=sprite1;
	tabSprite[2]=sprite2;
	tabSprite[3]=sprite3;
	tabSprite[4]=sprite4;
	tabSprite[5]=sprite5;

	//~ tabSprite[0].setTexture(tabTexture[0]);
	
	//~ tabSprite[1].setTexture(tabTexture[1]);
	//~ tabSprite[1].setPosition(1368, 0);
	
	//~ tabSprite[2].setTexture(tabTexture[2]);
	//~ tabSprite[2].setPosition(2736, 0);
	
	//~ tabSprite[3].setTexture(tabTexture[3]);
	//~ tabSprite[3].setPosition(4104, 0);
	
	//~ tabSprite[4].setTexture(tabTexture[4]);
	//~ tabSprite[4].setPosition(5472, 0);
	
	//~ tabSprite[5].setTexture(tabTexture[5]);
	//~ tabSprite[5].setPosition(6837, 0);
	
	
	return tabSprite;
}

//affiche les autres fond uniquement si ils sont sur l'écran et les replace à la suite pour boucler le circuit
sf::Sprite afficheFond(sf::Sprite sprite, sf::RenderWindow* window){
	if (sprite.getPosition().x>-1369 && sprite.getPosition().x<=2736)
		window->draw(sprite);
	else if(sprite.getPosition().x<-1369)
		sprite.setPosition(sprite.getPosition().x+6837,0);
	return sprite;
}


