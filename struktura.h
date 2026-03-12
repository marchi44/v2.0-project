#ifndef STRUKTURA_H
#define STRUKTURA_H

#include "lib.h"
enum Grupe{
    dundukai,
    galvociai
};
struct Studentas {
    std::string Vardas;
    std::string Pavarde;
    Grupe grupe;
    vector<int> nd_rez;
    int egz_rez;
    double vidurkis;
    double mediana;
    double galutinis_vid;
    double galutinis_med;
};

#endif