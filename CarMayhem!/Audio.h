#pragma once
class Audio{
protected:
	//*******************
	//****Atributos******
	//*******************
	bool loopMusic = true, loopSound = true;	//Loopers para evitar que a m�sica seja repetida
	sf::Music music;							//M�sica
	sf::Sound soundEffect;						//Efeitos sonoros

	//*******************
	//*****M�todos*******
	//*******************
	//Construtor Padr�o
	Audio();

	//M�todo principal para reproduzir um �udio de m�sica
	virtual void playMusic();

	//M�todo principal para reproduzir um �udio de efeito sonoro
	virtual void playSE();
};
