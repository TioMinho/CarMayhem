#pragma once
#include "Menus.h"
class MenuInicial : public Menus{
private:
	//*******************
	//****Atributos******
	//*******************
	sf::Sprite caixaSelecao;			// Sprite de caixa de seleção do menu inicial
	sf::Texture imagemSelecao;			// Textura dinâmica da caixa de seleção

public:
	//*******************
	//*****Métodos*******
	//*******************
	//Construtor Padrão
	MenuInicial();

	//Construtor Personalizado
	MenuInicial(std::string imagemBG);

	/*GETTER*/
	sf::Sprite getSelecao();

	/*SETTER*/
	void setImagem(std::string imagemBG);

	//Método principal para ativar a seleção no menu aberto
	void ativarSelecao();
};