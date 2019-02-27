#include <iostream>
#include "Cblad.h"

Cblad::Cblad(){
}

Cblad::Cblad(int nr_bl, bool stop, std::string kom){
	numer_bledu = nr_bl;
	stop_app = stop;
	komunikat = kom;
}

void Cblad::komunikuj(){
	std::cout << "Blad! Numer: " << numer_bledu << " " << komunikat << "\n";
	//if(stop_app){ break; }
}