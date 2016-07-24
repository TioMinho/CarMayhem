#pragma once
#include "Menus.h"
class MenuPause : public Menus{
private:
	//*******************
	//****Atributos******
	//*******************
	sf::Text optionContinue, optionMenu, optionQuit;			// Textos para as op��es do menu
	sf::Font fontOption;										// Fonte para os textos

public:
	//*******************
	//*****M�todos*******
	//*******************
	//Construtor Padr�o
	MenuPause();

	//Construtor Personalizado
	MenuPause(std::string nomeFonte, std::string menuBG);

	/*SETTERS*/
	void setFont(std::string nomeFonte);

	void setMenuBG(std::string menuBG);

	/*GETTERS*/
	sf::Text getOptionContinue();

	sf::Text getOptionMenu();

	sf::Text getOptionQuit();

	//M�todo para ativar a sele��o do menu
	void ativarSelecao();
};
