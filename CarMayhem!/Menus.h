#pragma once
class Menus{
protected:
	//*******************
	//****Atributos******
	//*******************
	sf::Sprite menuBackground;					// Imagem do plano de fundo do Menu
	sf::Texture menuTextura;					// Textura do imagem
	bool menuOpen;								// Boolean que indica se o menu est� ou n�o aberto
	int numSelecao = 1, optionSelected = 0;		// Vari�veis inteiras que represent�o as op��es do menu

	//*******************
	//*****M�todos*******
	//*******************
	//M�todo abstrato para intera��o das sele��es com o usu�rio
	virtual void selecaoMenu();

public:
	//*******************
	//*****M�todos*******
	//*******************
	//Construtor Padr�o
	Menus();

	/*GETTERS*/
	virtual int getOption();

	virtual sf::Sprite menuDraw();

	//M�todo para checar se o menu est� aberto ou fechado
	virtual bool isMenuOpen();

	//M�todo para abrir o menu
	virtual void abrirMenu();

	//M�todo para fechar o menu
	virtual void fecharMenu();

	//M�todo abstrato para ativar a sele��o do menu quando aberto
	virtual void ativarSelecao();

	//M�todo que atribui o valor da sele��o � uma vari�vel para ser utilizado no game
	virtual void selectOption();
};