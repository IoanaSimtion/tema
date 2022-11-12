using namespace std;
#include <iostream>
#include <fstream>
#include <math.h>
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

//todo functie ce citeste 2 fractii

void citireFractii(fractii& fractie1, fractii& fractie2) {
	ifstream f("citireFractii.txt");
	f >> fractie1.numarator;
	f >> fractie1.numitor;
	f >> fractie2.numarator;
	f >> fractie2.numitor;
}

//todo functie ce compara 2 fractii

fractii comparareFractii(fractii f1, fractii f2) {
	if (f1.numarator / f1.numitor > f2.numarator / f2.numitor) {
		return f1;
	}
	else {
		return f2;
	}
}

//todo functie ce returneaza cmmdc a doua numere

int cmmdc(int a, int b) {
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

//todo functie ce simplifica o fractie 

void simplificare(int& numarator, int& numitor) {
	int divizor = cmmdc(numarator, numitor);
	numarator = numarator / divizor;
	numitor=numitor/divizor;
}

//todo functie ce citeste coordonatele a n puncte

void citireCoordonate(coordonate puncte[], int& n) {
	ifstream f("citireCoordonate.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> puncte[i].x;
		f >> puncte[i].y;
	}
}

//todo functie ce returneaza distanta dintre un punct si origine

float distanta(coordonate punct) {
	int a = pow(punct.x, 2);
	int b = pow(punct.y, 2);
	float d = sqrt(a + b);
	return d;
}

//todo functie ce determina distanta maxima

float distantaMaxima(coordonate punct[], int n) {
	float max = 0;
	for (int i = 0; i < n; i++) {
		if (distanta(punct[i]) > max) {
			max = distanta(punct[i]);
		}
	}
	return max;
}

//todo functie ce returneaza nr de puncte ce au distanta maxima

int ctDistMax(coordonate punct[], int n, float dMax) {
	int ct = 0;
	for (int i = 0; i < n; i++) {
		if (distanta(punct[i]) == dMax) {
			ct++;
		}
	}
	return ct;
}

//todo functie ce citeste datele elevilor

void citireDateElevi(dateElevi elev[], int& n) {
	ifstream f("citireElevi.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> elev[i].cod;
		f >> elev[i].medie;
		f >> elev[i].absente;
	}
}

//todo functie ce returneaza nr de elevi cu media 10

int ctMedie(dateElevi elev[], int n) {
	int ct = 0;
	for (int i = 0; i < n; i++) {
		if (elev[i].medie == 10) {
			ct++;
		}
	}
	return ct;
}

//todo functie ce returneaza media clasei

int mediaClasei(dateElevi elev[], int n) {
	int suma = 0;
	for (int i = 0; i < n; i++) {
		suma = suma + elev[i].medie;
	}
	return suma / n;
}

//todo functie ce determina primii 2 elevi după absențe

void maximAbsente(dateElevi elev[], int& a, int& b, int n) {
	int max1=0, max2=0;
	for (int i = 0; i < n; i++) {
		if (elev[i].absente > max1) {
			max2 = max1;
			max1 = elev[i].absente;
			a = i;
		}
		else {
			if (elev[i].absente == max1) {
				if (elev[i].cod > elev[a].cod) {
					max2 = max1;
					max1 = elev[i].absente;
					b = a;
					a = i;
				}
			}
			else {
				max2 = elev[i].absente;
				b = i;
			}
		}
	}
}