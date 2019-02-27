#include "stdafx.h"
#include <iostream>
#include <string>
#include "karta.h"
#include "talia.h"
#include "krupier.h"
#include "stol.h"
#include "Cblad.h"

int main() {

		krupier k;

		k.komunik("witaj");
		int dzialanie = 1; //odnosnik do stanu pytania czy rozpoczac gre
		bool kontynuowac = true;
		char odp;

		while (kontynuowac == true){
			try{
				switch (dzialanie){
				case 1: //stan pytania czy rozpoczac gre
					k.komunik("czy_rozpoczac");
					odp = k.odpowiedz();
					if (odp == 'T' || odp == 't'){
						dzialanie = 2; //idzie do stanu inicjalizacji stolu
					}
					else if (odp == 'N' || odp == 'n'){
						dzialanie = 3; //idzie do stanu zegnaj i konczy gre
					}
					else{
						dzialanie = 4; //idzie do stanu zwracajacego blad
					}
					break;

				case 3: // komunikat zegnaj
					k.komunik("zegnaj");
					kontynuowac = false;
					break;

				case 4: // komunikat bledu
					throw Cblad(505, false, "Nie przewidziano takiej odpowiedzi\n");
					dzialanie = 1;
					break;

				case 2: //stan inicjalizacji zmiennych stolu
					k.moj_stol.zeruj_punkty();
					k.moj_stol.moja_talia.tasuj_talie();
					for (int i = 0; i<2; i++){ k.kolejna_karta("krupier"); }
					for (int i = 0; i<2; i++){ k.kolejna_karta("gracz"); }
					k.moj_stol.pokaz_co_na_stole("gracz");
					k.oblicz_punkty();
					k.powiedz_punkty("gracz");
					dzialanie = 5; //idzie do stanu pytania czy gracz dobiera karte
					break;

				case 5: // stan pytania czy gracz dobiera karte
					k.komunik("czy_dobiera");
					odp = k.odpowiedz();
					if (odp == 'T' || odp == 't'){
						dzialanie = 6; //idzie do stanu dobierania przez gracza
					}
					else if (odp == 'N' || odp == 'n'){
						dzialanie = 7; // idzie do stanu dobierania krupiera
					}
					else{
						dzialanie = 4;
					}
					break;

				case 6: //gracz dostaje nowa karte
					k.kolejna_karta("gracz");
					k.moj_stol.pokaz_co_na_stole("gracz");
					k.oblicz_punkty();
					k.powiedz_punkty("gracz");
					dzialanie = 8; // sprawdz punkty gracza
					break;

				case 8: //stan sprawdza punkty gracza
					if (k.moj_stol.punkty_gracza >21){
						dzialanie = 9; //idzie do stanu zwracajacego przegrana
					}
					else if (k.moj_stol.punkty_gracza == 21){
						dzialanie = 11;//idzie do stanu zwracajacego wygrana
					}
					else{
						dzialanie = 5; //idzie do stanu pytania czy dobrac kolejna karte
					}
					break;

				case 9: //informuje o przegranej
					k.komunik("przegrana");
					dzialanie = 1; // idzie do stanu poczatkowego
					break;

				case 11:
					k.komunik("wygrana");
					dzialanie = 1; // idzie do stanu poczatkowego
					break;

				case 7: //stan dobierania krupiera
					k.kolejna_karta("krupier");
					k.moj_stol.pokaz_co_na_stole("krupier");
					k.oblicz_punkty();
					k.powiedz_punkty("krupier");
					dzialanie = 10; //idzie do stanu sprawdzania punktow krupiera
					break;

				case 10: //stan sprawdza punkty krupiera
					if (k.moj_stol.punkty_krupiera >21){
						dzialanie = 11; //idzie do stanu zwracajacego wygrana gracza
					}
					else if (k.moj_stol.punkty_krupiera <= 21 && k.moj_stol.punkty_krupiera > k.moj_stol.punkty_gracza){
						dzialanie = 9; //idzie do stanu zwracajacego przegrana gracza
					}
					else{
						dzialanie = 7;
					}
					break;
				}
			}
			catch (Cblad blad){
				blad.komunikuj();
				dzialanie = 1;
			}
		}
	
	return 0;
}