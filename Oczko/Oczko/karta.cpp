#include "karta.h"

karta::karta(std::string kolor, std::string figura, int punkty_na_karcie )
{
	kol = kolor;
	fig = figura;
	punkty = punkty_na_karcie;
}

std::string karta::get_karta()
{
	return kol + " " + fig + " " + std::to_string(punkty) + " punktow" ;
}