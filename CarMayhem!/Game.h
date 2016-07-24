#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <string>
#include <iostream>
#include "Jogador.h"
#include "Mapas.h"
#include "Collision.h"
#include "MenuPersonagens.h"
#include "MenuInicial.h"
#include "MenuPause.h"
#include "MenuEndGame.h"
#include "MenuCreditos.h"
#include "BGM.h"
#include "SoundEffect.h"

class Game{
private:
	//*******************
	//****Atributos******
	//*******************
	Jogador player[2];				// Cria dois objetos da classe Jogador, referenciando os players 1 e 2
	MenuInicial menuInicial;		// Cria um objeto da classe MenuInicial, o primeiro menu do Game
	MenuCreditos menuCreditos;		// Cria um objeto da classe MenuCreditos, representando o menu que exibe os cr�ditos do jogo
	MenuPersonagens menuSelecao[2];	// Cria dois objetos da classe MenuPersonagens, o menu seletor do carro de cada player
	MenuPause menuPause;			// Cria um objeto da classe MenuPause, representando o menu de pausa dentro da corrida
	MenuEndRace endRaceMenu;		// Cria um objeto da classe MenuEndGame, representando o menu ao final de uma corrida
	TileTracks mapaPista;			// Cria um objeto da classe TileTracks, representando o mapa do circuito
	BGM menuBGM, raceBGM;			// Cria um objeto da classe BGM, representando o "background music" do jogo
	SoundEffect menuSE;				// Cria um objetos da classe SoundEffect, representando os efeitos sonoros do jogo
	sf::View cameraGenerica;		// Cria um objeto da classe sf::View, que ser� a c�mera dos menus iniciais
	sf::Clock timer[2];				// Cria dois objetos da classe sf::Clock para a manipula��o do tempo dentro do game
	bool finishRace = true;			// Cria uma vari�vel do tipo booleano para terminar uma corrida prematuramente

	sf::RectangleShape rectTeste;	// Cria um objeto da classe sf::RectangleShape para manipular o editor de mapas de colis�o
	float x = 0, y = 0, z = 0;		// Cria 3 vari�veis do tipo float para armazenar os valores durante a edi��o

	sf::RenderWindow gameWindow;	// Cria um objeto da classe sf::RenderWindow, representando a janela principal do game
	sf::Vector2i dimensaoJanela;	// Cria um objeto do tipo sf::Vector2i, ou seja, dois inteiros da dimens�o da janela do game

	//*******************
	//*****M�todos*******
	//*******************

	//Renderiza o Tile Map da Pista Principal
	void renderMap();

	//Renderiza a GUI
	void renderGUI(int numPlayer);

	//Renderiza os proj�teis ao mesmo tempo
	void renderProjeteis();

	//Renderiza o menu Pause in-game
	void renderPause();

	//Inicia o menu inicial e mant�m o loop at� que uma op��o no seletor de personagens seja retornado
	void renderMenus();
	
	//Posiciona os carros na linha de chegada para iniciar a corrida
	void iniciarCorrida();

	//Checa se o carro ultrapassou a linha de chegada e atribui um valor ao Lap (volta)
	void checkLap();

	//Checa em tempo-real se o n�mero de laps de um dos players atinge o n�mero m�ximo, terminando a corrida
	void isRaceOver();

	//Checa por colis�es com bordas das pistas ou obst�culos em tempo real
	void checkCollision(int numberPlayer);

	//Ativa os movimentos de ambos os players e checa suas teclas ativas em tempo real
	void ativarMovimentos();

	//Metodo principal para atualizar checagens de colis�o, posicionamento da c�mera, sprites e entradas do teclado
	void gameUpdate();

	//Ferramente para manipular tipos ret�ngulares e auxiliar na delimita��o de objetos colid�veis
	void ferramentaMapaConstrutor();

public:
	//*******************
	//*****M�todos*******
	//*******************
	//Construtor Padr�o
	Game();

	//M�todo principal no main thread para rodar o game inteiro
	void rodarGame();
};