#pragma once
#include <string>

class karta
{
public:
	karta(std::string kolor, std::string figura, int punkty_na_karcie);		//konstruktor wpisujacy w zmienne kol i fig stringi
	std::string kol;									//miejsce na kolor karty
	std::string fig;									//miejsce na figure
	int punkty;											//punkty jakie ma dana karta
	std::string get_karta();							//zwraca string z kolorem i figura karty
};