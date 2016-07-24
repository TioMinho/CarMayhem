#pragma once
#include "Menus.h"
class MenuPause : public Menus{
private:
	//*******************
	//****Atributos******
	//*******************
	sf::Text optionContinue, optionMenu, optionQuit;			// Textos para as opções do menu
	sf::Font fontOption;										// Fonte para os textos

public:
	//*******************
	//*****Métodos*******
	//*******************
	//Construtor Padrão
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

	//Método para ativar a seleção do menu
	void ativarSelecao();
};
