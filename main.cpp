/*
 * -----------------------------
 *		JOGO DA MEMÓRIA
 * -----------------------------
 *
 * by Dr.XGB	-	Apr 25th, 2020
 * Version 1.0
 *
 * Um simples jogo da memória feito para o terminal
 * do Windows.
 * ---------------------------------------------------
*/

#include "UI.h"
#include "Jogo.h"

#include <iostream>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int main() {

	// Definições iniciais do console
	srand((unsigned int) time(0));
	setlocale(LC_ALL, "portuguese");
	system("title Jogo da Memória");

	// Tela de Título
	UI::titulo();
	cout << "\tBem-vindo ao JOGO DA MEMÓRIA !!" << endl << endl;
	system("pause");

	// Iniciar o jogo
	UI::limpaTela();
	cout << "Os números estão sendo sorteados..." << endl;
	Sleep(3000);

	Jogo jogo{10};
	cout << "Pronto!" << endl;
	Sleep(1000);	

	// Loop Principal
	while (!jogo.isFinalizado()) {
		// HUD do jogo
		UI::limpaTela();
		UI::HUD(jogo);

		char a, b; // Colunas
		bool revelado = false;

		// Escolher a primeira coluna		
		do {
			cout << "Escolha uma coluna de A - J: ";
			cin >> a;
			revelado = jogo.revelaNumero(a);
		} while ((a < 'A' || a > 'J') || !revelado);

		// Escolher a segunda coluna
		UI::limpaTela();
		UI::HUD(jogo);
		do {
			cout << "Em qual coluna está o par deste número? ";
			cin >> b;
			revelado = jogo.revelaNumero(b);
		} while ((b < 'A' || b > 'J') || !revelado);

		// Comparar se os valores são iguais
		UI::limpaTela();
		UI::HUD(jogo);
		if (jogo.comparaValores(a, b)) {
			// Acertou
			cout << "Você acertou!" << endl << endl;
		}
		else {
			// Errou
			cout << "Você errou!" << endl << endl;
			jogo.proximaTentativa();
		}
		system("pause");
	}

	// Fim de Jogo
	UI::limpaTela();
	UI::HUD(jogo);
	UI::fim(jogo);

	return 0;
}