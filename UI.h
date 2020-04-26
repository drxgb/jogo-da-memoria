/*
 * -------------------------
 *		CLASSE UI
 * -------------------------
 * by Dr.XGB
 * Version 1.0
 *
 * Classe responsável pela interface
 * gráfica do jogo.
 * Aqui é onde vai mostrar a tela de título,
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

