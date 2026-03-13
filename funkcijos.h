#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "lib.h"
#include "struktura.h"

bool ar_valid (const string &input);
int meniu();
int mok_sk_ivedimas();
void pazymiu_ivedimas(vector<Studentas> &S, int i);
int egz_ivedimas();
double vidurkis(vector<Studentas> &S, int i, int paz_sk);
void mokinio_info_ivedimas(vector<Studentas> &S, int mok_sk);
int paz_sk_ivedimas();
string med_ar_vid();
void isvedimas(vector<Studentas> S);
void pasirinkimas2(vector<Studentas> &S, int meniu_pasirinkimas);
void pasirinkimas3(vector<Studentas> &S, int meniu_pasirinkimas);
string rnd_vardas(bool vyras);
string rnd_pavarde(bool vyras);
void failo_generavimas();
void ivedimas_is_failo(vector<Studentas> &S, int meniu_pasirinkimas);
void rusiavimas(vector<Studentas> &S);
void isvedimas_i_faila(std::vector<Studentas> S);
void test_failu_generavimas();
void antras_tyrimas();

#endif
