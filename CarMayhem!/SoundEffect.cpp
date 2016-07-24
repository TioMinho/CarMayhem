#include <SFML\Audio.hpp>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "SoundEffect.h"

//Construtor Padrão
SoundEffect::SoundEffect(){}

//Método para carregar um soundbuffer e atribuí-lo à um objeto sf::Sound
void SoundEffect::loadSE(std::string diretorio, int numSE){
	//Variáveis para realizar a conversão de um número inteiro qualquer em uma string
	std::string folder = "Resources/Sound Effects/", nomeMusica, extensao = ".wav";
	std::stringstream conversor[2];

	//Conversão e atribuição à string principal
	conversor[numSE] << numSE;
	nomeMusica = conversor[numSE].str();

	//Cria a string completa
	folder += diretorio;
	nomeMusica += extensao;
	folder += nomeMusica;

	//Carrega o buffer de áudio com o arquivo direcionado pela string formada
	bufferSE[numSE].loadFromFile(folder);

	//Atribui ao efeito sonoro aquele buffer
	soundEffect.setBuffer(bufferSE[numSE]);
}

//Método para produzir um determinado efeito sonoro
void SoundEffect::playSE(std::string diretorio, int numMusica){
	loadSE(diretorio, numMusica);
	soundEffect.play();
}