#pragma once
class Audio{
protected:
	//*******************
	//****Atributos******
	//*******************
	bool loopMusic = true, loopSound = true;	//Loopers para evitar que a música seja repetida
	sf::Music music;							//Música
	sf::Sound soundEffect;						//Efeitos sonoros

	//*******************
	//*****Métodos*******
	//*******************
	//Construtor Padrão
	Audio();

	//Método principal para reproduzir um áudio de música
	virtual void playMusic();

	//Método principal para reproduzir um áudio de efeito sonoro
	virtual void playSE();
};
