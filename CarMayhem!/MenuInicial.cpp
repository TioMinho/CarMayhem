#include <SFML/Graphics.hpp>
#include "MenuInicial.h"

//Construtor Padr�o
MenuInicial::MenuInicial(){
	//Inicializa o menu aberto
	menuOpen = 1;

	//Loaders para a textura do Menu
	menuTextura.loadFromFile("Resources/Menus/menuInicialBG.png");

	//Atribui��o de Texturas para os Sprites
	menuBackground.setTexture(menuTextura);

	//Posiciona a caixa de Sele��o
	caixaSelecao.setPosition(478.5, 643);
	imagemSelecao.loadFromFile("Resources/Menus/firstOption.png");
	caixaSelecao.setTexture(imagemSelecao);
}

//Construtor Personalizado
MenuInicial::MenuInicial(std::string imagemBG){
	//Inicializa o menu aberto
	menuOpen = 1;

	//Loaders para a textura do Menu
	menuTextura.loadFromFile(imagemBG);

	//Atribui��o de Texturas para os Sprites
	menuBackground.setTexture(menuTextura);

	//Posiciona a caixa de Sele��o
	caixaSelecao.setPosition(478.5, 643);
	caixaSelecao.setTexture(imagemSelecao);
}

/*GETTER*/
sf::Sprite MenuInicial::getSelecao(){
	return caixaSelecao;
}

/*SETTER*/
void MenuInicial::setImagem(std::string imagemBG){
	//Loaders para a textura do Menu
	menuTextura.loadFromFile(imagemBG);

	//Atribui��o de Texturas para os Sprites
	menuBackground.setTexture(menuTextura);

	//Posiciona a caixa de Sele��o
	caixaSelecao.setPosition(478.5, 643);
	imagemSelecao.loadFromFile("Resources/Menus/firstOption.png");
	caixaSelecao.setTexture(imagemSelecao);
}

//M�todo principal para ativar a sele��o no menu aberto
void MenuInicial::ativarSelecao(){
	selecaoMenu();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		selectOption();

	switch (numSelecao){
	case 1:
		imagemSelecao.loadFromFile("Resources/Menus/start.png");
		break;
	case 2:
		imagemSelecao.loadFromFile("Resources/Menus/credits.png");
		break;
	case 3:
		imagemSelecao.loadFromFile("Resources/Menus/quit.png");
		break;
	}

	caixaSelecao.setTexture(imagemSelecao);
}