#pragma once
#include "Audio.h"
class BGM : public Audio {
private:
	//*******************
	//****Atributos******
	//*******************
	int numMusica;			//Variável para determinar aleatoriedade das músicas

	//*******************
	//*****Métodos*******
	//*******************

	//Método para converter o número aleatório de um valor inteiro para a string e
	//carregar um streaming de música a partir dessa string no citado diretório
	void loadMusic(std::string diretorio, int numMusica);

public:
	//*******************
	//*****Métodos*******
	//*******************
	//Contrutor padrão
	BGM();

	//Construtor personalizado
	BGM(std::string diretorioMusicas, int randomMax);

	/*SETTERS*/
	void setMusic(std::string diretorioMusicas, int numero_Musica);

	void setVolume(float volume);

	//Esse método retorna, através de um "rand" alimentando por um "srand", um número
	//aleatório dinâmico, sendo usado como determinante para uma reprodução de aúdio
	//aleatória dentro de determinado diretório
	int modoAleatorio(int randomMax);

	//Esse método irá tocar a música caso o "loopMusic" esteja "true" e, após ser executada
	//definirá o "loopMusic" como false evitando, assim uma repetição indefinida desse áudio
	//no game loop
	void playMusic(std::string diretorio, int numMusica);

	//Overload do método anterior, porém sem os parâmetros de entrada
	void playMusic();

	//Esse método para a reprodução da música e atribui "True" ao "loopMusic", permitindo
	//que a música seja reproduzida novamente depois de parada
	void stopMusic();
};