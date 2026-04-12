#include <iostream>
#include <chrono>
#include <iomanip>
#include <string>
#include <random>

#include "ArrayList.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

using namespace std;
using namespace std::chrono;

//tablice z seedami oraz rozmiarami

const unsigned int seedy[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const int rozmiary[] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000};

void testArrayList() {
    cout << "\nTABLICA DYNAMICZNA:\n";

    for (int i = 0; i < 8; ++i) {
        int rozmiar = rozmiary[i];
        long long dodPocz = 0, dodKon = 0, dodNa = 0;
        long long usunPocz = 0, usunKon = 0, usunNa = 0, wyszukiwanie = 0;

        for (int j = 0; j < 10; ++j) {

            //generowanie liczb
            
            mt19937 gen(seedy[j]);
            uniform_int_distribution<int> zakres_wartosci(0, 100000);
            uniform_int_distribution<int> indeksy(0, rozmiar - 1);

            int* danePoczatkowe = new int[rozmiar];
            for (int k = 0; k < rozmiar; ++k) danePoczatkowe[k] = zakres_wartosci(gen);

            int wartosc = zakres_wartosci(gen);
            int losowy_index = indeksy(gen);
            int szukana_wartosc = zakres_wartosci(gen);

            //tworzenie 300 takich samych struktur

            ArrayList kopie[300];
            for (int k = 0; k < 300; ++k) {
                for (int m = 0; m < rozmiar; ++m) {
                    kopie[k].dodKon(danePoczatkowe[m]);
                }
            }
            delete[] danePoczatkowe;

            //dodawanie na początek

            auto start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].dodPocz(wartosc);
            auto koniec = high_resolution_clock::now();
            dodPocz += duration_cast<nanoseconds>(koniec - start).count() / 300;
            for (int k = 0; k < 300; ++k) kopie[k].usunPocz();

            //dodawanie na koniec

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].dodKon(wartosc);
            koniec = high_resolution_clock::now();
            dodKon += duration_cast<nanoseconds>(koniec - start).count() / 300;
            for (int k = 0; k < 300; ++k) kopie[k].usunKon();

            //dodawanie w danym miejscu

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].dodNa(losowy_index, wartosc);
            koniec = high_resolution_clock::now();
            dodNa += duration_cast<nanoseconds>(koniec - start).count() / 300;
            for (int k = 0; k < 300; ++k) kopie[k].usunNa(losowy_index);

            //wyszukiwanie

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].wyszukaj(szukana_wartosc);
            koniec = high_resolution_clock::now();
            wyszukiwanie += duration_cast<nanoseconds>(koniec - start).count() / 300;

            //usuwanie na początku

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].usunPocz();
            koniec = high_resolution_clock::now();
            usunPocz += duration_cast<nanoseconds>(koniec - start).count() / 300;
            for (int k = 0; k < 300; ++k) kopie[k].dodPocz(wartosc);

            //usuwanie na końcu

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].usunKon();
            koniec = high_resolution_clock::now();
            usunKon += duration_cast<nanoseconds>(koniec - start).count() / 300;
            for (int k = 0; k < 300; ++k) kopie[k].dodKon(wartosc);

            //usuwanie w danym miejscu

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].usunNa(losowy_index);
            koniec = high_resolution_clock::now();
            usunNa += duration_cast<nanoseconds>(koniec - start).count() / 300;
        }

        //wypisanie statystyk

        cout << "\nSTATYSTKI DLA N = " << rozmiar << endl;
        cout << "\nDODAWANIA:\n";
        cout << "Dodawanie na poczatku: " << dodPocz / 10 << "\nDodawanie na koncu: " << dodKon / 10 << "\nDodawanie w danym miejscu: " << dodNa / 10 << endl;
        cout << "\nODEJMOWANIA:\n";
        cout << "Usuwanie na poczatku: " << usunPocz / 10 << "\nUsuwanie na koncu: " << usunKon / 10 << "\nUsuwanie w danym miejscu: " << usunNa / 10 << endl;
        cout << "\nWYSZUKIWANIE: " << wyszukiwanie / 10 << endl;
    }
    cout << "\n--------------------------------\n";
}

//Struktury następnych funkcji są zrobione w taki sam sposób co poprzednia

void testSinglyLinkedList() {
    cout << "\nLISTA JEDNOKIERUNKOWA:\n";

    for (int i = 0; i < 8; ++i) {
        int rozmiar = rozmiary[i];
        long long dodPocz = 0, dodKon = 0, dodNa = 0;
        long long usunPocz = 0, usunKon = 0, usunNa = 0, wyszukiwanie = 0;

        for (int j = 0; j < 10; ++j) {
            mt19937 gen(seedy[j]);
            uniform_int_distribution<int> zakres_wartosci(0, 1000000000);
            uniform_int_distribution<int> indeksy(0, rozmiar - 1);

            int* danePoczatkowe = new int[rozmiar];
            for (int k = 0; k < rozmiar; ++k) danePoczatkowe[k] = zakres_wartosci(gen);

            int wartosc = zakres_wartosci(gen);
            int losowy_index = indeksy(gen);
            int szukana_wartosc = zakres_wartosci(gen);

            SinglyLinkedList kopie[300];
            for (int k = 0; k < 300; ++k) {
                for (int m = 0; m < rozmiar; ++m) {
                    kopie[k].addAtEnd(danePoczatkowe[m]);
                }
            }
            delete[] danePoczatkowe;

            auto start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].addAtBeginning(wartosc);
            auto koniec = high_resolution_clock::now();
            dodPocz += duration_cast<nanoseconds>(koniec - start).count() / 300;
            for (int k = 0; k < 300; ++k) kopie[k].removeAtBeginning();

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].addAtEnd(wartosc);
            koniec = high_resolution_clock::now();
            dodKon += duration_cast<nanoseconds>(koniec - start).count() / 300;
            for (int k = 0; k < 300; ++k) kopie[k].removeAtEnd();

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].addAtPos(losowy_index, wartosc);
            koniec = high_resolution_clock::now();
            dodNa += duration_cast<nanoseconds>(koniec - start).count() / 300;
            for (int k = 0; k < 300; ++k) kopie[k].removeAtPos(losowy_index);

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].find(szukana_wartosc);
            koniec = high_resolution_clock::now();
            wyszukiwanie += duration_cast<nanoseconds>(koniec - start).count() / 300;

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].removeAtBeginning();
            koniec = high_resolution_clock::now();
            usunPocz += duration_cast<nanoseconds>(koniec - start).count() / 300;
            for (int k = 0; k < 300; ++k) kopie[k].addAtBeginning(wartosc);

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].removeAtEnd();
            koniec = high_resolution_clock::now();
            usunKon += duration_cast<nanoseconds>(koniec - start).count() / 300;
            for (int k = 0; k < 300; ++k) kopie[k].addAtEnd(wartosc);

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].removeAtPos(losowy_index);
            koniec = high_resolution_clock::now();
            usunNa += duration_cast<nanoseconds>(koniec - start).count() / 300;
        }

        cout << "\nSTATYSTKI DLA N = " << rozmiar << endl;
        cout << "\nDODAWANIA:\n";
        cout << "Dodawanie na poczatku: " << dodPocz / 10 << "\nDodawanie na koncu: " << dodKon / 10 << "\nDodawanie w danym miejscu: " << dodNa / 10 << endl;
        cout << "\nODEJMOWANIA:\n";
        cout << "Usuwanie na poczatku: " << usunPocz / 10 << "\nUsuwanie na koncu: " << usunKon / 10 << "\nUsuwanie w danym miejscu: " << usunNa / 10 << endl;
        cout << "\nWYSZUKIWANIE: " << wyszukiwanie / 10 << endl;
    }
    cout << "\n--------------------------------\n";
}

void testDoublyLinkedList() {
    cout << "\nLISTA DWUKIERUNKOWA:\n";

    for (int i = 0; i < 8; ++i) {
        int rozmiar = rozmiary[i];
        long long dodPocz = 0, dodKon = 0, dodNa = 0;
        long long usunPocz = 0, usunKon = 0, usunNa = 0, wyszukiwanie = 0;

        for (int j = 0; j < 10; ++j) {
            mt19937 gen(seedy[j]);
            uniform_int_distribution<int> zakres_wartosci(0, 1000000000);
            uniform_int_distribution<int> indeksy(0, rozmiar - 1);

            int* danePoczatkowe = new int[rozmiar];
            for (int k = 0; k < rozmiar; ++k) danePoczatkowe[k] = zakres_wartosci(gen);

            int wartosc = zakres_wartosci(gen);
            int losowy_index = indeksy(gen);
            int szukana_wartosc = zakres_wartosci(gen);

            DoublyLinkedList kopie[300];
            for (int k = 0; k < 300; ++k) {
                for (int m = 0; m < rozmiar; ++m) {
                    kopie[k].addAtEnd(danePoczatkowe[m]);
                }
            }
            delete[] danePoczatkowe;

            auto start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].addAtBeginning(wartosc);
            auto koniec = high_resolution_clock::now();
            dodPocz += duration_cast<nanoseconds>(koniec - start).count() / 300;
            for (int k = 0; k < 300; ++k) kopie[k].removeAtBeginning();

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].addAtEnd(wartosc);
            koniec = high_resolution_clock::now();
            dodKon += duration_cast<nanoseconds>(koniec - start).count() / 300;
            for (int k = 0; k < 300; ++k) kopie[k].removeAtEnd();

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].addAtPos(losowy_index, wartosc);
            koniec = high_resolution_clock::now();
            dodNa += duration_cast<nanoseconds>(koniec - start).count() / 300;
            for (int k = 0; k < 300; ++k) kopie[k].removeAtPos(losowy_index);

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].find(szukana_wartosc);
            koniec = high_resolution_clock::now();
            wyszukiwanie += duration_cast<nanoseconds>(koniec - start).count() / 300;

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].removeAtBeginning();
            koniec = high_resolution_clock::now();
            usunPocz += duration_cast<nanoseconds>(koniec - start).count() / 300;
            for (int k = 0; k < 300; ++k) kopie[k].addAtBeginning(wartosc);

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].removeAtEnd();
            koniec = high_resolution_clock::now();
            usunKon += duration_cast<nanoseconds>(koniec - start).count() / 300;
            for (int k = 0; k < 300; ++k) kopie[k].addAtEnd(wartosc);

            start = high_resolution_clock::now();
            for (int k = 0; k < 300; ++k) kopie[k].removeAtPos(losowy_index);
            koniec = high_resolution_clock::now();
            usunNa += duration_cast<nanoseconds>(koniec - start).count() / 300;

        }

        cout << "\nSTATYSTKI DLA N = " << rozmiar << endl;
        cout << "\nDODAWANIA:\n";
        cout << "Dodawanie na poczatku: " << dodPocz / 10 << "\nDodawanie na koncu: " << dodKon / 10 << "\nDodawanie w danym miejscu: " << dodNa / 10 << endl;
        cout << "\nODEJMOWANIA:\n";
        cout << "Usuwanie na poczatku: " << usunPocz / 10 << "\nUsuwanie na koncu: " << usunKon / 10 << "\nUsuwanie w danym miejscu: " << usunNa / 10 << endl;
        cout << "\nWYSZUKIWANIE: " << wyszukiwanie / 10 << endl;
    }
    cout << "\n--------------------------------\n";
}

//wywołanie funkcji

int main() {
    testArrayList();
    testSinglyLinkedList();
    testDoublyLinkedList();

    return 0;
}