#pragma once
#include "Audio.h"
class SoundEffect : public Audio {
private:
	//*******************
	//****Atributos******
	//*******************
	//Atributo para criar 10 espaços de memórias disponíveis para armazenar efeitos sonoros por cada objeto
	sf::SoundBuffer bufferSE[10];


	//*******************
	//*****Métodos*******
	//*******************

	//Esse método irá carregar um determinado efeito sonoro, referenciado por um número inteiro
	//a partir de um determinado diretório dentro da pasta "Resources/Sound Effects/"
	void loadSE(std::string diretorio, int numSE);

public:
	//*******************
	//*****Métodos*******
	//*******************
	//Construtor Padrão
	SoundEffect();

	//Método para executar um efeito sonoro ao carregá-lo através do método "void loadSE"
	void playSE(std::string diretorio, int numMusica);
};