#include "krupier.h"
#include "Cblad.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <time.h>

krupier::krupier(){
	numer_karty = 0;
}

void krupier::kolejna_karta(std::string komu){
	if (komu == "krupier"){
		moj_stol.karty_krupiera.push_back(moj_stol.moja_talia.karty[numer_karty]);
		komunik("dostal_kr");
	}
	else if (komu == "gracz"){
		moj_stol.karty_gracza.push_back(moj_stol.moja_talia.karty[numer_karty]);
		komunik("dostal_gr");
	}
	numer_karty++;
}

void krupier::oblicz_punkty(void){

	moj_stol.punkty_gracza = 0;
	moj_stol.punkty_krupiera = 0;

	for (unsigned int i = 0; i<moj_stol.karty_gracza.size(); i++){
		moj_stol.punkty_gracza = moj_stol.punkty_gracza+moj_stol.karty_gracza[i].punkty;
	}

	for (unsigned int i = 0; i<moj_stol.karty_krupiera.size(); i++){
		moj_stol.punkty_krupiera = moj_stol.punkty_krupiera+moj_stol.karty_krupiera[i].punkty;
	}
}

void krupier::komunik(std::string kom){
	try{
		if (kom == "witaj") {
			zap("Witaj  w grze \"Oczko\"");
		}
		else if (kom == "czy_rozpoczac"){
			zap("Czy chcesz rozpoczac? T/N");
		}
		else if (kom == "zegnaj"){
			zap("Do widzenia");
		}
		else if (kom == "blad"){
			throw Cblad(201, false, "Klasa komunikat. Jakis obiekt zwrocil blad");
		}
		else if (kom == "dostal_kr"){
			zap("Krupier otrzymal karte");
		}
		else if (kom == "dostal_gr"){
			zap("Gracz otrzymal karte");
		}
		else if (kom == "czy_dobiera"){
			zap("Czy chcesz dobrac kolejna karte? T/N");
		}
		else if (kom == "przegrana"){
			zap("Przegrales!");
		}
		else if (kom == "wygrana"){
			zap("Wygrales!");
		}
		else{
			throw Cblad(101, true, "Klasa komunikat. Nie przewidziano tresci dla tego komunikatu");
		}
	}

	catch (Cblad blad_0){
		blad_0.komunikuj();
	}
}

void krupier::zap(std::string tkst){
	std::cout << tkst << "\n";
}

void krupier::pokaz_karty(){
	int size = moj_stol.moja_talia.karty.size();
	for (int i = 0; i<size; i++){
		std::cout << moj_stol.moja_talia.karty.at(i).get_karta() << "\n";
	}
}

void krupier::powiedz_punkty(std::string kto){
	if (kto == "gracz"){
		std::cout << "Punkty Gracza to: " << moj_stol.punkty_gracza << "\n";
	}
	else if (kto == "krupier"){
		std::cout << "Punkty Krupiera to: " << moj_stol.punkty_krupiera << "\n";
	}
}

char krupier::odpowiedz(){
	std::cin >> odp;
	return odp;
}