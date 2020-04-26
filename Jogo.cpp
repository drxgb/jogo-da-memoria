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

#include "Jogo.h"

#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

Jogo::Jogo(int tam) {
	this->setNumeros(tam);
}

bool Jogo::isFinalizado() {
	for (auto it = this->numeros->begin(); it != this->numeros->end(); it++) {
		if (!(*it).second)
			return false;
	}
	return true;
}

void Jogo::finalizar() {
	this->finalizado = true;
}

void Jogo::setNumeros(int tam) {
	// Zera todos os campos
	for (int i = 0; i < tam; i++) {
		this->numeros->push_back(make_pair(0, false));
	}

	// Define os pares de números a serem guardados
	for (int i = 0; i < tam / 2; i++) {
		this->insereNumero();
	}

}

int Jogo::sorteiaNumero(int max) {
	return rand() % max + 1;
}

void Jogo::insereNumero() {
	int i;
	int sorteio = this->sorteiaNumero(30);
	for (int j = 0; j < 2; j++) {
		do {
			i = rand() % this->numeros->size();
		} while (this->numeros->at(i).first > 0);
		this->numeros->at(i).first = sorteio;
	}
}

int Jogo::getTentativas() {
	return this->tentativas;
}

void Jogo::proximaTentativa() {
	this->tentativas++;
}

void Jogo::getNumeros() {
	// First = Número | Second = Encontrado
	for (auto it = this->numeros->begin(); it != this->numeros->end(); it++) {
		cout << setfill(' ') << setw(4);
		if ((*it).second)
			cout << (*it).first;
		else
			cout << "#";
	}
	cout << '\0' << endl;
}

void Jogo::revelaNumero(char col) {
	int i = (int)(col - 65);
	this->numeros->at(i).second = true;
}

bool Jogo::comparaValores(char a, char b) {
	auto& valorA = this->numeros->at((int)(a - 65));
	auto& valorB = this->numeros->at((int)(b - 65));
	if (valorA.first == valorB.first) {
		return true;
	}
	else {
		valorA.second = false;
		valorB.second = false;
		return false;
	}
}
