#pragma once
#include "Menus.h"
class MenuInicial : public Menus{
private:
	//*******************
	//****Atributos******
	//*******************
	sf::Sprite caixaSelecao;			// Sprite de caixa de sele��o do menu inicial
	sf::Texture imagemSelecao;			// Textura din�mica da caixa de sele��o

public:
	//*******************
	//*****M�todos*******
	//*******************
	//Construtor Padr�o
	MenuInicial();

	//Construtor Personalizado
	MenuInicial(std::string imagemBG);

	/*GETTER*/
	sf::Sprite getSelecao();

	/*SETTER*/
	void setImagem(std::string imagemBG);

	//M�todo principal para ativar a sele��o no menu aberto
	void ativarSelecao();
};