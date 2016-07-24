#pragma once
class Menus{
protected:
	//*******************
	//****Atributos******
	//*******************
	sf::Sprite menuBackground;					// Imagem do plano de fundo do Menu
	sf::Texture menuTextura;					// Textura do imagem
	bool menuOpen;								// Boolean que indica se o menu está ou não aberto
	int numSelecao = 1, optionSelected = 0;		// Variáveis inteiras que representão as opções do menu

	//*******************
	//*****Métodos*******
	//*******************
	//Método abstrato para interação das seleções com o usuário
	virtual void selecaoMenu();

public:
	//*******************
	//*****Métodos*******
	//*******************
	//Construtor Padrão
	Menus();

	/*GETTERS*/
	virtual int getOption();

	virtual sf::Sprite menuDraw();

	//Método para checar se o menu está aberto ou fechado
	virtual bool isMenuOpen();

	//Método para abrir o menu
	virtual void abrirMenu();

	//Método para fechar o menu
	virtual void fecharMenu();

	//Método abstrato para ativar a seleção do menu quando aberto
	virtual void ativarSelecao();

	//Método que atribui o valor da seleção à uma variável para ser utilizado no game
	virtual void selectOption();
};