#include <SFML\Graphics.hpp>
#include "Menus.h"

//Construtor Padr�o
Menus::Menus(){}

/*GETTERS*/
int Menus::getOption(){
	return optionSelected;
}

sf::Sprite Menus::menuDraw(){
	return menuBackground;
}

//M�todo abstrato para intera��o das sele��es com o usu�rio
void Menus::selecaoMenu(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
		if (numSelecao < 3 && numSelecao >= 1)
			numSelecao++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		if (numSelecao <= 3 && numSelecao > 1)
			numSelecao--;
	}
}

//M�todo para checar se o menu est� aberto ou fechado
bool Menus::isMenuOpen(){
	return menuOpen;
}

//M�todo para abrir o menu
void Menus::abrirMenu(){
	menuOpen = 1;
}

//M�todo para fechar o menu
void Menus::fecharMenu(){
	menuOpen = 0;
	optionSelected = 0;
}

//M�todo abstrato para ativar a sele��o do menu quando aberto
void Menus::ativarSelecao(){}

//M�todo que atribui o valor da sele��o � uma vari�vel para ser utilizado no game
void Menus::selectOption(){
	optionSelected = numSelecao;
}