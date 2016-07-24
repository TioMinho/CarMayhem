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
	GUI playerGUI;						// Objeto GUI, representando a interface gráfica do usuário in-game
	sf::View raceCam;					// Objeto sf::View, representando a câmera do player durante a corrida
	sf::Clock respawnTimer, shotLoad;	// Objeto sf::Clock, representando o timer de respawn e o tempo de recarga
	int lapNumber;						// Variável do tipo inteiro que representa o número de voltas do jogador
	int maxHealth, actualHealth;		// Duas variáveis do tipo inteiro, representando o HP do player
	int maxAmmo, actualAmmo;			// Duas variáveis do tipo inteiro, representando a munição disponível do jogador
	Bullet projetil[10];				// Cria um vetor de 10 para objetos "Bullet"(projétil) que o carro pode atirar
	bool sentidoCircuito;				// Variável do tipo boolean que determinará se o carro está no sentido correto


public:
	//*******************
	//*****Métodos*******
	//*******************
	//Construtor Padrão
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

	//Método para ativar os movimentos do jogador
	void ativarMovimentos(int numberPlayer);

	//Método que centraliza a camera no carro do jogador
	void centralizarCamera();

	//Metodo para carregar as posições das câmeras do jogador
	void loadCamera(int numberPlayer, int larguraJanela, int alturaJanela);
	
	//Método para carregar a GUI do jogador
	void loadGUI();

	//Método para atualizar a GUI em tempo real
	void updateGUI();

	//Método para receber dano
	void dano(int valorDano);

	//Método que aumenta o número da volta
	void voltaCompleta();

	//Método para checar colisões com os limites da pista em tempo real
	void checarColisao(bool estaColidindo);

	//Método para checar colisões entre os carros
	void checarColisao(sf::Sprite enemySprite);

	//Método para checar se o carro está em cima de uma poça de lava, atribuindo um dano ao seu life
	void checarColisao(int danoLava);

	//Método para checar se o carro está em cima de uma poça de piche, retardando seu movimento por um fator inteiro
	void checarColisao(bool dentroGosma, int fator);

	//Método para checar se algum projétil atingiu o carro
	void checarColisao(sf::Sprite projetil, int valorDano);

	//Método para checar se o player ainda possui HP, explodindo o carro caso não possua
	void checarHP();

	//Método para checar se o player está no sentido contrário da corrida, atribuindo um dano gradual caso ele esteja
	void checarSentido();

	//Método para recarregar a munição
	void recarregarAmmo();

private:
	//Método para atualizar o movimento de cada bala individualmente no in-game
	void updateAmmo();

	//Método principal para disparar um projétil
	void atirar();
};

