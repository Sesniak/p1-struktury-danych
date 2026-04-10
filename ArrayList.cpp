#include "ArrayList.h"
#include <algorithm>

ArrayList::ArrayList(): rozmiar(2), ilosc_el(0){
    dane = new int[rozmiar];
}

ArrayList::~ArrayList(){
    delete[] dane;
}

//Zmiana rozmiaru

void ArrayList::zmienRozmiar(int nowy_rozmiar){
    int* nowe = new int[nowy_rozmiar];
    for(int i = 0; i < ilosc_el; ++i){
        nowe[i] = dane[i];
    }
    delete[] dane;
    dane = nowe;
    rozmiar = nowy_rozmiar;
}

//Funkcje na dodawanie elementów

void ArrayList::dodPocz(int wartosc){
    if(ilosc_el == rozmiar){
        zmienRozmiar(rozmiar*2);
    }

    for(int i = ilosc_el; i > 0; --i){
        dane[i] = dane[i-1];
    }
    dane[0] = wartosc;
    ilosc_el++;
}

void ArrayList::dodKon(int wartosc){
    if(ilosc_el == rozmiar){
        zmienRozmiar(rozmiar*2);
    }
    dane[ilosc_el] = wartosc;
    ilosc_el++;
}

void ArrayList::dodNa(int gdzie, int wartosc){
    if(gdzie > ilosc_el) return;
    if(gdzie == ilosc_el){
        dodKon(wartosc);
        return;
    }
    if(ilosc_el == rozmiar){
        zmienRozmiar(rozmiar*2);
    }

    for(int i = ilosc_el; i > gdzie; --i){
        dane[i] = dane[i-1];
    }
    dane[gdzie] = wartosc;
    ilosc_el++;
}

// Funkcje na usuwanie elementów

void ArrayList::usunPocz(){
    if(ilosc_el == 0) return;

    for(int i = 0; i < ilosc_el-1; ++i){
        dane[i] = dane[i+1];
    }
    ilosc_el--;
}

void ArrayList::usunKon(){
    if(ilosc_el == 0) return;
    ilosc_el--;
}

void ArrayList::usunNa(int gdzie){
    if(gdzie >= ilosc_el) return;

    for(int i = gdzie; i < ilosc_el-1; ++i){
        dane[i] = dane[i+1];
    }
    ilosc_el--;
}

bool ArrayList::wyszukaj(int wartosc) const{
    for(int i = 0; i < ilosc_el; ++i){
        if(dane[i] == wartosc){
            return true;
        }
    }
    return false;
}

//Funkcje w razie co

int ArrayList::ileEl() const{
    return ilosc_el;
}

void ArrayList::wyczysc(){
    delete[] dane;
    ilosc_el = 0;
    rozmiar = 2;
    dane = new int[rozmiar];
}