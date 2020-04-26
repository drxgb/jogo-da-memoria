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

#include "UI.h"

#include <iostream>
#include <iomanip>

using namespace std;

void UI::titulo() {
	cout << setfill('=') << setw(70) << '\0' << endl
		<< "\t\tJOGO DA MEM�RIA" << endl
		<< setw(70) << '\0'
		<< endl << endl;
}

void UI::limpaTela() {
	system("cls");
	titulo();
}

void UI::HUD(Jogo& jogo) {
	// Colunas
	cout << '\t';
	for (char c = 'A'; c < 'A' + 10; c++) {
		cout << setfill(' ') << setw(4) << c;
	}
	cout << '\0' << endl;
	cout << '\t' << setfill('-') << setw(44) << '\0';
	cout << endl;

	// Mostra os n�meros
	cout << '\t';
	jogo.getNumeros();
	cout << endl;

	// Mostra a quantidade de tentativas
	cout << "Tentativas: " <<
		jogo.getTentativas()
		<< endl << endl;
}

void UI::fim(Jogo& jogo) {
	cout << "MUITO BEM !!" << endl;
	cout << "Voc� concluiu o jogo em "
		<< jogo.getTentativas() << " tentativas"
		<< endl << endl;
}
