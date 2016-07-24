#pragma once
class GUI{
private:
	//*********************
	//******Atributos******
	//*********************
	sf::RectangleShape lifeBar, ammoBar;

public:
	//*********************
	//*******Métodos*******
	//*********************

	//Construtor Padr
	GUI();

	/*GETTERS*/
	sf::RectangleShape getLifeBar();

	sf::RectangleShape getAmmoBar();

	//Esse método carrega a GUI com um valor máximo inicial tanto para o life como para
	//o valor de munição disponível no começo da corrida
	void loadGUI(int maxLife, int maxAmmo);

	//Esse método irá receber dentro do loop do game, em tempo real, os valores atuais
	//de HP e munição restantes, bem como a posição do centro do sprite do carro para
	//que a GUI acompanhe esse quando estiver se movendo
	void updateGUI(int positionX, int positionY, int actualHP, int actualAmmo);
};

