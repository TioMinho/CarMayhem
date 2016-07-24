#include <SFML\Audio.hpp>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Audio.h"

//Construtor Padr�o
Audio::Audio(){}

//M�todo para reproduzir uma m�sica
void Audio::playMusic(){
	if (loopMusic){
		music.setLoop(true);
		music.play();

		loopMusic = false;
	}
}

//M�todo para reproduzir um efeito sonoro
void Audio::playSE(){
	if (loopSound){
		soundEffect.play();
		loopSound = false;
	}
	if (soundEffect.Stopped){
		loopSound = true;
	}
}