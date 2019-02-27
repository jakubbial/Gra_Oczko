#pragma once
#include <string>

class Cblad
{
public:
	Cblad();
	Cblad(int nr_bl, bool stop, std::string kom);
	void komunikuj(void);
	int numer_bledu;
	bool stop_app;
	std::string komunikat;
};