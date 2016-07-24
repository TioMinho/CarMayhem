#include <SFML\Graphics.hpp>
#include "MenuEndGame.h"

//Construtor Padrão
MenuEndRace::MenuEndRace(){
	//Inicializa o MenuPause fechado
	menuOpen = 0;

	//Carrega a textura do background do menu
	menuTextura.loadFromFile("Resources/Menus/menuEndRace.png");

	//Atribui a textura ao sprite do background
	menuBackground.setTexture(menuTextura);

	//Carrega a fonte dos textos
	fontOption.loadFromFile("Resources/Fonts/ColdNightForAlligators.ttf");

	//Atribui a fonte ao sf::Text que anuncia o vencedor e o posiciona de acordo com a caixa de seleção
	winnerName.setFont(fontOption);
	winnerName.setCharacterSize(80);
	winnerName.setColor(sf::Color::White);
	winnerName.setPosition(sf::Vector2f(700, 320));

	//Atribui a fonte aos sf::Text das Opções e os posiciona de acordo com a caixa de seleção
	optionPlay.setFont(fontOption);
	optionPlay.setString("Play Again");
	optionPlay.setCharacterSize(70);
	optionPlay.setPosition(sf::Vector2f(735, 470));
	optionQuit.setFont(fontOption);
	optionQuit.setString("Quit");
	optionQuit.setCharacterSize(70);
	optionQuit.setPosition(sf::Vector2f(805, 560));
}

//Construtor Personalizado
MenuEndRace::MenuEndRace(std::string nomeFonte, std::string menuBG){
	//Inicializa o MenuPause fechado
	menuOpen = 0;

	//Carrega a textura do background do menu
	menuTextura.loadFromFile(nomeFonte);

	//Atribui a textura ao sprite do background
	menuBackground.setTexture(menuTextura);

	//Carrega a fonte dos textos
	fontOption.loadFromFile(menuBG);

	//Atribui a fonte ao sf::Text que anuncia o vencedor e o posiciona de acordo com a caixa de seleção
	winnerName.setFont(fontOption);
	winnerName.setCharacterSize(80);
	winnerName.setColor(sf::Color::White);
	winnerName.setPosition(sf::Vector2f(700, 320));

	//Atribui a fonte aos sf::Text das Opções e os posiciona de acordo com a caixa de seleção
	optionPlay.setFont(fontOption);
	optionPlay.setString("Play Again");
	optionPlay.setCharacterSize(70);
	optionPlay.setPosition(sf::Vector2f(735, 470));
	optionQuit.setFont(fontOption);
	optionQuit.setString("Quit");
	optionQuit.setCharacterSize(70);
	optionQuit.setPosition(sf::Vector2f(805, 560));
}

/*SETTERS*/
void MenuEndRace::setWinnerName(std::string nomeVencedor){
	winnerName.setString(nomeVencedor);
}

void MenuEndRace::setFont(std::string nomeFonte){
	fontOption.loadFromFile(nomeFonte);
}

void MenuEndRace::setMenuBG(std::string menuBG){
	menuTextura.loadFromFile(menuBG);
}

/*GETTERS*/
sf::Text MenuEndRace::getWinnerName(){
	return winnerName;
}

sf::Text MenuEndRace::getOptionPlay(){
	return optionPlay;
}

sf::Text MenuEndRace::getOptionQuit(){
	return optionQuit;
}

//Sobreescrita do método seleçãoMenu
void MenuEndRace::selecaoMenu(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		if (numSelecao < 2 && numSelecao >= 1)
			numSelecao++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		if (numSelecao <= 2 && numSelecao > 1)
			numSelecao--;
	}
}

//Método principal para ativar a seleção do menu
void MenuEndRace::ativarSelecao(){
	selecaoMenu();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		selectOption();

	switch (numSelecao){
	case 1:
		optionPlay.setColor(sf::Color::White);
		optionQuit.setColor(sf::Color::Transparent);
		break;
	case 2:
		optionPlay.setColor(sf::Color::Transparent);
		optionQuit.setColor(sf::Color::White);
		break;
	}
}