#include "stol.h"
#include "Cblad.h"
#include <iostream>

stol::stol(){
	moja_talia_wsk = &moja_talia;
}

void stol::pokaz_co_na_stole(std::string kto){
	std::cout << "Karty " << kto << "a to:\n";
	try {
		if (kto == "gracz"){
			for (unsigned int i = 0; i<karty_gracza.size(); i++) { std::cout << karty_gracza.at(i).get_karta() << "\n"; }
		}
		else if (kto == "krupier"){
			for (unsigned int i = 0; i<karty_krupiera.size(); i++) { std::cout << karty_krupiera.at(i).get_karta() << "\n"; }
		}
		else {
			throw Cblad(301, true, "Klasa stol, metoda pokaz co na stole. nie zdefiniowano takiego gracza");
		}
	}

	catch (Cblad blad_1){
		blad_1.komunikuj();
	}

}

void stol::zeruj_punkty(){
	karty_gracza.clear();
	karty_krupiera.clear();
	punkty_gracza = 0;
	punkty_krupiera = 0;
	std::cout << "Stol wyczyszczono\n";
}