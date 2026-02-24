#include "funkcijos.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>

void pasirinkimas2_arr(){
    srand(time(NULL));
    std::string metodas = med_ar_vid();
    int mok_sk = mok_sk_ivedimas();
    int kiek_mok = 0;
    Studentas *S = nullptr;
    int n = 100;
    if(mok_sk > 0){
        S = new Studentas[mok_sk];
    }
    else {
        S = new Studentas[n];
    }
    int i = 0;
    std::string eil, vrd, pvrd;

    while(true){

        // jei kiekis zinomas ir jau uzpildyta
        if(mok_sk != 0 && i >= mok_sk){
            break;
        }
        // jei reikia padidinti masyva
        if (i == n && mok_sk == 0) {
            n *= 2;
            Studentas *temp = new Studentas[n];
            for(int j = 0; j < i; j++)
                temp[j] = S[j];
            delete[] S;
            S = temp;
        }
        std::cout << "Iveskite " << i+1 << "-ojo mokinio varda ir pavarde. Tuscia eilute - baigti\n";
        std::getline(std::cin, eil);

        // jei kiekis nezinomas ir ivedimas baigtas su tuscia eilute
        if(mok_sk == 0 && eil.empty() && i != 0){
            break;
        }

        std::stringstream ss(eil);

        if(!(ss >> vrd >> pvrd)){
            std::cout << "Klaida! Turite ivesti varda ir pavarde...\n";
            std::cin.clear();
            continue;
        }
        kiek_mok++;
        S[i].Vardas = vrd;
        S[i].Pavarde = pvrd;
        //mokinio nd pazymiu ivedimas
        std::cout << "Generuojami pazymiai...\n";
        int k = rand() % 100 + 1; //pazymiu skaicius nuo 1 iki 100
        S[i].pazymiu_sk = k;
        S[i].nd_paz = new int[k];
        for(int j = 0; j < k; j++){
            int rnd_paz = rand() % 10 + 1;
            S[i].nd_paz[j] = rnd_paz;
        }
        S[i].egz_rez = rand() % 10 + 1;
        //vidurkio apskaiciavimas
        int paz_suma = 0;
        for(int j = 0; j < S[i].pazymiu_sk; j++){
            paz_suma += S[i].nd_paz[j];
        }
        if(S[i].pazymiu_sk > 0)
            S[i].vidurkis = static_cast<double>(paz_suma) / S[i].pazymiu_sk;
        else
            S[i].vidurkis = 0;

        if (metodas == "vid") {
                S[i].galutinis = 0.4 * S[i].vidurkis + 0.6 * static_cast<double>(S[i].egz_rez);
            }
            else
            {
                std::sort(S[i].nd_paz, S[i].nd_paz + S[i].pazymiu_sk);
                int kiek = S[i].pazymiu_sk;
                if (kiek % 2 == 0) {
                    S[i].mediana = (S[i].nd_paz[kiek / 2] + S[i].nd_paz[kiek / 2 - 1]) / 2.0;
                }
                else {
                S[i].mediana = S[i].nd_paz[kiek / 2];
                }
                S[i].galutinis = 0.4 * S[i].mediana + 0.6 * static_cast<double>(S[i].egz_rez);
            }
            i++;
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
    for (int i = 0; i < kiek_mok; i++) {
        std::cout << std::left << std::setw(25) << S[i].Pavarde << std::left << std::setw(15) << S[i].Vardas << std::left << std::setw(18) << std::fixed << std::setprecision(2) << S[i].galutinis << std::endl;
    }
    for(int j = 0; j < kiek_mok; j++){
    delete[] S[j].nd_paz;
    }
    delete[] S;
}