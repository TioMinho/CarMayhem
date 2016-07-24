#include "Game.h"

//Construtor Padrão
Game::Game(){
	//Inicialização da Janela Principal
	dimensaoJanela = sf::Vector2i(1733, 768);
	gameWindow.create(sf::VideoMode(dimensaoJanela.x, dimensaoJanela.y), "CarMayhem!", sf::Style::Default);

	//Inicialização do Circuito Principal
	mapaPista.LoadMap("tileMap.txt");
	mapaPista.estruturarMapa();

	//Inicialização das Câmeras Genéricas
	cameraGenerica.reset(sf::FloatRect(1, 1, dimensaoJanela.x, dimensaoJanela.y));

	//Inicialização de cada Jogador
	//Player 1
	player[0].loadCamera(0, dimensaoJanela.x, dimensaoJanela.y);
	//Player 2
	player[1].loadCamera(1, dimensaoJanela.x, dimensaoJanela.y);

	//Rectangulo para construtor do mapa
	rectTeste.setFillColor(sf::Color::White);
}

//Método para rodar o game
void Game::rodarGame(){
	while (gameWindow.isOpen()){
		sf::Event mainEvent;		// Objeto da classe sf::Event, para manipular eventos
		/*EVENT LOOP*/
		while (gameWindow.pollEvent(mainEvent)){
			switch (mainEvent.type){
			case sf::Event::Closed:
				gameWindow.close();
				break;
			}
		}
		/*GAME LOOP*/
		/*
		while (finishRace)
			renderMenus();

		while (!finishRace)
			gameUpdate();
*/
		//Testes//
		ferramentaMapaConstrutor();
	}
}

//Método principal para atualização do game em tempo real
void Game::gameUpdate(){
	//Limite de Frame Rate
	gameWindow.setFramerateLimit(60);

	//Checa se algum dos players completou as 3 voltas
	isRaceOver();

	//Verifica se a tecla ESC é pressionada, abrindo o menuPause
	renderPause();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		menuPause.abrirMenu();

	//Toca a música que será reproduzida durante a corrida
	raceBGM.playMusic();
	raceBGM.setVolume(100);

	//Ativa os métodos de entrada de keyboard para os controles de ambos os players
	player[0].ativarMovimentos(0);
	player[1].ativarMovimentos(1);

	//Checa todas as colisões possíveis dentro da partida para cada Player
	checkCollision(0);
	checkCollision(1);

	//Checa se os players estão no sentido correto da pista (caso eles percorram ao contrário), seus
	//carros explodirão
	player[0].checarSentido();
	player[1].checarSentido();

	//Checa durante a partida quando a linha de chegada é ultrapassada
	checkLap();
	
	//Centralizando cada câmera em seu respectivo player
	player[0].centralizarCamera();
	player[1].centralizarCamera();

	//Renderizações na tela do Player1
	gameWindow.setView(player[0].getCamera());
	renderMap();
	gameWindow.draw(player[0].getSprite());
	gameWindow.draw(player[1].getSprite());
	renderProjeteis();
	renderGUI(0);
	
	//Renderizações na tela do Player 2
	gameWindow.setView(player[1].getCamera());
	renderMap();
	gameWindow.draw(player[1].getSprite());
	gameWindow.draw(player[0].getSprite());
	renderProjeteis();
	renderGUI(1);

	gameWindow.display();
	gameWindow.clear();
}

//Método principal para checar colisões em tempo real
void Game::checkCollision(int numberPlayer){
	//Checa colisão do Player com as paredes da pista
	player[numberPlayer].checarColisao(mapaPista.checkCollision(player[numberPlayer].getSprite()));

	//Checa colisão do Player com os obstáculos lava
	player[numberPlayer].checarColisao(mapaPista.checkLava(player[numberPlayer].getSprite()));

	//Checa colisão do Player com os obstáculos gosma
	player[numberPlayer].checarColisao(mapaPista.checkGosma(player[numberPlayer].getSprite()), 2.0f);

	//Checa colisão de um projétil do outro player com o player ao qual o método foi parametrado
	int enemyPlayer = 0;
	if (numberPlayer == 0)
		enemyPlayer = 1;

	player[numberPlayer].checarColisao(player[enemyPlayer].getProjetil(0), 20);
	player[numberPlayer].checarColisao(player[enemyPlayer].getProjetil(1), 20);
	player[numberPlayer].checarColisao(player[enemyPlayer].getProjetil(2), 20);
	player[numberPlayer].checarColisao(player[enemyPlayer].getProjetil(3), 20);
	player[numberPlayer].checarColisao(player[enemyPlayer].getProjetil(4), 20);
	player[numberPlayer].checarColisao(player[enemyPlayer].getProjetil(5), 20);
	player[numberPlayer].checarColisao(player[enemyPlayer].getProjetil(6), 20);
	player[numberPlayer].checarColisao(player[enemyPlayer].getProjetil(7), 20);
	player[numberPlayer].checarColisao(player[enemyPlayer].getProjetil(8), 20);
	player[numberPlayer].checarColisao(player[enemyPlayer].getProjetil(9), 20);

	//Checa colisão entre os players
	player[numberPlayer].checarColisao(player[enemyPlayer].getSprite());

	//Checa a quantidade de HP restante do player
	player[numberPlayer].checarHP();
}

//Método para renderizar e interagir com os menus iniciais e finais (Menus off-game)
void Game::renderMenus(){
	//Para a música da partida e inicia a música do menu, no modo aleatório
	raceBGM.stopMusic();
	menuBGM.playMusic("Menu/", menuBGM.modoAleatorio(4));

	//Limita o framerate durante as telas de seleção, facilitando a escolha
	gameWindow.setFramerateLimit(10);
	//Atribui a câmera genérica à visualização dos menus
	gameWindow.setView(cameraGenerica);

	//Menu Inicial
	while (menuInicial.isMenuOpen()){

		menuInicial.ativarSelecao();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			menuSE.playSE("Menu/", 0);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
			menuSE.playSE("Menu/", 1);

			switch (menuInicial.getOption()){
			case 1: // Abre o primeiro menu seletor
				menuInicial.fecharMenu();
				menuSelecao[0].abrirMenu();
				break;
			case 2: // Abre o menu créditos
				menuInicial.fecharMenu();
				menuCreditos.abrirMenu();
				break;
			case 3: // Fecha a janela do game
				menuInicial.fecharMenu();
				gameWindow.close();
				break;
			}
		}

		//Renderiza o menu
		gameWindow.draw(menuInicial.menuDraw());
		gameWindow.draw(menuInicial.getSelecao());

		gameWindow.display();
		gameWindow.clear();
	}

	//Menu de Créditos
	while (menuCreditos.isMenuOpen()){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) 
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up) 
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			menuSE.playSE("Menu/", 0);

		//Volta ao menu principal
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
			menuSE.playSE("Menu/", 1);

			menuInicial.abrirMenu(); 
			menuCreditos.fecharMenu();
		}

		//Renderiza o menu
		gameWindow.draw(menuCreditos.menuDraw());

		gameWindow.display();
		gameWindow.clear();
	}

	//Primeiro menu de seleção
	while (menuSelecao[0].isMenuOpen()){
		menuSelecao[0].ativarSelecao();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			menuSE.playSE("Menu/", 0);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
			menuSE.playSE("Menu/", 1);

			switch (menuSelecao[0].getOption()){
			case 1: // Atribui o personagem The Illuminatian ao player 1
				player[0].setCar("Resources/Sprites/theIlluminatian.png", 47, 38, 150, 30, 3, 150, 3);
				raceBGM.setMusic("The Illuminatian/", raceBGM.modoAleatorio(5));
				menuSelecao[0].fecharMenu();
				menuSelecao[1].abrirMenu();
				break;
			case 2: // Atribui o personagem Little Jack ao player 1
				player[0].setCar("Resources/Sprites/littleJack.png", 46, 31, 100, 20, 2, 250, 5);
				raceBGM.setMusic("Little Jack/", raceBGM.modoAleatorio(5));
				menuSelecao[0].fecharMenu();
				menuSelecao[1].abrirMenu();
				break;
			case 3: // Atribui o personagem Liese Vicious ao player 1
				player[0].setCar("Resources/Sprites/lieseVicious.png", 47, 27, 200, 10, 2, 400, 10);
				raceBGM.setMusic("Liese Vicious/", raceBGM.modoAleatorio(5));
				menuSelecao[0].fecharMenu();
				menuSelecao[1].abrirMenu();
				break;
			}
		}

		//Renderiza o menu
		gameWindow.draw(menuSelecao[0].menuDraw());
		gameWindow.draw(menuSelecao[0].getNomeSelecao());
		gameWindow.draw(menuSelecao[0].getAcelleration());
		gameWindow.draw(menuSelecao[0].getTopSpeed());
		gameWindow.draw(menuSelecao[0].getAmmo());
		gameWindow.draw(menuSelecao[0].getHealth());
		gameWindow.draw(menuSelecao[0].getTracklist());
		gameWindow.draw(menuSelecao[0].getMostruario());

		gameWindow.display();
		gameWindow.clear();
	}

	// Menu seletor do player 2
	while (menuSelecao[1].isMenuOpen()){

		menuSelecao[1].ativarSelecao();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			menuSE.playSE("Menu/", 0);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
			menuSE.playSE("Menu/", 1);

			switch (menuSelecao[1].getOption()){
			case 1: // Atribui o personagem The Illuminatian ao player 2
				player[1].setCar("Resources/Sprites/theIlluminatian.png", 47, 38, 150, 30, 3, 150, 3);
				iniciarCorrida();
				menuSelecao[1].fecharMenu();
				break;
			case 2: // Atribui o personagem Little Jack ao player 2
				player[1].setCar("Resources/Sprites/littleJack.png", 46, 31, 100, 20, 2, 250, 5);
				iniciarCorrida();
				menuSelecao[1].fecharMenu();
				break;
			case 3: // Atribui o personagem Liese Vicious ao player 2
				player[1].setCar("Resources/Sprites/lieseVicious.png", 47, 27, 200, 10, 2, 400, 10);
				iniciarCorrida();
				menuSelecao[1].fecharMenu();
				break;
			}
		}

		//Renderiza o menu
		gameWindow.draw(menuSelecao[1].menuDraw());
		gameWindow.draw(menuSelecao[1].getNomeSelecao());
		gameWindow.draw(menuSelecao[1].getAcelleration());
		gameWindow.draw(menuSelecao[1].getTopSpeed());
		gameWindow.draw(menuSelecao[1].getAmmo());
		gameWindow.draw(menuSelecao[1].getHealth());
		gameWindow.draw(menuSelecao[1].getTracklist());
		gameWindow.draw(menuSelecao[1].getMostruario());

		gameWindow.display();
		gameWindow.clear();
	}

	// Menu de fim de jogo, exibido quando um dos players completa as 3 voltas
	while (endRaceMenu.isMenuOpen()){

		endRaceMenu.ativarSelecao();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			menuSE.playSE("Menu/", 0);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
			menuSE.playSE("Menu/", 1);

			switch (endRaceMenu.getOption()){
			case 1: // Volta ao menu inicial
				endRaceMenu.fecharMenu();
				menuInicial.abrirMenu();
				break;
			case 2: // Fecha o game
				endRaceMenu.fecharMenu();
				gameWindow.close();
				break;
			}
		}

		// Renderizações
		gameWindow.draw(endRaceMenu.menuDraw());
		gameWindow.draw(endRaceMenu.getWinnerName());
		gameWindow.draw(endRaceMenu.getOptionPlay());
		gameWindow.draw(endRaceMenu.getOptionQuit());

		gameWindow.display();
		gameWindow.clear();
	}

	// Para-se a música quando nenhum menu estiver aberto
	menuBGM.stopMusic();
}

//Método para renderizar o Tilemap do Circuito
void Game::renderMap(){
	for (int k = 0; k < mapaPista.getSize(); k++){
		for (int j = 0; j < mapaPista.getSize(k); j++){
			if (mapaPista.getTileNumberX(k, j) != -1 && mapaPista.getTileNumberY(k, j) != -1){
				mapaPista.setTilePosition(j * 370, k * 405);
				mapaPista.setTileRectangle(mapaPista.getTileNumberX(k, j) * 370, mapaPista.getTileNumberY(k, j) * 405, 370, 405);
				gameWindow.draw(mapaPista.getTile());
			}
		}
	}
}

//Método para renderizar o menu pause (Menu in-game)
void Game::renderPause(){
	while (menuPause.isMenuOpen()){
		menuPause.ativarSelecao();

		raceBGM.setVolume(10);

		gameWindow.setFramerateLimit(10);
		gameWindow.setView(cameraGenerica);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			menuSE.playSE("Menu/", 0);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
			menuSE.playSE("Menu/", 1);

			switch (menuPause.getOption()){
			case 1:
				menuPause.fecharMenu();
				break;
			case 2:
				menuPause.fecharMenu();
				finishRace = true;
				menuInicial.abrirMenu();
				break;
			case 3:
				menuPause.fecharMenu();
				gameWindow.close();
				break;
			}
		}

		gameWindow.draw(menuPause.menuDraw());
		gameWindow.draw(menuPause.getOptionContinue());
		gameWindow.draw(menuPause.getOptionMenu());
		gameWindow.draw(menuPause.getOptionQuit());

		gameWindow.display();
		gameWindow.clear();
	}
}

//Método para verificar ultrapassagens da linha de chegada
void Game::checkLap(){
	//Player 1
	if (timer[0].getElapsedTime().asSeconds() >= 30 && sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		if (Collision::BoundingBoxTest(player[0].getSprite(), mapaPista.getFinishLine())){
			if (player[0].getSpriteframe().x >= 6 && player[0].getSpriteframe().y == 0){
				player[0].voltaCompleta();
				player[0].recarregarAmmo();
				timer[0].restart();
				player[0].setSentido(true);
			}
		}
	}
	if (Collision::BoundingBoxTest(player[0].getSprite(), mapaPista.getFinishLine()))
		if (player[0].getSpriteframe().x >= 6 && player[0].getSpriteframe().y == 1)
			player[0].setSentido(false);

	//Player 2
	if (timer[1].getElapsedTime().asSeconds() >= 30 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		if (Collision::BoundingBoxTest(player[1].getSprite(), mapaPista.getFinishLine())){
			if (player[1].getSpriteframe().x >= 6 && player[1].getSpriteframe().y == 0){
				player[1].voltaCompleta();
				player[1].recarregarAmmo();
				timer[1].restart();
				player[1].setSentido(true);
			}
		}
	}
	if (Collision::BoundingBoxTest(player[1].getSprite(), mapaPista.getFinishLine()))
		if (player[1].getSpriteframe().x >= 6 && player[1].getSpriteframe().y == 1)
			player[1].setSentido(false);
}

//Método para verificar se um dos players atingiu a meta de voltas
void Game::isRaceOver(){
	if (player[0].getLap() == 3){
		endRaceMenu.setWinnerName("Player 1");
		endRaceMenu.abrirMenu();
		finishRace = true;
	}
	else if (player[1].getLap() == 3){
		endRaceMenu.setWinnerName("Player 2");
		endRaceMenu.abrirMenu();
		finishRace = true;
	}
	else
		finishRace = false;
}

//Método para iniciar a corrida
void Game::iniciarCorrida(){
	//Atribui false ao boolean que determina o fim da corrida
	finishRace = false;

	//Player 1
	player[0].loadGUI();
	player[0].setPosition(3230, 1632);
	player[0].setLaps(0);
	
	//Player 2
	player[1].loadGUI();
	player[1].setPosition(3200, 1674);
	player[1].setLaps(0);
}

//Método para renderizar a interface gráfica in-game do jogador
void Game::renderGUI(int numPlayer){
	player[numPlayer].updateGUI();

	gameWindow.draw(player[numPlayer].getLifeBar());
	gameWindow.draw(player[numPlayer].getAmmoBar());
}

//Método para renderizar os projéteis em tempo real
void Game::renderProjeteis(){
	//Player 1
	gameWindow.draw(player[0].getProjetil(0));
	gameWindow.draw(player[0].getProjetil(1));
	gameWindow.draw(player[0].getProjetil(2));
	gameWindow.draw(player[0].getProjetil(3));
	gameWindow.draw(player[0].getProjetil(4));
	gameWindow.draw(player[0].getProjetil(5));
	gameWindow.draw(player[0].getProjetil(6));
	gameWindow.draw(player[0].getProjetil(7));
	gameWindow.draw(player[0].getProjetil(8));
	gameWindow.draw(player[0].getProjetil(9));

	//Player 2
	gameWindow.draw(player[1].getProjetil(0));
	gameWindow.draw(player[1].getProjetil(1));
	gameWindow.draw(player[1].getProjetil(2));
	gameWindow.draw(player[1].getProjetil(3));
	gameWindow.draw(player[1].getProjetil(4));
	gameWindow.draw(player[1].getProjetil(5));
	gameWindow.draw(player[1].getProjetil(6));
	gameWindow.draw(player[1].getProjetil(7));
	gameWindow.draw(player[1].getProjetil(8));
	gameWindow.draw(player[1].getProjetil(9));
}

//Método ferramenta para auxiliar a delimitação das pistas de colisão
void Game::ferramentaMapaConstrutor(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		cameraGenerica.move(0, -5);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		cameraGenerica.move(0, 5);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		cameraGenerica.move(-5, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		cameraGenerica.move(5, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		rectTeste.move(0, -2);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		rectTeste.move(0, 2);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		rectTeste.move(-2, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		rectTeste.move(2, 0);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		x -= 0.1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		x += 0.1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
		y += 0.1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
		y -= 0.1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
		z += 0.1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
		z -= 0.1;

	rectTeste.setRotation(x);
	rectTeste.setSize(sf::Vector2f(y, z));

	std::cout << "Rotacao = " << rectTeste.getRotation() << " - Posicao: X = " << rectTeste.getPosition().x
		<< ", Y = " << rectTeste.getPosition().y << " - Tamanho: X = " << rectTeste.getSize().x <<
		", Y = " << rectTeste.getSize().y << std::endl;

	gameWindow.setView(cameraGenerica);
	renderMap();
	gameWindow.draw(rectTeste);
	gameWindow.display();
	gameWindow.clear();
}