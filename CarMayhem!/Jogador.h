#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "Car.h"
#include "Bullet.h"
#include "GUI.h"
#include "Collision.h"

class Jogador{
private:
	//*******************
	//****Atributos******
	//*******************

	Car carPlayer;						// Objeto Car, representando o carro pertencente ao jogador
	GUI playerGUI;						// Objeto GUI, representando a interface gr�fica do usu�rio in-game
	sf::View raceCam;					// Objeto sf::View, representando a c�mera do player durante a corrida
	sf::Clock respawnTimer, shotLoad;	// Objeto sf::Clock, representando o timer de respawn e o tempo de recarga
	int lapNumber;						// Vari�vel do tipo inteiro que representa o n�mero de voltas do jogador
	int maxHealth, actualHealth;		// Duas vari�veis do tipo inteiro, representando o HP do player
	int maxAmmo, actualAmmo;			// Duas vari�veis do tipo inteiro, representando a muni��o dispon�vel do jogador
	Bullet projetil[10];				// Cria um vetor de 10 para objetos "Bullet"(proj�til) que o carro pode atirar
	bool sentidoCircuito;				// Vari�vel do tipo boolean que determinar� se o carro est� no sentido correto


public:
	//*******************
	//*****M�todos*******
	//*******************
	//Construtor Padr�o
	Jogador();

	/*SETTERS*/
	void setPosition(float x, float y);

	void setLaps(int numeroVoltas);

	void setCar(std::string carSprite, float largura, float altura, float aceleracao, float frenagem, float velocidadeMax, int lifeMax, int ammoMax);

	void setSentido(bool isSentidoCorreto);

	/*GETTERS*/
	sf::Sprite getSprite();

	sf::Vector2i getSpriteframe();

	sf::RectangleShape getLifeBar();

	sf::RectangleShape getAmmoBar();

	int getLap();

	sf::View getCamera();

	sf::Sprite getProjetil(int numProjetil);

	//M�todo para ativar os movimentos do jogador
	void ativarMovimentos(int numberPlayer);

	//M�todo que centraliza a camera no carro do jogador
	void centralizarCamera();

	//Metodo para carregar as posi��es das c�meras do jogador
	void loadCamera(int numberPlayer, int larguraJanela, int alturaJanela);
	
	//M�todo para carregar a GUI do jogador
	void loadGUI();

	//M�todo para atualizar a GUI em tempo real
	void updateGUI();

	//M�todo para receber dano
	void dano(int valorDano);

	//M�todo que aumenta o n�mero da volta
	void voltaCompleta();

	//M�todo para checar colis�es com os limites da pista em tempo real
	void checarColisao(bool estaColidindo);

	//M�todo para checar colis�es entre os carros
	void checarColisao(sf::Sprite enemySprite);

	//M�todo para checar se o carro est� em cima de uma po�a de lava, atribuindo um dano ao seu life
	void checarColisao(int danoLava);

	//M�todo para checar se o carro est� em cima de uma po�a de piche, retardando seu movimento por um fator inteiro
	void checarColisao(bool dentroGosma, int fator);

	//M�todo para checar se algum proj�til atingiu o carro
	void checarColisao(sf::Sprite projetil, int valorDano);

	//M�todo para checar se o player ainda possui HP, explodindo o carro caso n�o possua
	void checarHP();

	//M�todo para checar se o player est� no sentido contr�rio da corrida, atribuindo um dano gradual caso ele esteja
	void checarSentido();

	//M�todo para recarregar a muni��o
	void recarregarAmmo();

private:
	//M�todo para atualizar o movimento de cada bala individualmente no in-game
	void updateAmmo();

	//M�todo principal para disparar um proj�til
	void atirar();
};

