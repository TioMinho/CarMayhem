#include <SFML\Graphics.hpp>
#include "Menus.h"

//Construtor Padrão
Menus::Menus(){}

/*GETTERS*/
int Menus::getOption(){
	return optionSelected;
}

sf::Sprite Menus::menuDraw(){
	return menuBackground;
}

//Método abstrato para interação das seleções com o usuário
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

//Método para checar se o menu está aberto ou fechado
bool Menus::isMenuOpen(){
	return menuOpen;
}

//Método para abrir o menu
void Menus::abrirMenu(){
	menuOpen = 1;
}

//Método para fechar o menu
void Menus::fecharMenu(){
	menuOpen = 0;
	optionSelected = 0;
}

//Método abstrato para ativar a seleção do menu quando aberto
void Menus::ativarSelecao(){}

//Método que atribui o valor da seleção à uma variável para ser utilizado no game
void Menus::selectOption(){
	optionSelected = numSelecao;
}