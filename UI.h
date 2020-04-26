/*
 * -------------------------
 *		CLASSE UI
 * -------------------------
 * by Dr.XGB
 * Version 1.0
 *
 * Classe respons�vel pela interface
 * gr�fica do jogo.
 * Aqui � onde vai mostrar a tela de t�tulo,
 * HUD e mensagens de fim de jogo.
 * -------------------------------------------
*/

#pragma once

#include "Jogo.h"

class UI
{
public:
	static void titulo();
	static void limpaTela();
	static void HUD(Jogo&);
	static void fim(Jogo&);
};

