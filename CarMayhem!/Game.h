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
	MenuCreditos menuCreditos;		// Cria um objeto da classe MenuCreditos, representando o menu que exibe os créditos do jogo
	MenuPersonagens menuSelecao[2];	// Cria dois objetos da classe MenuPersonagens, o menu seletor do carro de cada player
	MenuPause menuPause;			// Cria um objeto da classe MenuPause, representando o menu de pausa dentro da corrida
	MenuEndRace endRaceMenu;		// Cria um objeto da classe MenuEndGame, representando o menu ao final de uma corrida
	TileTracks mapaPista;			// Cria um objeto da classe TileTracks, representando o mapa do circuito
	BGM menuBGM, raceBGM;			// Cria um objeto da classe BGM, representando o "background music" do jogo
	SoundEffect menuSE;				// Cria um objetos da classe SoundEffect, representando os efeitos sonoros do jogo
	sf::View cameraGenerica;		// Cria um objeto da classe sf::View, que será a câmera dos menus iniciais
	sf::Clock timer[2];				// Cria dois objetos da classe sf::Clock para a manipulação do tempo dentro do game
	bool finishRace = true;			// Cria uma variável do tipo booleano para terminar uma corrida prematuramente

	sf::RectangleShape rectTeste;	// Cria um objeto da classe sf::RectangleShape para manipular o editor de mapas de colisão
	float x = 0, y = 0, z = 0;		// Cria 3 variáveis do tipo float para armazenar os valores durante a edição

	sf::RenderWindow gameWindow;	// Cria um objeto da classe sf::RenderWindow, representando a janela principal do game
	sf::Vector2i dimensaoJanela;	// Cria um objeto do tipo sf::Vector2i, ou seja, dois inteiros da dimensão da janela do game

	//*******************
	//*****Métodos*******
	//*******************

	//Renderiza o Tile Map da Pista Principal
	void renderMap();

	//Renderiza a GUI
	void renderGUI(int numPlayer);

	//Renderiza os projéteis ao mesmo tempo
	void renderProjeteis();

	//Renderiza o menu Pause in-game
	void renderPause();

	//Inicia o menu inicial e mantém o loop até que uma opção no seletor de personagens seja retornado
	void renderMenus();
	
	//Posiciona os carros na linha de chegada para iniciar a corrida
	void iniciarCorrida();

	//Checa se o carro ultrapassou a linha de chegada e atribui um valor ao Lap (volta)
	void checkLap();

	//Checa em tempo-real se o número de laps de um dos players atinge o número máximo, terminando a corrida
	void isRaceOver();

	//Checa por colisões com bordas das pistas ou obstáculos em tempo real
	void checkCollision(int numberPlayer);

	//Ativa os movimentos de ambos os players e checa suas teclas ativas em tempo real
	void ativarMovimentos();

	//Metodo principal para atualizar checagens de colisão, posicionamento da câmera, sprites e entradas do teclado
	void gameUpdate();

	//Ferramente para manipular tipos retângulares e auxiliar na delimitação de objetos colidíveis
	void ferramentaMapaConstrutor();

public:
	//*******************
	//*****Métodos*******
	//*******************
	//Construtor Padrão
	Game();

	//Método principal no main thread para rodar o game inteiro
	void rodarGame();
};