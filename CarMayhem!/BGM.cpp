#include <SFML\Audio.hpp>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "BGM.h"

//Construtor Padrão
BGM::BGM(){}

//Construtor Personalizado
BGM::BGM(std::string diretorioMusicas, int randomMax){
	//Cria um valor aleatório para caso a BGM esteja no modo aleatório
	srand(time(NULL));
	numMusica = rand() % randomMax;

	//Carrega música diretamente de um número
	loadMusic(diretorioMusicas, numMusica);

	//Inicializa o loop como verdadeiro para que o método seja executado apenas uma vez
	loopMusic = true;
}

/*SETTERS*/
void BGM::setMusic(std::string diretorioMusicas, int numero_Musica){
	loadMusic(diretorioMusicas, numero_Musica);
}

void BGM::setVolume(float volume){
	music.setVolume(volume);
}

//Método para carregar uma música
void BGM::loadMusic(std::string diretorio, int numMusica){
	//Variáveis para realizar a conversão de um número inteiro qualquer em uma string
	std::string folder = "Resources/BGM/", nomeMusica, extensao = ".ogg";
	std::stringstream conversor;

	//Conversão e atribuição à string principal
	conversor << numMusica;
	nomeMusica = conversor.str();

	//Cria a string completa
	folder += diretorio;
	nomeMusica += extensao;
	folder += nomeMusica;

	//Direciona o streaming do áudio para a string construída
	music.openFromFile(folder);
}

//Método para gerar reprodução aleatória
int BGM::modoAleatorio(int randomMax){
	srand(time(NULL));
	numMusica = rand() % randomMax;

	return numMusica;
}

//Método para reproduzir uma música
void BGM::playMusic(std::string diretorio, int numMusica){
	if (loopMusic){
		//Carrega a música, permite que ela seja repetida, executa o arquivo e fecha o loop
		loadMusic(diretorio, numMusica);
		music.setLoop(true);
		music.play();

		loopMusic = false;
	}
}

//Método para reproduzir uma música (+1 overload)
void BGM::playMusic(){
	if (loopMusic){
		music.setLoop(true);
		music.play();

		loopMusic = false;
	}
}

//Método que pára a reprodução
void BGM::stopMusic(){
	music.stop();

	loopMusic = true;
}
