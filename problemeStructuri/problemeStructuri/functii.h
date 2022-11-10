using namespace std;
#include <iostream>
#include <fstream>
#include "structuri.h"
#pragma once

//todo functie ce citeste o structura din fisier

void citireAniversari(aniversari aniversare[], int& d) {
	ifstream f("citireAniversari.txt");
	f >> d;
	for (int i = 1; i <= d; i++) {
		f >> aniversare[i].an;
		f >> aniversare[i].luna;
		f >> aniversare[i].zi;
	}
}

void afisareAniversari(aniversari aniversare[], int d) {
	for (int i = 1; i <= d; i++) {
		cout << aniversare[i].an << ' ';
		cout << aniversare[i].luna << ' ';
		cout << aniversare[i].zi << endl;
	}
}

//todo functie ce determina cea mai tanara persoana

int persTanara(aniversari aniversare[], int d) {
	int minimAn = 0, minimLuna=0, minimZi=0, indice = 0;
	for (int i = 1; i <= d; i++) {
		if (aniversare[i].an > minimAn) {
			minimAn = aniversare[i].an;
			indice = i;
		}
		else {
			if (aniversare[i].an == minimAn) {
				if (aniversare[i].luna > minimLuna) {
					minimLuna = aniversare[i].luna;
					indice = i;
				}
				else {
					if (aniversare[i].luna == minimLuna) {
						if (aniversare[i].zi > minimZi) {
							minimZi = aniversare[i].zi;
							indice = i;
						}
					}
				}
			}
		}
	}
	return indice;
}

int persBatrana(aniversari aniversare[], int d) {
	int maximAn = 0, maximLuna=0, maximZi=0, indice = 0;
	for (int i = 1; i <= d; i++) {
		if (aniversare[i].an < maximAn) {
			maximAn = aniversare[i].an;
			indice = i;
		}
		else {
			if (aniversare[i].an == maximAn) {
				if (aniversare[i].luna < maximLuna) {
					maximLuna = aniversare[i].luna;
					indice = i;
				}
				else {
					if (aniversare[i].luna == maximLuna) {
						if (aniversare[i].zi < maximZi) {
							maximZi = aniversare[i].zi;
							indice = i;
						}
					}
				}
			}
		}
	}
	return indice;
}