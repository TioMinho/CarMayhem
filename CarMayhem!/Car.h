#pragma once
class Car{
private:
	//*******************
	//****Atributos******
	//*******************
	
	sf::Sprite carSprite;					// Sprite
	sf::Vector2i spriteFrame;				// Frames do Sprite
	sf::Texture modelo;						// Spritesheet 
	int width, height;						// Largura e Altura do Sprite
	float acceleration, deacceleration;		// Fator de acelera��o e frenagem
	int velocidadeMax;						// Velocidade M�xima
	sf::Vector2f actualSpeed;				// Vetores de velocidade num determinado instante
	sf::Vector2f topSpeed;					// Vetores de velocidade m�xima

	//Compensa��o de Framerate e Cronometragem
	float frameCounter = 0, switchFrame = 100, frameSpeed = 1000;
	sf::Clock clock;

	//*******************
	//*****M�todos*******
	//*******************

	//M�todo para movimentar o carro de acordo com a velocidade
	void mover();

	//M�todo para parar o carro
	void parar();

public:
	//*******************
	//*****M�todos*******
	//*******************
	//Construtor Padrao
	Car();

	//Construtor Personalizado//
	Car(std::string tipoModelo, int carWidth, int carHeight, float aceleracao, float frenagem, float velocidadeMax);

	/*SETTERS*/
	void setTexture(std::string tipoModelo);

	void setTextureRect(int rectLeft, int rectTop, int largura, int altura);

	void setAcceleration(float aceleracao);

	void setDeacceleration(float frenagem);

	void setTopSpeed(float maxVelocidade);

	void setPosition(float x, float y);

	void setSpriteframe(int x, int y);

	void setLargura(float x);

	void setAltura(float x);

	void zerarVelocidade();

	/*GETTERS*/
	sf::Sprite getSprite();

	int getActualHealth();

	int getMaxHealth();

	int getLargura();

	int getAltura();

	float getPositionX();

	float getPositionY();

	sf::Vector2f getTopspeed();

	sf::Vector2i Car::getSpriteframe();
	
	//M�todo para limitar a velocidade � um valor m�ximo
	void limitarVelocidade();

	//M�todo para rotacionar o carro no sentido hor�rio
	void rotacionarHorario();

	//M�todo para rotacionar o carro no sentido anti-hor�rio
	void rotacionarAntiHorario();

	//M�todo para acelerar
	void acelerar();

	//M�todo para Desacelerar
	void desacelerar();
	
	//Metodo para zerar velocidade quando o carro colidir
	void colidir();

	//M�todo para retardar o Movimento
	void retardarMovimento(float fator);

	//M�todo para explodir o carro quando o life se igualar a zero
	void explodir();
};