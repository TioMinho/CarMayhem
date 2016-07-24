#include "SFML\Graphics.hpp"
#include "Bullet.h"

//Construtor Padr�o
Bullet::Bullet(){
	//Inicia a bala como n�o disparada
	isBalaDisparada = false;

	//Carrega a textura do sprite da bala
	sf::Texture balaText;
	
	balaText.loadFromFile("Resources/Sprites/bullet.png");

	//Atribui��o da textura ao sprite e inicializa��o da velocidade e posi��o
	balaSprite.setTexture(balaText);
	balaVelocidade = sf::Vector2f(0, 0);
	direcaoBala = sf::Vector2i(0, 0);
	balaSprite.setPosition(-1, -1);
}

/*GETTERS*/
sf::Sprite Bullet::getBalaSprite(){
	return balaSprite;
}

sf::Vector2f Bullet::getBalaVelocidade(){
	return balaVelocidade;
}

void Bullet::disparar(sf::Vector2f velocidadeCarro, sf::Vector2i direcaoCarro, 
					float positionX, float positionY, float larguraCarro, float alturaCarro){
	//Centraliza a bala no sprite do carro
	balaSprite.setPosition(positionX + (larguraCarro / 2.0), positionY + (alturaCarro / 2.0));

	//Atribui a dire��o da bala atrav�s da dire��o do carro no momento do disparo
	direcaoBala = direcaoCarro;

	//Atribui a velocidade(sentido) do carro � bala, multiplicando essa velocidade por 5
	balaVelocidade = 3.0f * velocidadeCarro;

	//Dispara a bala!
	isBalaDisparada = true;
}

//M�todo para update da velocidade da bala em tempo real
void Bullet::updateBullet(){
	if (isBalaDisparada){
		if (direcaoBala.y == 0){
			if (direcaoBala.x <= 6)
				balaSprite.move(-balaVelocidade.x, balaVelocidade.x);
			else
				balaSprite.move(-balaVelocidade.x, -balaVelocidade.y);
		}
		if (direcaoBala.y == 1){
			if (direcaoBala.x <= 6)
				balaSprite.move(balaVelocidade.x, -balaVelocidade.y);
			else
				balaSprite.move(balaVelocidade.x, balaVelocidade.y);
		}
	}
}