#pragma once
#include <string>
#include <vector>

class karta;

class talia
{
private:
	static const std::string kolo[];
	static const std::string figu[];
	static const int punkty[];
	std::vector<std::string> kolory;
	std::vector<std::string> figury;
	

	int size_kolory;
	int size_figury;

public:
	talia();						//wypelnia wektor "karty" kartami nadajac im po kolei figury i kolory
	void tasuj_talie(void);
	std::vector<karta> karty;		//wektor z kolejno ulozonymi kartami

};