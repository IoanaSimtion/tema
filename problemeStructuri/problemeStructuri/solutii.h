#include "functii.h"
#include "structuri.h"
#pragma once

/*1013: Se dau datele de naștere a n persoane, numerotate de la 1 la n, 
în forma an luna zi. Să se determine numărul de ordine al celei mai tinere
și al celei mai în vârstă persoană dintre cele date.*/

void sol1(){
	aniversari aniversare[100];
	int n;
	citireAniversari(aniversare, n);
	//afisareAniversari(aniversare, n);
	cout << "Cea mai tanara persoana este persoana cu numarul " << persTanara(aniversare, n) << endl;
	cout << "Cea mai in varsta persoana este persona cu numarul " << persBatrana(aniversare, n);
}

//293: Se dau 4 numere naturale a b c d, reprezentând fracţiile a/b şi c/d.
//Determinați și afișați cea mai mare dintre cele două fracții.

void sol2() {
	fractii fr1, fr2;
	citireFractii(fr1, fr2);
	simplificare(fr1.numarator, fr1.numitor);
	simplificare(fr2.numarator, fr2.numitor);
	cout << comparareFractii(fr1, fr2).numarator << ' ' << comparareFractii(fr1, fr2).numitor;
}


/*922: Se dau coordonatele carteziene a n puncte în plan. 
Să se determine distanța maximă dintre un punct dat și originea sistemului de coordonate 
și numărul de puncte situate la acea distanță față de origine.*/

void sol3() {
	int n;
	coordonate puncte[100];
	citireCoordonate(puncte, n);
	cout << distantaMaxima(puncte, n) << endl;
	cout << ctDistMax(puncte, n, distantaMaxima(puncte, n));
}

/*3164: Se dau n, reprezentând numărul de elevi apoi, pe câte un rând, datele fiecărui elev: 
codul, media la informatică și numărul de absențe.
Definiți un tip structură pentru a putea memora datele unui elev și rezolvați cerințele:
a) memorați datele tuturor elevilor într-un vector de structuri de tipul definit;
b) afișați numărul de elevi cu media 10
c) afișați media clasei (se va afișa doar partea întreagă a ei).
d) afișați primii doi elevi după absențe (elevii cu cele mai multe absențe).
Dacă sunt mai mulți elevi cu același număr de absențe se afișează în ordine crescătoare a codului. 
Dacă sunt mai mult de doi elevi număr maxim de absențe se afișează doar doi.*/

void sol4() {
	int n, a, b;
	dateElevi elevi[100];
	citireDateElevi(elevi, n);
	cout << ctMedie(elevi, n) << endl;
	cout << mediaClasei(elevi, n) << endl;
	maximAbsente(elevi, a, b, n);
	cout << elevi[a].cod << ' ' << elevi[a].medie << ' ' << elevi[a].absente << endl;
	cout << elevi[b].cod << ' ' << elevi[b].medie << ' ' << elevi[b].absente << endl;

}

/*1460: La o serbare sunt n grupe de copii care poartă p tipuri de uniforme.
Scrieţi un program care să afişeze pe ecran tipurile de uniforme 
în ordinea descrescătoare a numărului total de copii ce poartă fiecare tip de uniformă. 
Afişarea se va face pe o singură linie, valoriile fiind separate printr-un spaţiu.*/

void sol5() {
	int n, p;
	uniforme uniforma[100];
	citireCopiiUniforme(uniforma, n, p);
	//cout << contorCopii(uniforma, 2, n);
	sortareDesc(uniforma, n);
	for (int i = 0; i < n; i++) {
		cout << uniforma[i].tip << ' ';
		while (uniforma[i].tip == uniforma[i + 1].tip) {
			i++;
		}
	}
}