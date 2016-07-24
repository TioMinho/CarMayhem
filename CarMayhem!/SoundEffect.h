#pragma once
#include "Audio.h"
class SoundEffect : public Audio {
private:
	//*******************
	//****Atributos******
	//*******************
	//Atributo para criar 10 espa�os de mem�rias dispon�veis para armazenar efeitos sonoros por cada objeto
	sf::SoundBuffer bufferSE[10];


	//*******************
	//*****M�todos*******
	//*******************

	//Esse m�todo ir� carregar um determinado efeito sonoro, referenciado por um n�mero inteiro
	//a partir de um determinado diret�rio dentro da pasta "Resources/Sound Effects/"
	void loadSE(std::string diretorio, int numSE);

public:
	//*******************
	//*****M�todos*******
	//*******************
	//Construtor Padr�o
	SoundEffect();

	//M�todo para executar um efeito sonoro ao carreg�-lo atrav�s do m�todo "void loadSE"
	void playSE(std::string diretorio, int numMusica);
};