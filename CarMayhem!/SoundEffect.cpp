#include <SFML\Audio.hpp>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "SoundEffect.h"

//Construtor Padr�o
SoundEffect::SoundEffect(){}

//M�todo para carregar um soundbuffer e atribu�-lo � um objeto sf::Sound
void SoundEffect::loadSE(std::string diretorio, int numSE){
	//Vari�veis para realizar a convers�o de um n�mero inteiro qualquer em uma string
	std::string folder = "Resources/Sound Effects/", nomeMusica, extensao = ".wav";
	std::stringstream conversor[2];

	//Convers�o e atribui��o � string principal
	conversor[numSE] << numSE;
	nomeMusica = conversor[numSE].str();

	//Cria a string completa
	folder += diretorio;
	nomeMusica += extensao;
	folder += nomeMusica;

	//Carrega o buffer de �udio com o arquivo direcionado pela string formada
	bufferSE[numSE].loadFromFile(folder);

	//Atribui ao efeito sonoro aquele buffer
	soundEffect.setBuffer(bufferSE[numSE]);
}

//M�todo para produzir um determinado efeito sonoro
void SoundEffect::playSE(std::string diretorio, int numMusica){
	loadSE(diretorio, numMusica);
	soundEffect.play();
}