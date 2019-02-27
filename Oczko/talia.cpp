#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include "talia.h"
#include "karta.h"

talia::talia(){
	//static tzn istnieje dla wszystkich obiektów danej klasy
	//const tzn tylko do odczytu
	static const std::string kolo[] = { "czerwo", "dzwonek", "zoledz", "wino" };
	static const std::string figu[] = { "dwojka", "trojka", "czworka", "piatka", "szostka", "siodemka", "osemka", "dziewiatka", "dziesiatka", "walet", "dama", "krol", "as" };
	const int punkty[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 2, 3, 4, 11};

	std::vector<std::string> kolory(kolo, kolo + sizeof(kolo) / sizeof(kolo[0]));
	std::vector<std::string> figury(figu, figu + sizeof(figu) / sizeof(figu[0]));
	

	int size_kolory = kolory.size();
	int size_figury = figury.size();



	for (int i = 0; i<size_kolory; i++){
		for (int j = 0; j<size_figury; j++){
			karta karta(kolory.at(i), figury.at(j), punkty[j]);
			karty.push_back(karta);
		}
	}
}

void talia::tasuj_talie(void){
	srand(time(NULL));
	std::random_shuffle(karty.begin(), karty.end());
	std::cout << "Karty potasowano\n";
}