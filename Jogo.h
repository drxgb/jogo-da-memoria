/*
 * -------------------------
 *		CLASSE JOGO
 * -------------------------
 * by Dr.XGB
 * Version 1.0
 *
 * Classe responsável pela lógica de
 * todo o jogo.
 * -------------------------------------------
*/

#pragma once

#include <utility>
#include <vector>

using namespace std;

class Jogo
{
private:
	int tentativas = 1;
	vector<pair<int, bool>> numeros[10];
	bool finalizado = false;

	void setNumeros(int);
	int sorteiaNumero(int);
	void insereNumero();

public:
	Jogo(int);
	
	bool isFinalizado();
	void finalizar();
	int getTentativas();
	void proximaTentativa();
	void getNumeros();
	bool revelaNumero(char);
	bool comparaValores(char, char);
};

