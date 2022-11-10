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

