#pragma once
#include "Audio.h"
class BGM : public Audio {
private:
	//*******************
	//****Atributos******
	//*******************
	int numMusica;			//Vari�vel para determinar aleatoriedade das m�sicas

	//*******************
	//*****M�todos*******
	//*******************

	//M�todo para converter o n�mero aleat�rio de um valor inteiro para a string e
	//carregar um streaming de m�sica a partir dessa string no citado diret�rio
	void loadMusic(std::string diretorio, int numMusica);

public:
	//*******************
	//*****M�todos*******
	//*******************
	//Contrutor padr�o
	BGM();

	//Construtor personalizado
	BGM(std::string diretorioMusicas, int randomMax);

	/*SETTERS*/
	void setMusic(std::string diretorioMusicas, int numero_Musica);

	void setVolume(float volume);

	//Esse m�todo retorna, atrav�s de um "rand" alimentando por um "srand", um n�mero
	//aleat�rio din�mico, sendo usado como determinante para uma reprodu��o de a�dio
	//aleat�ria dentro de determinado diret�rio
	int modoAleatorio(int randomMax);

	//Esse m�todo ir� tocar a m�sica caso o "loopMusic" esteja "true" e, ap�s ser executada
	//definir� o "loopMusic" como false evitando, assim uma repeti��o indefinida desse �udio
	//no game loop
	void playMusic(std::string diretorio, int numMusica);

	//Overload do m�todo anterior, por�m sem os par�metros de entrada
	void playMusic();

	//Esse m�todo para a reprodu��o da m�sica e atribui "True" ao "loopMusic", permitindo
	//que a m�sica seja reproduzida novamente depois de parada
	void stopMusic();
};