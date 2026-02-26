#include "funkcijos.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

void pasirinkimas3(vector<Studentas> &S, int meniu_pasirinkimas){
    //string metodas = med_ar_vid();
    std::cout << "Generuojami studentu vardai ir pavardes...\n";
    int mok_sk = rand() % 100 + 1;
    S.reserve(S.size() + mok_sk);
    for(int i = 0; i < mok_sk; i++){
        bool vyras = rand() % 2;
        string vardas = rnd_vardas(vyras);
        string pavarde = rnd_pavarde(vyras);
        S.push_back(Studentas{vardas, pavarde});
        std::cout << "Generuojami " << i+1 << "-ojo studento pazymiai...\n";
        int n = rand() % 100 + 1; //pazymiu skaicius nuo 1 iki 100
        S[i].nd_rez.reserve(S[i].nd_rez.size() + n);
        for(int j = 0; j < n; j++){
            int rnd_paz = rand() % 10 + 1;
            S[i].nd_rez.push_back(rnd_paz);
        }
        S[i].egz_rez = rand() % 10 + 1;
        int paz_sk = S[i].nd_rez.size();
        S[i].vidurkis = vidurkis(S, i, paz_sk);
        for (auto& s : S) {
                std::sort(s.nd_rez.begin(), s.nd_rez.end());
                if (s.nd_rez.size() % 2 == 0) {
                    s.mediana = (s.nd_rez[s.nd_rez.size() / 2] + s.nd_rez[s.nd_rez.size() / 2 - 1]) / 2.0;
                }
                else {
                s.mediana = s.nd_rez[s.nd_rez.size() / 2];
                }
                s.galutinis_vid = 0.4 * s.vidurkis + 0.6 * static_cast<double>(s.egz_rez);
                s.galutinis_med = 0.4 * s.mediana + 0.6 * static_cast<double>(s.egz_rez);
        }
        }
        rusiavimas(S);
        isvedimas(S);
}