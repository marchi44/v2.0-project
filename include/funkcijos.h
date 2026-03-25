#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "lib.h"
#include "struktura.h"

bool ar_valid (const string &input);
int meniu();
int mok_sk_ivedimas();
void pazymiu_ivedimas(Studentas &s);
int egz_ivedimas();
double vidurkis(Studentas &s, int paz_sk);
template<typename Container>
void mokinio_info_ivedimas(Container &S, int mok_sk);
int paz_sk_ivedimas();
string med_ar_vid();
template<typename Container>
void pasirinkimas2(Container &S, int meniu_pasirinkimas);
template<typename Container>
void pasirinkimas3(Container &S, int meniu_pasirinkimas);
string rnd_vardas(bool vyras);
string rnd_pavarde(bool vyras);
void failo_generavimas();
template<typename Container>
void ivedimas_is_failo(Container &S, int meniu_pasirinkimas);
template<typename Container>
void rusiavimas(Container &S, int did_ar_maz, int pagal_ka_rusiuoti);
template<typename Container>
void isvedimas_i_faila(Container Dundukai, Container Galvociai);
void test_failu_generavimas();
template<typename Container>
void antras_tyrimas();
template<typename Container>
void rusiavimo_pasirinkimas(Container &S);
void rusiavimo_pasirinkimas_list(std::list<Studentas> &S);
void rusiavimas_list(std::list<Studentas> &S, int did_ar_maz, int pagal_ka_rusiuoti);
template<typename Container>
void rasyti_i_faila(const Container& grupe, const std::string& failo_pavadinimas);

#include "funkcijos_temp.h"
#include "rusiavimas.h"
#include "testavimas.h"
#endif
