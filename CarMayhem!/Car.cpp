#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include "Car.h"

//Construtor Padr�o
Car::Car(){}

//Construtor Personalizado
Car::Car(std::string tipoModelo, int carWidth, int carHeight, float aceleracao, float frenagem, float velocidadeMaxima){
	//Construindo Spritesheet
	if (!modelo.loadFromFile(tipoModelo))
		std::cout << "A imagem nao pode ser carregada" << std::endl;
	carSprite.setTexture(modelo);

	//Largura e Comprimento do Sprite
	width = carWidth;
	height = carHeight;

	//Atribui os valres de acerela��o e frenagem
	acceleration = aceleracao;
	deacceleration = frenagem;

	//Atribui o fator que limita a velocidade m�xima do carro
	velocidadeMax = velocidadeMaxima;

	//Posi��o Inicial do Spriteframe e recorte de Textura
	spriteFrame.x = 6;
	spriteFrame.y = 0;

	//Velocidade Inicial
	actualSpeed.x = 0;
	actualSpeed.y = 0;
}

/*SETTERS*/
void Car::setTexture(std::string tipoModelo){
	modelo.loadFromFile(tipoModelo);
	carSprite.setTexture(modelo);
	carSprite.setTextureRect(sf::IntRect(spriteFrame.x * width, 0, width, height));
}

void Car::setTextureRect(int rectLeft, int rectTop, int largura, int altura){
	carSprite.setTextureRect(sf::IntRect(rectLeft, rectTop, largura, altura));
}

void Car::setAcceleration(float aceleracao){
	acceleration = aceleracao;
}

void Car::setDeacceleration(float frenagem){
	deacceleration = frenagem;
}

void Car::setTopSpeed(float maxVelocidade){
	velocidadeMax = maxVelocidade;
}

void Car::setPosition(float x, float y){
	carSprite.setPosition(x, y);
}

void Car::setSpriteframe(int x, int y){
	spriteFrame.x = x;
	spriteFrame.y = y;
}

void Car::setLargura(float x){
	width = x;
}

void Car::setAltura(float x){
	height = x;
}

void Car::zerarVelocidade(){
	actualSpeed.x = 0;
	actualSpeed.y = 0;
}

/*GETTERS*/
sf::Sprite Car::getSprite(){
	return carSprite;
}

int Car::getLargura(){
	return width;
}

int Car::getAltura(){
	return height;
}

float Car::getPositionX(){
	return carSprite.getPosition().x;
}

float Car::getPositionY(){
	return carSprite.getPosition().y;
}

sf::Vector2f Car::getTopspeed(){
	return topSpeed;
}

sf::Vector2i Car::getSpriteframe(){
	return spriteFrame;
}


//M�todo para movimentar o carro de acordo com a velocidade
void Car::mover(){
	if (spriteFrame.y == 0){
		if (spriteFrame.x <= 6)
			carSprite.move(-actualSpeed.x, actualSpeed.y);
		else
			carSprite.move(-actualSpeed.x, -actualSpeed.y);
	}
	if (spriteFrame.y == 1){
		if (spriteFrame.x <= 6)
			carSprite.move(actualSpeed.x, -actualSpeed.y);
		else
			carSprite.move(actualSpeed.x, actualSpeed.y);
	}
}

//M�todo para parar o carro
void Car::parar(){
	actualSpeed.x = 0;
	actualSpeed.y = 0;
}

//Metodo de resposta a uma colis�o, impedindo que o carro se mova na dire��o do obst�culo
void Car::colidir(){
	if (spriteFrame.y == 0){
		if (spriteFrame.x <= 6)
			carSprite.move(actualSpeed.x, -actualSpeed.y);
		else
			carSprite.move(actualSpeed.x, actualSpeed.y);
	}
	if (spriteFrame.y == 1){
		if (spriteFrame.x <= 6)
			carSprite.move(-actualSpeed.x, actualSpeed.y);
		else
			carSprite.move(-actualSpeed.x, -actualSpeed.y);
	}
}

//M�todo para explodir o carro quando o life se igualar a zero
void Car::explodir(){
		//Para o Sprite do carro
		parar();

		//Anima��o de explos�o
		carSprite.setTextureRect(sf::IntRect(48, 2 * height, 48, 48));
}

//M�todo para retardar o Movimento
void Car::retardarMovimento(float fator){
	if (spriteFrame.y == 0){
		if (spriteFrame.x <= 6)
			carSprite.move(actualSpeed.x / fator, -actualSpeed.y / fator);
		else
			carSprite.move(actualSpeed.x / fator, actualSpeed.y / fator);
	}
	if (spriteFrame.y == 1){
		if (spriteFrame.x <= 6)
			carSprite.move(-actualSpeed.x / fator, actualSpeed.y / fator);
		else
			carSprite.move(-actualSpeed.x / fator, -actualSpeed.y / fator);
	}
}

//M�todo para limitar a velocidade � um valor m�ximo
void Car::limitarVelocidade(){
	if (spriteFrame.x <= 6){
		topSpeed.x = (0.42 * spriteFrame.x);
		topSpeed.y = 2.52 - (0.42 * spriteFrame.x);
	}
	else{
		topSpeed.x = 2.52 - (0.42 * (spriteFrame.x - 6));
		topSpeed.y = (0.42 * (spriteFrame.x - 6));
	}

	topSpeed.x *= velocidadeMax;
	topSpeed.y *= velocidadeMax;
}

//M�todo para rotacionar o carro no sentido hor�rio
void Car::rotacionarHorario(){
	frameCounter += frameSpeed*clock.restart().asSeconds();
	if (frameCounter >= switchFrame){
		frameCounter = 0;

		if (spriteFrame.y == 0){
			if (spriteFrame.x >= 0 && spriteFrame.x < 12)
				spriteFrame.x++;
			else if (spriteFrame.x == 12){
				spriteFrame.y++;
				spriteFrame.x = 1;
			}
		}
		else if (spriteFrame.y == 1){
			if (spriteFrame.x >= 0 && spriteFrame.x < 12)
				spriteFrame.x++;
			else if (spriteFrame.x == 12){
				spriteFrame.y--;
				spriteFrame.x = 1;
			}
		}
	}
	carSprite.setTextureRect(sf::IntRect(spriteFrame.x * width, spriteFrame.y * height, width, height));
}

//M�todo para rotacionar o carro no sentido anti-hor�rio
void Car::rotacionarAntiHorario(){
	frameCounter += frameSpeed*clock.restart().asSeconds();
	if (frameCounter >= switchFrame){
		frameCounter = 0;

		if (spriteFrame.y == 0){
			if (spriteFrame.x > 0 && spriteFrame.x <= 12)
				spriteFrame.x--;
			else if (spriteFrame.x == 0){
				spriteFrame.y++;
				spriteFrame.x = 11;
			}
		}
		else if (spriteFrame.y == 1){
			if (spriteFrame.x > 0 && spriteFrame.x <= 12)
				spriteFrame.x--;
			else if (spriteFrame.x == 0){
				spriteFrame.y--;
				spriteFrame.x = 11;
			}
		}
	}

	carSprite.setTextureRect(sf::IntRect(spriteFrame.x * width, spriteFrame.y * height, width, height));
}

//M�todo para acelerar
void Car::acelerar(){
	//Para o eixo X
	//Verifica se a velocidade atual � menor que a m�xima
	if (actualSpeed.x < topSpeed.x)
		// Acresce a velocidade sobre uma taxa constante
		actualSpeed.x += topSpeed.x / acceleration;
	else if (actualSpeed.x >= topSpeed.x)
		// Delimita a velocidade m�xima poss�vel
		actualSpeed.x = topSpeed.x;
	
	//Para o eixo Y
	//Verifica se a velocidade atual � menor que a m�xima
	if (actualSpeed.y < topSpeed.y)
		// Acresce a velocidade sobre uma taxa constante
		actualSpeed.y += topSpeed.y / acceleration;
	else if (actualSpeed.y >= topSpeed.y)
		// Delimita a velocidade m�xima poss�vel
		actualSpeed.y = topSpeed.y;

	mover();
}

//M�todo para Desacelerar
void Car::desacelerar(){
	if (actualSpeed.x > 0)
		actualSpeed.x -= (actualSpeed.x / deacceleration);
	else
		actualSpeed.x = 0;
	if (actualSpeed.y > 0)
		actualSpeed.y -= (actualSpeed.y / deacceleration);
	else
		actualSpeed.y = 0;

	mover();
}
