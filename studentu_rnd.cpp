#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "funkcijos.h"

void failo_generavimas() {
    std::ofstream out("kursiokai.txt");
    srand(time(0));
    int mok_sk = rand();
    out << std::left << std::setw(15) << "Vardas" << std::setw(25) << "Pavarde" << std::setw(5) << "ND1" << std::setw(5) << "ND2" << std::setw(5) << "ND3" << std::setw(5) << "ND4" << std::setw(5) << "ND5" << std::setw(10) << "Egzaminas\n";
    for (int i = 0; i < mok_sk; i++) {
        bool lytis = rand() % 2;
        out << std::setw(15) << rnd_vardas(lytis) << std::setw(25) << rnd_pavarde(lytis) << " ";
        int paz_sk = rand() % 5 + 1;
        for (int j = 0; j < paz_sk; j++) {
            out << std::setw(5) << rand() % 10 + 1;
        }
        if(paz_sk < 5){
            for (int j = paz_sk; j < 5; j++) {
                out << std::setw(5) << " ";
            }
        }
        out << std::setw(10) << rand() % 10 + 1 << "\n";
    }
    out.close();
}