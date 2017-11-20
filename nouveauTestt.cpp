#include <SFML/Graphics.hpp>

sf::Texture* initTexture (void);
sf::Sprite* initSprite (sf::Texture* tabTexture);

int main()
{
    sf::RenderWindow window(sf::VideoMode(1369, 744), "titre de la fenetre");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
	//~ int vitesse =10;
	sf::Texture* tabTexture;
	tabTexture= (sf::Texture*)malloc(sizeof(sf::Texture )*6);
	tabTexture= initTexture ();

	//initialise les sprite des fonds
	sf::Sprite* tabSprite;
	tabSprite= (sf::Sprite*)malloc(sizeof(sf::Sprite )*6);
	tabSprite=initSprite(tabTexture);
	
	
	sf::Sprite sprite0=tabSprite[0];
	//~ sf::Texture texture0=tabTexture[0];
	//~ sf::Sprite sprite0;
	//~ sprite0.setTexture(texture0);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		//~ tabSprite[0]->move(-vitesse,0);
		//~ tabSprite[1]->move(-vitesse,0);
		//~ tabSprite[2]->move(-vitesse,0);
		//~ tabSprite[3]->move(-vitesse,0);
		//~ tabSprite[4]->move(-vitesse,0);
		//~ tabSprite[5]->move(-vitesse,0);
		//~ if (tabSprite[0].getPosition().x>-1369)
			
		
		//~ for (int i=1; i<6 ; i++){
			//~ //affiche le fond 2 à la suite du fond 1 puis le replace à la suite des autres
			//~ if (tabSprite[i].getPosition().x>-1369 && tabSprite[i].getPosition().x<=2736)
				//~ window.draw(tabSprite[i]);
			//~ else if(tabSprite[i].getPosition().x<-1369)
				//~ tabSprite[i].setPosition(tabSprite[i].getPosition().x+6837,0);
		//~ }
		
        window.clear();
        //initialise les texture des fonds
		window.draw(sprite0);
        window.draw(shape);
        window.display();
    }

    return 0;
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
	sprite2.setPosition(2736, 0);
	
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
	
	return tabSprite;
}
