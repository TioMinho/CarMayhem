#pragma once
#include "Menus.h"
#include "Car.h"
class MenuPersonagens : public Menus{
private:
	//*******************
	//****Atributos******
	//*******************
	sf::RectangleShape acelleration, topSpeed, ammonition, health;  // Barras para representar os atributos de cada carro
	sf::Text nomePlayer, nomeCarro, musicas;						// Textos para exibir o nome do carro e seu repertório
	sf::Font fonte;													// Fonte para os textos
	Car mostruario;													// Mostruário gráfico do carro

public:
	//*******************
	//*****Métodos*******
	//*******************
	//Construtor Padrão
	MenuPersonagens();

	//Construtor Personalizado
	MenuPersonagens(std::string nomeFonte, std::string menuBG);

	/*GETTERS*/
	sf::RectangleShape getAcelleration();

	sf::RectangleShape getTopSpeed();

	sf::RectangleShape getAmmo();

	sf::RectangleShape getHealth();

	sf::Sprite getMostruario();

	sf::Text getNomeSelecao();

	sf::Text getTracklist();

	/*SETTERS*/
	void setImagem(std::string imagemBG);

	//Método principal para ativar a seleção com o menu aberto
	void ativarSelecao();
};
