#include <iostream>
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include "ArrayList.h"

using namespace std;
using namespace std::chrono;

// Zwykłe tablice zamiast std::vector
const unsigned int SEEDS[] = {123, 456, 789, 1011, 1314, 1617, 1920, 2223, 2526, 2829};
const int SIZES[] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000};

int bigRand() {
    return (static_cast<int>(rand()) << 15) | rand();
}

int main() {
    cout << "Pomiary (srednia z 10 seedow) w nanosekundach:\n";
    cout << "--------------------------------------------------------------------------------------------------\n";
    cout << setw(8) << "Rozmiar" << " | " 
         << setw(10) << "AddFront" << " | " 
         << setw(10) << "AddBack" << " | " 
         << setw(10) << "AddRand" << " | " 
         << setw(10) << "RemFront" << " | " 
         << setw(10) << "RemBack" << " | " 
         << setw(10) << "RemRand" << " | " 
         << setw(10) << "Search" << endl;
    cout << "--------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < 8; ++i) { // Dla każdego z 8 rozmiarów
        int currentSize = SIZES[i];
        
        long long sumAddF = 0, sumAddB = 0, sumAddR = 0;
        long long sumRemF = 0, sumRemB = 0, sumRemR = 0;
        long long sumSearch = 0;

        for (int j = 0; j < 10; ++j) { // Dla każdego z 10 seedów
            srand(SEEDS[j]);
            ArrayList arr(currentSize);

            // 1. Wypełnianie tablicy do zadanego rozmiaru
            for (int k = 0; k < currentSize; ++k) {
                arr.dodKon(rand());
            }

            // Losujemy dane do testów
            int val = rand();
            int randIdx = bigRand() % currentSize;

            // --- POMIARY DODAWANIA ---
            auto start = high_resolution_clock::now();
            arr.dodPocz(val);
            sumAddF += duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();
            arr.usunPocz(); // Przywrócenie rozmiaru

            start = high_resolution_clock::now();
            arr.dodKon(val);
            sumAddB += duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();
            arr.usunKon();

            start = high_resolution_clock::now();
            arr.dodNa(randIdx, val);
            sumAddR += duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();
            arr.usunNa(randIdx);

            // --- POMIAR WYSZUKIWANIA ---
            int searchVal = rand();
            start = high_resolution_clock::now();
            arr.wyszukaj(searchVal);
            sumSearch += duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();

            // --- POMIARY USUWANIA ---
            start = high_resolution_clock::now();
            arr.usunPocz();
            sumRemF += duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();
            arr.dodPocz(val);

            start = high_resolution_clock::now();
            arr.usunKon();
            sumRemB += duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();
            arr.dodKon(val);

            start = high_resolution_clock::now();
            arr.usunNa(randIdx);
            sumRemR += duration_cast<nanoseconds>(high_resolution_clock::now() - start).count();
        }

        // Wypisanie średniej (dzielone przez 10)
        cout << setw(8) << currentSize << " | "
             << setw(10) << sumAddF / 10 << " | "
             << setw(10) << sumAddB / 10 << " | "
             << setw(10) << sumAddR / 10 << " | "
             << setw(10) << sumRemF / 10 << " | "
             << setw(10) << sumRemB / 10 << " | "
             << setw(10) << sumRemR / 10 << " | "
             << setw(10) << sumSearch / 10 << endl;
    }

    return 0;
}