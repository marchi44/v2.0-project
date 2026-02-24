#include "funkcijos.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>

using std::string;

void pasirinkimas3_arr(){
    string metodas = med_ar_vid();
    std::cout << "Generuojami studentu vardai ir pavardes...\n";
    srand(time(NULL));
    int mok_sk = rand() % 100 + 1;
    Studentas *S = new Studentas[mok_sk];
    for(int i = 0; i < mok_sk; i++){
        bool vyras = rand() % 2;
        string vardas = rnd_vardas(vyras);
        string pavarde = rnd_pavarde(vyras);
        S[i].Vardas = vardas;
        S[i].Pavarde = pavarde;
        std::cout << "Generuojami " << i+1 << "-ojo studento pazymiai...\n";
        S[i].pazymiu_sk = rand() % 100 + 1; //pazymiu skaicius nuo 1 iki 100
        S[i].nd_paz = new int[S[i].pazymiu_sk];
        int paz_suma = 0;
        for(int j = 0; j < S[i].pazymiu_sk; j++){
            int rnd_paz = rand() % 10 + 1;
            S[i].nd_paz[j] = rnd_paz;
            paz_suma += rnd_paz;
        }
        S[i].vidurkis = static_cast<double>(paz_suma) / S[i].pazymiu_sk;
        S[i].egz_rez = rand() % 10 + 1;
        
        if (metodas == "vid") {
                S[i].galutinis = 0.4 * S[i].vidurkis + 0.6 * static_cast<double>(S[i].egz_rez);
            }
            else
            {
                std::sort(S[i].nd_paz, S[i].nd_paz + S[i].pazymiu_sk);
                if (S[i].pazymiu_sk % 2 == 0) {
                    S[i].mediana = (S[i].nd_paz[S[i].pazymiu_sk / 2] + S[i].nd_paz[S[i].pazymiu_sk / 2 - 1]) / 2.0;
                }
                else {
                S[i].mediana = S[i].nd_paz[S[i].pazymiu_sk / 2];
                }
                S[i].galutinis = 0.4 * S[i].mediana + 0.6 * static_cast<double>(S[i].egz_rez);
            }
        }
        //isvedimas
        if (metodas == "vid") {
            std::cout << std::left << std::setw(25) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(18) << "Galutinis (Vid.)\n";
        }
        else {
            std::cout << std::left << std::setw(25) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(18) << "Galutinis (Med.)\n";
        }
        for (int i = 0; i < 58; i++) {
            std::cout << "-";
        }
        std::cout << std::endl;
        for (int i = 0; i < mok_sk; i++) {
            std::cout << std::left << std::setw(25) << S[i].Pavarde << std::left << std::setw(15) << S[i].Vardas << std::left << std::setw(18) << std::fixed << std::setprecision(2) << S[i].galutinis << std::endl;
        }
        for(int j = 0; j < mok_sk; j++){
        delete[] S[j].nd_paz;
        }
        delete[] S;
}