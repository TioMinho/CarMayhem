#include <SFML/Graphics.hpp>
#include "MenuPause.h"

//Construtor Padrão
MenuPause::MenuPause(){
	//Inicializa o MenuPause fechado
	menuOpen = 0;

	//Recebe a string para carregar a textura do sprite do menu
	menuTextura.loadFromFile("Resources/Menus/menuPause.png");

	//Atribui a textura ao sprite
	menuBackground.setTexture(menuTextura);

	//Carrega a fonte do texto das opções
	fontOption.loadFromFile("Resources/Fonts/ColdNightForAlligators.ttf");

	//Atribuição da fonte aos objetos sf::Text
	optionContinue.setFont(fontOption);
	optionMenu.setFont(fontOption);
	optionQuit.setFont(fontOption);

	//Inicialização das strings dos textos
	optionContinue.setString("Continue");
	optionMenu.setString("Quit to Main Menu");
	optionQuit.setString("Quit Game");

	//Posiciona cada texto em sua posição e tamanho
	optionContinue.setCharacterSize(70);
	optionContinue.setPosition(sf::Vector2f(765, 345));
	optionMenu.setCharacterSize(70);
	optionMenu.setPosition(sf::Vector2f(670, 430));
	optionQuit.setCharacterSize(70);
	optionQuit.setPosition(sf::Vector2f(760, 510));
}

//Construtor Personalizado
MenuPause::MenuPause(std::string nomeFonte, std::string menuBG){
	//Inicializa o MenuPause fechado
	menuOpen = 0;

	//Recebe a string para carregar a textura do sprite do menu
	menuTextura.loadFromFile(menuBG);

	//Atribui a textura ao sprite
	menuBackground.setTexture(menuTextura);

	//Carrega a fonte do texto das opções
	fontOption.loadFromFile(nomeFonte);

	//Atribuição da fonte aos objetos sf::Text
	optionContinue.setFont(fontOption);
	optionMenu.setFont(fontOption);
	optionQuit.setFont(fontOption);

	//Inicialização das strings dos textos
	optionContinue.setString("Continue");
	optionMenu.setString("Quit to Main Menu");
	optionQuit.setString("Quit Game");

	//Posiciona cada texto em sua posição e tamanho
	optionContinue.setCharacterSize(70);
	optionContinue.setPosition(sf::Vector2f(765, 345));
	optionMenu.setCharacterSize(70);
	optionMenu.setPosition(sf::Vector2f(670, 430));
	optionQuit.setCharacterSize(70);
	optionQuit.setPosition(sf::Vector2f(760, 510));
}

/*SETTERS*/
void MenuPause::setFont(std::string nomeFonte){
	fontOption.loadFromFile(nomeFonte);
}

void MenuPause::setMenuBG(std::string menuBG){
	menuTextura.loadFromFile(menuBG);
}

/*GETTERS*/
sf::Text MenuPause::getOptionContinue(){
	return optionContinue;
}

sf::Text MenuPause::getOptionMenu(){
	return optionMenu;
}

sf::Text MenuPause::getOptionQuit(){
	return optionQuit;
}

//Método para ativar a seleção do menu
void MenuPause::ativarSelecao(){
	selecaoMenu();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		selectOption();
	switch (numSelecao){
	case 1:
		optionContinue.setColor(sf::Color::White);
		optionMenu.setColor(sf::Color::Transparent);
		optionQuit.setColor(sf::Color::Transparent);
		break;
	case 2:
		optionContinue.setColor(sf::Color::Transparent);
		optionMenu.setColor(sf::Color::White);
		optionQuit.setColor(sf::Color::Transparent);
		break;
	case 3:
		optionContinue.setColor(sf::Color::Transparent);
		optionMenu.setColor(sf::Color::Transparent);
		optionQuit.setColor(sf::Color::White);
		break;
	}
}