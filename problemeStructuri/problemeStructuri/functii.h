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

//todo functie ce citeste numărul de copii dintr-o grupă şi tipul de uniformă pe care aceştia îl poartă

void citireCopiiUniforme(uniforme uniforma[], int& n, int& p) {
	ifstream f("citireUniforme.txt");
	f >> n >> p;
	for (int i = 0; i < n; i++) {
		f >> uniforma[i].copii;
		f >> uniforma[i].tip;
	}
}

//todo functie ce returneaza numarul de copii care poarta o uniforma

int contorCopii(uniforme uniforma[], int tip, int n) {
	int total = 0;
	for (int i = 0; i < n; i++) {
		if (uniforma[i].tip == tip) {
			total = total + uniforma[i].copii;
		}
	}
	return total;
}

//todo fucntie ce sorteaza tipurile de uniforme în ordinea descrescătoare a numărului total de copii ce poartă fiecare tip de uniformă

void sortareDesc(uniforme uniforma[], int n) {
	bool flag = 0;
	do {
		flag = 1;
		for (int i = 0; i < n - 1; i++) {
			if (contorCopii(uniforma, uniforma[i].tip, n) < contorCopii(uniforma, uniforma[i + 1].tip, n)) {
				swap(uniforma[i].tip, uniforma[i + 1].tip);
				swap(uniforma[i].copii, uniforma[i + 1].copii);
				flag = 0;
			}
		}
	} while (!flag);
}

//todo functie ce citeste durata a 2 evenimente

void citireDurata(program durata[]) {
	ifstream f("citireProgram.txt");
	f >> durata[0].ore;
	f >> durata[0].minute;
	f >> durata[0].secunde;	
	f >> durata[1].ore;
	f >> durata[1].minute;
	f >> durata[1].secunde;
}

//todo functie ce returneaza durata corespunzatoare in secunde

int durataSecunde(program durata) {
	int secunde = 0;
	secunde = durata.secunde + durata.minute * 60 + durata.ore * 3600;
	return secunde;
}

//todo functie ce afiseaza suma obţinută din adunarea duratelor celor două evenimente

void suma (int secunde1, int secunde2) {
	int totalS = secunde1 + secunde2;
	int s = totalS % 60;
	int m = (totalS / 60) % 60;
	int h = (totalS / 3600) % 60;
	cout << h << ": " << m << ": " << s;
}