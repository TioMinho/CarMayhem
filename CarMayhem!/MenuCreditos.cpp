#include <SFML/Graphics.hpp>
#include "MenuCreditos.h"

MenuCreditos::MenuCreditos(){
	//Inicializa o menu fechado
	menuOpen = false;

	//Carrega a textura do sprite do menu
	menuTextura.loadFromFile("Resources/Menus/creditos.png");

	//Atribui a textura ao sprite
	menuBackground.setTexture(menuTextura);
}

