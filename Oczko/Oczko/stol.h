#pragma once
#include <string>
#include "talia.h"
#include "karta.h"

class stol
{
public:
	talia moja_talia;							//tworzy obiekt klasy talia, czyli tworzy sobie talie
	talia *moja_talia_wsk;						//wskaznik na talie
	stol();										//konstruktor. wpisuje wskaznik na talie
	void pokaz_co_na_stole(std::string kto);			//pokazuje co lezy na stole
	void zeruj_punkty(void);							//zeruje karty i punkty po grze
	std::vector<karta> karty_gracza;			//przechowuje karty jakie ma gracz
	std::vector<karta> karty_krupiera;			//przechowuje karty jakie ma krupier
	int punkty_gracza;							//podliczone punkty gracza
	int punkty_krupiera;						//podliczone punkty krupiera
};