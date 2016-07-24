#pragma once
class GUI{
private:
	//*********************
	//******Atributos******
	//*********************
	sf::RectangleShape lifeBar, ammoBar;

public:
	//*********************
	//*******M�todos*******
	//*********************

	//Construtor Padr
	GUI();

	/*GETTERS*/
	sf::RectangleShape getLifeBar();

	sf::RectangleShape getAmmoBar();

	//Esse m�todo carrega a GUI com um valor m�ximo inicial tanto para o life como para
	//o valor de muni��o dispon�vel no come�o da corrida
	void loadGUI(int maxLife, int maxAmmo);

	//Esse m�todo ir� receber dentro do loop do game, em tempo real, os valores atuais
	//de HP e muni��o restantes, bem como a posi��o do centro do sprite do carro para
	//que a GUI acompanhe esse quando estiver se movendo
	void updateGUI(int positionX, int positionY, int actualHP, int actualAmmo);
};

