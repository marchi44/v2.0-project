#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

struct Studentas {
    string Vardas;
    string Pavarde;
    vector<int> nd_rez;
    int egz_rez;
    double vidurkis;
    double mediana;
    double galutinis;
};

bool ar_valid (const string &input);
int meniu();
int mok_sk_ivedimas();
#endif
