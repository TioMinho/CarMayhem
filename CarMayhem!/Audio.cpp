#include <SFML\Audio.hpp>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Audio.h"

//Construtor Padrão
Audio::Audio(){}

//Método para reproduzir uma música
void Audio::playMusic(){
	if (loopMusic){
		music.setLoop(true);
		music.play();

		loopMusic = false;
	}
}

//Método para reproduzir um efeito sonoro
void Audio::playSE(){
	if (loopSound){
		soundEffect.play();
		loopSound = false;
	}
	if (soundEffect.Stopped){
		loopSound = true;
	}
}