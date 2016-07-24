#include <SFML\Audio.hpp>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "BGM.h"

//Construtor Padr�o
BGM::BGM(){}

//Construtor Personalizado
BGM::BGM(std::string diretorioMusicas, int randomMax){
	//Cria um valor aleat�rio para caso a BGM esteja no modo aleat�rio
	srand(time(NULL));
	numMusica = rand() % randomMax;

	//Carrega m�sica diretamente de um n�mero
	loadMusic(diretorioMusicas, numMusica);

	//Inicializa o loop como verdadeiro para que o m�todo seja executado apenas uma vez
	loopMusic = true;
}

/*SETTERS*/
void BGM::setMusic(std::string diretorioMusicas, int numero_Musica){
	loadMusic(diretorioMusicas, numero_Musica);
}

void BGM::setVolume(float volume){
	music.setVolume(volume);
}

//M�todo para carregar uma m�sica
void BGM::loadMusic(std::string diretorio, int numMusica){
	//Vari�veis para realizar a convers�o de um n�mero inteiro qualquer em uma string
	std::string folder = "Resources/BGM/", nomeMusica, extensao = ".ogg";
	std::stringstream conversor;

	//Convers�o e atribui��o � string principal
	conversor << numMusica;
	nomeMusica = conversor.str();

	//Cria a string completa
	folder += diretorio;
	nomeMusica += extensao;
	folder += nomeMusica;

	//Direciona o streaming do �udio para a string constru�da
	music.openFromFile(folder);
}

//M�todo para gerar reprodu��o aleat�ria
int BGM::modoAleatorio(int randomMax){
	srand(time(NULL));
	numMusica = rand() % randomMax;

	return numMusica;
}

//M�todo para reproduzir uma m�sica
void BGM::playMusic(std::string diretorio, int numMusica){
	if (loopMusic){
		//Carrega a m�sica, permite que ela seja repetida, executa o arquivo e fecha o loop
		loadMusic(diretorio, numMusica);
		music.setLoop(true);
		music.play();

		loopMusic = false;
	}
}

//M�todo para reproduzir uma m�sica (+1 overload)
void BGM::playMusic(){
	if (loopMusic){
		music.setLoop(true);
		music.play();

		loopMusic = false;
	}
}

//M�todo que p�ra a reprodu��o
void BGM::stopMusic(){
	music.stop();

	loopMusic = true;
}
