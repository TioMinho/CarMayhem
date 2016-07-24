#include "Jogador.h"

//Construtor Padrão
Jogador::Jogador(){
	//Inicializa o sentido da pista como sendo o correto
	sentidoCircuito = true;

	//Inicializa a GUI
	playerGUI.loadGUI(maxHealth, maxAmmo);

	//Inicializa o número de voltas
	lapNumber = 0;
}

/*SETTERS*/
void Jogador::setPosition(float x, float y){
	carPlayer.setPosition(x, y);
}

void Jogador::setLaps(int numeroVoltas){
	lapNumber = numeroVoltas;
}

void Jogador::setCar(std::string carSprite, float largura, float altura, float aceleracao, float frenagem, float velocidadeMax, int lifeMax, int ammoMax){
	//Atribuiçao de uma textura ao sprite do carro
	carPlayer.setTexture(carSprite);

	//Posiciona inicialmente os spriteframes do carro
	carPlayer.setSpriteframe(7, 0);
	carPlayer.setTextureRect(7 * largura, 0 * altura, largura, altura);

	//Atribui os valores de largura e altura dos sprites
	carPlayer.setLargura(largura);
	carPlayer.setAltura(altura);

	//Atribui os valores de velocidade, aceleração e frenagem
	carPlayer.setAcceleration(aceleracao);
	carPlayer.setDeacceleration(frenagem);
	carPlayer.setTopSpeed(velocidadeMax);

	//Inicializa a velocidade como zero
	carPlayer.zerarVelocidade();

	//Atribui os indicadores de life máximo e munição
	actualHealth = maxHealth = lifeMax;
	actualAmmo = maxAmmo = ammoMax;
}

void Jogador::setSentido(bool isSentidoCorreto){
	sentidoCircuito = isSentidoCorreto;
}

/*GETTERS*/
sf::Sprite Jogador::getSprite(){
	return carPlayer.getSprite();
}

sf::Vector2i Jogador::getSpriteframe(){
	return carPlayer.getSpriteframe();
}

sf::RectangleShape Jogador::getLifeBar(){
	return playerGUI.getLifeBar();
}

sf::RectangleShape Jogador::getAmmoBar(){
	return playerGUI.getAmmoBar();
}

int Jogador::getLap(){
	return lapNumber;
}

sf::View Jogador::getCamera(){
	return raceCam;
}

sf::Sprite Jogador::getProjetil(int numProjetil){
	return projetil[numProjetil].getBalaSprite();
}

//Método para ativar movimentos
void Jogador::ativarMovimentos(int numberPlayer){
	//Limita a velocidade máxima que o carro pode atingir
	carPlayer.limitarVelocidade();

	//Permite aos sprites das balas de se movimentarem dentro do circuito
	updateAmmo();

	//Controles para o jogador caso ele seja o Player 1
	if (numberPlayer == 0){
		//Tecla para atirar
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			atirar();

		//Tecla para acelerar quando apertada e desacelerar quando solta
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			carPlayer.acelerar();
		else
			carPlayer.desacelerar();

		//Teclas para rotacionar a direção do carro
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			carPlayer.rotacionarAntiHorario();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			carPlayer.rotacionarHorario();
	}
	//Controles para o jogador caso ele seja o Player 2
	else if (numberPlayer == 1){
		//Tecla para atirar
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
			atirar();

		//Tecla para acelerar quando apertada e desacelerar quando solta
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			carPlayer.acelerar();
		else
			carPlayer.desacelerar();

		//Teclas para rotacionar a direção do carro
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			carPlayer.rotacionarAntiHorario();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			carPlayer.rotacionarHorario();
	}

}

//Método que centraliza a camera no carro do jogador
void Jogador::centralizarCamera(){
	raceCam.setCenter(carPlayer.getPositionX() + (carPlayer.getLargura() / 2.0f), carPlayer.getPositionY() + (carPlayer.getAltura() / 2.0f));
}

//Metodo para carregar as posições das câmeras do jogador
void Jogador::loadCamera(int numberPlayer, int larguraJanela, int alturaJanela){
	raceCam.setViewport(sf::FloatRect(0.5f * numberPlayer, 0, 0.5f, 1.0f));
	raceCam.setSize(larguraJanela / 2.0f, alturaJanela);
	raceCam.zoom(0.5);
}

//Método para carregar a GUI do jogador
void Jogador::loadGUI(){
	playerGUI.loadGUI(maxHealth, maxAmmo);
}

//Método para atualizar a GUI em tempo real
void Jogador::updateGUI(){
	playerGUI.updateGUI(carPlayer.getPositionX(), carPlayer.getPositionY(), actualHealth, actualAmmo);
}

//Método para receber dano
void Jogador::dano(int valorDano){
	actualHealth -= valorDano;
}

//Método que aumenta o número da volta
void Jogador::voltaCompleta(){
	lapNumber++;
}

//Método para checar colisões com os limites da pista em tempo real
void Jogador::checarColisao(bool estaColidindo){
	if (estaColidindo)
		carPlayer.colidir();
}

//Método para checar colisões entre os carros
void Jogador::checarColisao(sf::Sprite enemySprite){
	if (Collision::BoundingBoxTest(carPlayer.getSprite(), enemySprite))
		carPlayer.colidir();
}

//Método para checar se o carro está em cima de uma poça de lava, atribuindo um dano ao seu life
void Jogador::checarColisao(int danoLava){
	dano(danoLava);
}

//Método para checar se o carro está em cima de uma poça de piche, retardando seu movimento por um fator inteiro
void Jogador::checarColisao(bool dentroGosma, int fator){
	if (dentroGosma)
		carPlayer.retardarMovimento(fator);
}

//Método para checar se algum projétil atingiu o carro
void Jogador::checarColisao(sf::Sprite projetil, int valorDano){
	if (Collision::BoundingBoxTest(projetil, carPlayer.getSprite())){
		dano(valorDano);
	}
}

//Método para checar se o player ainda possui HP, explodindo o carro caso não possua
void Jogador::checarHP(){
	if (actualHealth <= 0){
		actualHealth = 0;
		carPlayer.explodir();
		if (respawnTimer.getElapsedTime().asSeconds() >= 5)
			actualHealth = maxHealth;
	}
	else
		respawnTimer.restart();
}

//Método que atribui um dano gradual ao player caso ele tente percorrer a pista pelo sentido contrário
void Jogador::checarSentido(){
	if (!sentidoCircuito)
		dano(1);
}

//Método para recarregar a munição
void Jogador::recarregarAmmo(){
	actualAmmo = maxAmmo;
}

//Método para atualizar o movimento de cada bala individualmente no in-game
void Jogador::updateAmmo(){
	projetil[0].updateBullet();
	projetil[1].updateBullet();
	projetil[2].updateBullet();
	projetil[3].updateBullet();
	projetil[4].updateBullet();
	projetil[5].updateBullet();
	projetil[6].updateBullet();
	projetil[7].updateBullet();
	projetil[8].updateBullet();
	projetil[9].updateBullet();
}

//Método principal para disparar um projétil
void Jogador::atirar(){
	if (shotLoad.getElapsedTime().asSeconds() >= 1 && actualAmmo > 0 && actualHealth > 0){
		projetil[actualAmmo - 1].disparar(carPlayer.getTopspeed(), carPlayer.getSpriteframe(), carPlayer.getPositionX(), carPlayer.getPositionY(), carPlayer.getLargura(), carPlayer.getAltura());

		actualAmmo--;
		shotLoad.restart();
	}
}

