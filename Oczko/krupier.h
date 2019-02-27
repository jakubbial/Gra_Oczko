#pragma once
#include "stol.h"

class krupier
{
private:
	int numer_karty;
	char odp;
public:
	stol moj_stol;
	krupier();
	void kolejna_karta(std::string komu);		//dodaje kolejna karte
	void oblicz_punkty(void);					//oblicza punkty
	void komunik(std::string kom);				//komunikat witaj
	void pokaz_karty(void);						//pokazuje karty
	void powiedz_punkty(std::string kto);		//wyswietla sume punktow gracza lub krupiera
	void zap(std::string tkst);
	char odpowiedz();
};