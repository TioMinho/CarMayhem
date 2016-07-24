#pragma once
#include "Menus.h"
#include "Car.h"
class MenuPersonagens : public Menus{
private:
	//*******************
	//****Atributos******
	//*******************
	sf::RectangleShape acelleration, topSpeed, ammonition, health;  // Barras para representar os atributos de cada carro
	sf::Text nomePlayer, nomeCarro, musicas;						// Textos para exibir o nome do carro e seu repert�rio
	sf::Font fonte;													// Fonte para os textos
	Car mostruario;													// Mostru�rio gr�fico do carro

public:
	//*******************
	//*****M�todos*******
	//*******************
	//Construtor Padr�o
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

	//M�todo principal para ativar a sele��o com o menu aberto
	void ativarSelecao();
};
