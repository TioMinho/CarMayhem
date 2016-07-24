#include <SFML/Graphics.hpp>
#include "MenuPersonagens.h"

//*******************
//*****Métodos*******
//*******************
//Construtor Padrão
MenuPersonagens::MenuPersonagens(){
	//Inicializa o menu fechado
	menuOpen = 0;

	//Carregar Textura da Fonte e do Menu
	fonte.loadFromFile("Resources/Fonts/FaceYourFears.ttf");
	menuTextura.loadFromFile("Resources/Menus/menuPersonagens.png");

	//Inserindo textura num sprite para exibir o Background
	menuBackground.setTexture(menuTextura);

	//Posicionamento e Tamanho das Fontes
	nomeCarro.setFont(fonte);
	nomeCarro.setColor(sf::Color::Black);
	nomeCarro.setCharacterSize(40);
	nomeCarro.setPosition(110, 150);
	musicas.setFont(fonte);
	musicas.setColor(sf::Color::Black);
	musicas.setCharacterSize(25);
	musicas.setPosition(1200, 250);

	//Coloração das Barros de Aceleração, Velocidade, Munição e Life
	acelleration.setPosition(105, 310);
	acelleration.setFillColor(sf::Color(35, 35, 190));
	topSpeed.setPosition(105, 410);
	topSpeed.setFillColor(sf::Color(35, 35, 190));
	ammonition.setPosition(105, 510);
	ammonition.setFillColor(sf::Color(35, 35, 190));
	health.setPosition(105, 610);
	health.setFillColor(sf::Color(35, 35, 190));

	//Posição do Mostruário
	mostruario.setPosition(800, 450);
}

//Construtor Personalizado
MenuPersonagens::MenuPersonagens(std::string nomeFonte, std::string menuBG){
	//Inicia com o menu fechado
	menuOpen = 0;

	//Carregar Textura da Fonte e do Menu
	fonte.loadFromFile(nomeFonte);
	menuTextura.loadFromFile(menuBG);

	//Inserindo textura num sprite para exibir o Background
	menuBackground.setTexture(menuTextura);

	//Posicionamento e Tamanho das Fontes
	nomeCarro.setFont(fonte);
	nomeCarro.setColor(sf::Color::Black);
	nomeCarro.setCharacterSize(40);
	nomeCarro.setPosition(110, 150);
	musicas.setFont(fonte);
	musicas.setColor(sf::Color::Black);
	musicas.setCharacterSize(50);
	musicas.setPosition(1200, 250);

	//Coloração das Barros de Aceleração, Velocidade, Munição e Life
	acelleration.setPosition(105, 310);
	acelleration.setFillColor(sf::Color(35, 35, 190));
	topSpeed.setPosition(105, 410);
	topSpeed.setFillColor(sf::Color(35, 35, 190));
	ammonition.setPosition(105, 510);
	ammonition.setFillColor(sf::Color(35, 35, 190));
	health.setPosition(105, 610);
	health.setFillColor(sf::Color(35, 35, 190));

	//Posição do Mostruário
	mostruario.setPosition(790, 450);
}

/*GETTERS*/
sf::RectangleShape MenuPersonagens::getAcelleration(){
	return acelleration;
}

sf::RectangleShape MenuPersonagens::getTopSpeed(){
	return topSpeed;
}

sf::RectangleShape MenuPersonagens::getAmmo(){
	return ammonition;
}

sf::RectangleShape MenuPersonagens::getHealth(){
	return health;
}

sf::Sprite MenuPersonagens::getMostruario(){
	return mostruario.getSprite();
}

sf::Text MenuPersonagens::getNomeSelecao(){
	return nomeCarro;
}

sf::Text MenuPersonagens::getTracklist(){
	return musicas;
}

/*SETTERS*/
void MenuPersonagens::setImagem(std::string imagemBG){
	//Loaders para a textura do Menu
	menuTextura.loadFromFile(imagemBG);

	//Atribuição de Texturas para os Sprites
	menuBackground.setTexture(menuTextura);
}

//Método principal para ativar a seleção com o menu aberto
void MenuPersonagens::ativarSelecao(){
	selecaoMenu();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		selectOption();

	switch (numSelecao){
	case 1:
		nomeCarro.setString("The Illuminatian");
		acelleration.setSize(sf::Vector2f(250, 30));
		topSpeed.setSize(sf::Vector2f(300, 30));
		ammonition.setSize(sf::Vector2f(50, 30));
		health.setSize(sf::Vector2f(100, 30));
		musicas.setString("Iron Maiden - The Trooper\n\nMetallica - Creeping Death\n\nJudas Priest - Electric Eye\n\nBlack Sabbath - Iron Man\n\nMotorhead - Ace of Spades\n\n");
		mostruario.setTexture("Resources/Sprites/theIlluminatian.png");
		mostruario.setTextureRect(4 * 47, 0, 47, 38);
		break;
	case 2:
		nomeCarro.setString("  Little Jack   ");
		acelleration.setSize(sf::Vector2f(200, 30));
		topSpeed.setSize(sf::Vector2f(200, 30));
		ammonition.setSize(sf::Vector2f(150, 30));
		health.setSize(sf::Vector2f(300, 30));
		musicas.setString("AC/DC - Highway to Hell\n\nVan Halen - Ain't Talking 'Bout Love\n\nKiss - Detroit Rock City\n\nBon Jovi - Living On a Prayer\n\nGuns'n Roses - Welcome To The Jungle\n\n");
		mostruario.setTexture("Resources/Sprites/littleJack.png");
		mostruario.setTextureRect(4 * 46, 0, 46, 31);
		break;
	case 3:
		nomeCarro.setString("  Liese Vicious ");
		acelleration.setSize(sf::Vector2f(50, 30));
		topSpeed.setSize(sf::Vector2f(100, 30));
		ammonition.setSize(sf::Vector2f(300, 30));
		health.setSize(sf::Vector2f(300, 30));
		musicas.setString("Misfits - Dig Up Her Bones\n\nRamones - Blitzkrieg Bop\n\nDead Kennedys - Holiday in Cambodia\n\nNirvana - Smells Like Teen Spirit\n\nJoan Jett - Bad Reputation\n\n");
		mostruario.setTexture("Resources/Sprites/lieseVicious.png");
		mostruario.setTextureRect(4 * 47, 0, 47, 27);
		break;
	}
}