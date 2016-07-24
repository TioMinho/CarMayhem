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
	float acceleration, deacceleration;		// Fator de aceleração e frenagem
	int velocidadeMax;						// Velocidade Máxima
	sf::Vector2f actualSpeed;				// Vetores de velocidade num determinado instante
	sf::Vector2f topSpeed;					// Vetores de velocidade máxima

	//Compensação de Framerate e Cronometragem
	float frameCounter = 0, switchFrame = 100, frameSpeed = 1000;
	sf::Clock clock;

	//*******************
	//*****Métodos*******
	//*******************

	//Método para movimentar o carro de acordo com a velocidade
	void mover();

	//Método para parar o carro
	void parar();

public:
	//*******************
	//*****Métodos*******
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
	
	//Método para limitar a velocidade à um valor máximo
	void limitarVelocidade();

	//Método para rotacionar o carro no sentido horário
	void rotacionarHorario();

	//Método para rotacionar o carro no sentido anti-horário
	void rotacionarAntiHorario();

	//Método para acelerar
	void acelerar();

	//Método para Desacelerar
	void desacelerar();
	
	//Metodo para zerar velocidade quando o carro colidir
	void colidir();

	//Método para retardar o Movimento
	void retardarMovimento(float fator);

	//Método para explodir o carro quando o life se igualar a zero
	void explodir();
};