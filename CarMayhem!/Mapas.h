#include <SFML/Graphics.hpp>
#include <sstream>
#include <cctype>
#include <fstream>
#include <vector>
#include "Collision.h"

class TileTracks{
private:
	//*******************
	//****Atributos******
	//*******************
	sf::Texture tileTexture;											// Textura do tileset
	sf::Sprite tiles;													// Sprite de cada tile
	sf::Sprite rectLimiteExt[6], rectLimiteInt[6], rectLimiteDiag[6];	// Pistas de Colisão
	sf::Texture limTextExt[6], limTextInt[6], limTextDiag[2];			// Tamanho dos sprites de colisão
	sf::Sprite linhaChegada;											// Sprite da linha de chegada
	sf::Texture linhaText;												//mTextura da linha de chegada
	sf::Sprite obstaculo[6];											// Seis sprites de obstáculos
	sf::Texture lava, gosma;											// Textura de lava e gosma para obstáculos
	std::vector<std::vector<sf::Vector2i>> map;							// Vetores para a leitura do tilemap
	std::vector<sf::Vector2i> tempMap;									// Vetores para a leitura do tilemap

	//*******************
	//*****Métodos*******
	//*******************

	//Metodo que cria os limites para os quais a pista não deve ser ultrapassada
	void criarMapaColisao(){
		//Strings para Carregar Textura
		std::string textString, numTextura, extensao = ".png";
		std::stringstream conversor[3][6];

		//Inicializando um tamanho para os Sprites
		//Limites Externos
		for (int i = 0; i < 6; i++){
			//Inicializa a string da textura a ser carregada com o Diretório das imagens
			textString = "Resources/CollisionMap/Ext/";
			//Tranforma o valor inteiro do loop para String e acrescenta a extensão do arquivo (.png) à uma string
			conversor[0][i] << i;
			numTextura = conversor[0][i].str();
			numTextura += extensao;
			//Une a duas strings
			textString += numTextura;

			//Carrega a textura correspondente à string formada 
			limTextExt[i].loadFromFile(textString);

			//Atribuição da textura no Sprite
			rectLimiteExt[i].setTexture(limTextExt[i]);
		}
		//Limites Internos
		for (int j = 0; j < 6; j++){
			//Inicializa a string da textura a ser carregada com o Diretório das imagens
			textString = "Resources/CollisionMap/Int/";
			//Tranforma o valor inteiro do loop para String e acrescenta a extensão do arquivo (.png) à uma string
			conversor[1][j] << j;
			numTextura = conversor[1][j].str();
			numTextura += extensao;
			//Une a duas strings
			textString += numTextura;

			//Carrega a textura correspondente à string formada 
			limTextInt[j].loadFromFile(textString);

			//Atribuição da textura no Sprite
			rectLimiteInt[j].setTexture(limTextInt[j]);
		}
		//Limites Diagonais
		for (int k = 0; k < 2; k++){
			//Inicializa a string da textura a ser carregada com o Diretório das imagens
			textString = "Resources/CollisionMap/Diag/";
			//Tranforma o valor inteiro do loop para String e acrescenta a extensão do arquivo (.png) à uma string
			conversor[2][k] << k;
			numTextura = conversor[2][k].str();
			numTextura += extensao;
			//Une a duas strings
			textString += numTextura;

			//Carrega a textura correspondente à string formada 
			limTextDiag[k].loadFromFile(textString);
		}
		//Atribuição da textura ao Sprite
		for (int l = 0; l < 2; l++)
			rectLimiteDiag[l].setTexture(limTextDiag[1]);
		for (int m = 2; m < 6; m++)
			rectLimiteDiag[m].setTexture(limTextDiag[0]);

		//Posicão de cada retângulo limitante na pista principal
		//Limites Externos
		rectLimiteExt[0].setPosition(sf::Vector2f(1110, 1088));
		rectLimiteExt[1].setPosition(sf::Vector2f(1110, 992));
		rectLimiteExt[2].setPosition(sf::Vector2f(4108, 384));
		rectLimiteExt[3].setPosition(sf::Vector2f(2732, 1112));
		rectLimiteExt[4].setPosition(sf::Vector2f(2724, 1106));
		rectLimiteExt[5].setPosition(sf::Vector2f(4182, 2070));
		//Limites Internos
		rectLimiteInt[0].setPosition(sf::Vector2f(1450, 1048));
		rectLimiteInt[1].setPosition(sf::Vector2f(1468, 1056));
		rectLimiteInt[2].setPosition(sf::Vector2f(4084, 506));
		rectLimiteInt[3].setPosition(sf::Vector2f(2350, 1045));
		rectLimiteInt[4].setPosition(sf::Vector2f(2350, 1135));
		rectLimiteInt[5].setPosition(sf::Vector2f(4264, 1912));
		//Limites Diagonais
		rectLimiteDiag[0].setPosition(sf::Vector2f(3994, 2000));
		rectLimiteDiag[1].setPosition(sf::Vector2f(3858, 406));
		rectLimiteDiag[2].setPosition(sf::Vector2f(1145, 1218));
		rectLimiteDiag[3].setPosition(sf::Vector2f(4758, 852));
		rectLimiteDiag[4].setPosition(sf::Vector2f(2432, 1290));
		rectLimiteDiag[5].setPosition(sf::Vector2f(5030, 2024));

		//Rotaciona cada limite para que se encaixe na pista
		//Limites Externos
		rectLimiteExt[0].setRotation(287.001);
		rectLimiteExt[1].setRotation(258.501);
		rectLimiteExt[2].setRotation(286.701);
		rectLimiteExt[3].setRotation(258.401);
		rectLimiteExt[4].setRotation(286.801);
		rectLimiteExt[5].setRotation(258.401);
		//Limites Internos
		rectLimiteInt[0].setRotation(287.001);
		rectLimiteInt[1].setRotation(258.301);
		rectLimiteInt[2].setRotation(288.101);
		rectLimiteInt[3].setRotation(258.701);
		rectLimiteInt[4].setRotation(286.701);
		rectLimiteInt[5].setRotation(259.901);
		//Limites Diagonais
		rectLimiteDiag[0].setRotation(273.601);
		rectLimiteDiag[1].setRotation(271.501);
		rectLimiteDiag[2].setRotation(183.501);
		rectLimiteDiag[3].setRotation(185.001);
		rectLimiteDiag[4].setRotation(181.401);
		rectLimiteDiag[5].setRotation(170.001);
	}

	//Metodo que cria e posiciona cada obstáculo da pista
	void criarObstaculos(){
		//Poças de Lava
		//Carrega as texturas
		lava.loadFromFile("Resources/CollisionMap/Obstaculos/lava.png");
		gosma.loadFromFile("Resources/CollisionMap/Obstaculos/gosma.png");

		//Atribui a textura de lava aos 5 primeiros sprites e a textura de gosma ao último sprite
		for (int i = 0; i < 5; i++)
			obstaculo[i].setTexture(lava);
		obstaculo[5].setTexture(gosma);

		//Rotaciona cada sprite
		obstaculo[0].setRotation(104.2);
		obstaculo[1].setRotation(94.5);
		obstaculo[2].setRotation(104.9);
		obstaculo[3].setRotation(104.9);
		obstaculo[4].setRotation(104.9);
		obstaculo[5].setRotation(78.1);

		//Posiciona os sprites em relação ao mapa
		obstaculo[0].setPosition(sf::Vector2f(2630, 1454));
		obstaculo[1].setPosition(sf::Vector2f(2060, 832));
		obstaculo[2].setPosition(sf::Vector2f(4756, 646));
		obstaculo[3].setPosition(sf::Vector2f(2986, 1260));
		obstaculo[4].setPosition(sf::Vector2f(3480, 1356));
		obstaculo[5].setPosition(sf::Vector2f(3712, 486));
	}

	//Método que cria e posiciona a linha de chegada
	void criarLinhaChegada(){
		//Carrega a textura da linha de chegada
		linhaText.loadFromFile("Resources/CollisionMap/Obstaculos/linhaChegada.png");

		//Atribui a textura ao sprite
		linhaChegada.setTexture(linhaText);

		//Angulação da linha
		linhaChegada.setRotation(42.5);

		//Posição da Linha
		linhaChegada.setPosition(sf::Vector2f(3216, 1620));
	}


public:
	//*******************
	//*****Métodos*******
	//*******************

	/*GETTERS*/
	sf::Sprite getLimiteExt(int lado){
		return rectLimiteExt[lado];
	}

	sf::Sprite getLimiteInt(int lado){
		return rectLimiteInt[lado];
	}

	sf::Sprite getLimiteDiag(int lado){
		return rectLimiteDiag[lado];
	}

	sf::Sprite getObstaculo(int vetor){
		return obstaculo[vetor];
	}

	sf::Sprite getFinishLine(){
		return linhaChegada;
	}

	sf::Sprite getTile(){
		return tiles;
	}

	int getSize(){
		return map.size();
	}

	int getSize(int vetor)	{
		return map[vetor].size();
	}

	int getTileNumberX(int vetor1, int vetor2){
		return map[vetor1][vetor2].x;
	}

	int getTileNumberY(int vetor1, int vetor2){
		return map[vetor1][vetor2].y;
	}

	float getChegadaX(){
		return linhaChegada.getPosition().x;
	}

	float getChegadaY(){
		return linhaChegada.getPosition().y;
	}

	/*SETTERS*/

	void setTilePosition(float x, float y){
		tiles.setPosition(x, y);
	}

	void setTileRectangle(int rectLeft, int rectTop, int rectLargura, int rectAltura){
		tiles.setTextureRect(sf::IntRect(rectLeft, rectTop, rectLargura, rectAltura));
	}

	//Método principal para Carregar o Mapa:
	void LoadMap(const char* filename)
	{
		//O nome do arquivo .txt onde o mapa está escrito
		std::ifstream openfile(filename);

		//Função temporária que permite modificar o mapa em tempo real
		tempMap.clear();
		map.clear();

		if (openfile.is_open()){
			//Armazena a primeira string do .txt como sendo a referência da textura do TileMap
			std::string tileLocation;
			openfile >> tileLocation;
			tileTexture.loadFromFile(tileLocation);
			tiles.setTexture(tileTexture);

			while (!openfile.eof()){
				std::string str, value;
				std::getline(openfile, str);
				std::stringstream stream(str);

				while (std::getline(stream, value, ' ')){
					if (value.length() > 0){
						std::string xx = value.substr(0, value.find(','));
						std::string yy = value.substr(value.find(',') + 1);

						int x, y, i, j;

						for (i = 0; i < xx.length(); i++)
						{
							if (!isdigit(xx[i]))
								break;
						}
						for (j = 0; j < yy.length(); j++)
						{
							if (!isdigit(yy[j]))
								break;
						}

						x = (i == xx.length()) ? atoi(xx.c_str()) : -1;
						y = (j == yy.length()) ? atoi(yy.c_str()) : -1;

						tempMap.push_back(sf::Vector2i(x, y));
					}
				}

				map.push_back(tempMap);
				tempMap.clear();
			}
		}
	}

	//Metodo que cria a estrutura de limites da pista, posiciona obstáculos e define a linha de chegada
	void estruturarMapa(){
		criarMapaColisao();
		criarLinhaChegada();
		criarObstaculos();
	}

	//Método para Checar colisão de Sprites com os limites da Pista
	bool checkCollision(sf::Sprite carro){
		if (Collision::BoundingBoxTest(carro, getLimiteExt(0)) ||
			Collision::BoundingBoxTest(carro, getLimiteExt(1)) ||
			Collision::BoundingBoxTest(carro, getLimiteExt(2)) ||
			Collision::BoundingBoxTest(carro, getLimiteExt(3)) ||
			Collision::BoundingBoxTest(carro, getLimiteExt(4)) ||
			Collision::BoundingBoxTest(carro, getLimiteExt(5)) ||
			Collision::BoundingBoxTest(carro, getLimiteInt(0)) ||
			Collision::BoundingBoxTest(carro, getLimiteInt(1)) ||
			Collision::BoundingBoxTest(carro, getLimiteInt(2)) ||
			Collision::BoundingBoxTest(carro, getLimiteInt(3)) ||
			Collision::BoundingBoxTest(carro, getLimiteInt(4)) ||
			Collision::BoundingBoxTest(carro, getLimiteInt(5)) ||
			Collision::BoundingBoxTest(carro, getLimiteDiag(0)) ||
			Collision::BoundingBoxTest(carro, getLimiteDiag(1)) ||
			Collision::BoundingBoxTest(carro, getLimiteDiag(2)) ||
			Collision::BoundingBoxTest(carro, getLimiteDiag(3)) ||
			Collision::BoundingBoxTest(carro, getLimiteDiag(4)) ||
			Collision::BoundingBoxTest(carro, getLimiteDiag(5))
			)
			return 1;
		else
			return 0;
	}

	//Método para checar colisão com obstáculo lava
	int checkLava(sf::Sprite carro){
		if (Collision::BoundingBoxTest(carro, getObstaculo(0)) ||
			Collision::BoundingBoxTest(carro, getObstaculo(1)) ||
			Collision::BoundingBoxTest(carro, getObstaculo(2)) ||
			Collision::BoundingBoxTest(carro, getObstaculo(3)) ||
			Collision::BoundingBoxTest(carro, getObstaculo(4)))
			return 5;
		else
			return 0;
	}

	//Método para checar colisão com obstáculo gosma
	bool checkGosma(sf::Sprite carro){
		if (Collision::BoundingBoxTest(carro, getObstaculo(5)))
			return 1;
		else
			return 0;
	}
};