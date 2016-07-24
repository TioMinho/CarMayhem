#pragma once
class Bullet{
private:
	//*******************
	//****Atributos******
	//*******************
	sf::Sprite balaSprite;
	sf::Vector2f balaVelocidade;
	sf::Vector2i direcaoBala;
	bool isBalaDisparada;

public:
	//*******************
	//*****Métodos*******
	//*******************
	//Construtor Padrão
	Bullet();

	/*GETTERS*/
	sf::Sprite getBalaSprite();

	sf::Vector2i getDirecaoBala();

	sf::Vector2f getBalaVelocidade();

	//Metodo para mirar a disparar a bala
	void Bullet::disparar(sf::Vector2f velocidadeCarro, sf::Vector2i direcaoCarro, float positionX, float positionY, float larguraCarro, float alturaCarro);

	//Método principal para movimentar a bala quando a mesma for disparada
	void updateBullet();
};

