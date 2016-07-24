#pragma once
#include "Menus.h"
class MenuEndRace : public Menus {
private:
	//*******************
	//****Atributos******
	//*******************
	sf::Text winnerName, optionPlay, optionQuit;				// Textos para as opções do menu
	sf::Font fontOption;										// Fonte para os textos

	//Sobreescrita do método void menu::selecaoMenu()
	void selecaoMenu();

public:
	//*******************
	//*****Métodos*******
	//*******************
	//Construtor Padrão
	MenuEndRace();

	//Construtor Personalizado
	MenuEndRace(std::string nomeFonte, std::string menuBG);

	/*SETTERS*/
	void setWinnerName(std::string nomeVencedor);

	void setFont(std::string nomeFonte);

	void setMenuBG(std::string menuBG);

	/*GETTERS*/
	sf::Text getWinnerName();

	sf::Text getOptionPlay();

	sf::Text getOptionQuit();

	//Menu para ativar a seleção do menu
	void ativarSelecao();
};