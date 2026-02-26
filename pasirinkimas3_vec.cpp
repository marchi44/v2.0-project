#include "funkcijos.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using std::string;

void pasirinkimas3(vector<Studentas> &S, int meniu_pasirinkimas){
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
        sort(S[i].nd_rez.begin(), S[i].nd_rez.end());
                if (S[i].nd_rez.size() % 2 == 0) {
                    S[i].mediana = (S[i].nd_rez[S[i].nd_rez.size() / 2] + S[i].nd_rez[S[i].nd_rez.size() / 2 - 1]) / 2.0;
                }
                else {
                S[i].mediana = S[i].nd_rez[S[i].nd_rez.size() / 2];
                }
                S[i].galutinis_vid = 0.4 * S[i].vidurkis + 0.6 * static_cast<double>(S[i].egz_rez);
                S[i].galutinis_med = 0.4 * S[i].mediana + 0.6 * static_cast<double>(S[i].egz_rez);
        }
        rusiavimas(S);
        std::cout << "1 - isvesti i konsole, 2 - isvesti i faila\n";
        int kur_isvesti;
        try {
            std::cin >> kur_isvesti;
            std::cin.ignore(10000, '\n');
            if(!std::cin || (kur_isvesti != 1 && kur_isvesti != 2)){
                throw std::runtime_error("Klaida! Neteisingai ivedete rezultatu isvedimo buda...\n");
            }
        }
        catch (const std::exception& e) {
            std::cerr << e.what();
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            return;
        }
        if(kur_isvesti == 1){
        isvedimas(S);
        }
        else{
            isvedimas_i_faila(S);
        }
}