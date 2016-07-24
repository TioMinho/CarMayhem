#include <iostream>
#include <sstream>
#include <SFML\Graphics.hpp>
#include "GUI.h"

//Construtor Padrão
GUI::GUI(){}

//Metódo getter para a barra de HP
sf::RectangleShape GUI::getLifeBar(){
	return lifeBar;
}

//Metódo getter para a barra de Ammo
sf::RectangleShape GUI::getAmmoBar(){
	return ammoBar;
}

//Método para carregar a GUI
void GUI::loadGUI(int maxLife, int maxAmmo){
	//Inicializa as barras de HP e Munição
	lifeBar.setFillColor(sf::Color::Red);
	lifeBar.setSize(sf::Vector2f(maxLife, 50));
	ammoBar.setFillColor(sf::Color::Green);
	ammoBar.setSize(sf::Vector2f(maxAmmo, 50));
}

//Método de atualização dos valores das barras de HP e Ammo
void GUI::updateGUI(int positionX, int positionY, int actualHP, int actualAmmo){
	//Posiciona as barras de HP e Munição de acordo com a posição do carro (centro)
	lifeBar.setPosition(sf::Vector2f(positionX, positionY - 10));
	lifeBar.setSize(sf::Vector2f(actualHP / 5.0, 2));
	ammoBar.setPosition(sf::Vector2f(positionX, positionY - 5));
	ammoBar.setSize(sf::Vector2f(actualAmmo * 5, 2));
}