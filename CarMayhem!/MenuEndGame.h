#pragma once
#include "Menus.h"
class MenuEndRace : public Menus {
private:
	//*******************
	//****Atributos******
	//*******************
	sf::Text winnerName, optionPlay, optionQuit;				// Textos para as op��es do menu
	sf::Font fontOption;										// Fonte para os textos

	//Sobreescrita do m�todo void menu::selecaoMenu()
	void selecaoMenu();

public:
	//*******************
	//*****M�todos*******
	//*******************
	//Construtor Padr�o
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

	//Menu para ativar a sele��o do menu
	void ativarSelecao();
};