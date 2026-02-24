#include "funkcijos.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>

void pasirinkimas1_arr(){
    int mok_sk = mok_sk_ivedimas();
    int kiek_mok = 0;
    std::string metodas;
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
        int paz_sk = paz_sk_ivedimas();
        bool nezinomas_kiek = false;
        bool baigta = false;
        if(paz_sk > 0){
            S[i].pazymiu_sk = paz_sk;
        }
        else {
            S[i].pazymiu_sk = 100;
            nezinomas_kiek = true;
            paz_sk = 1;
        }
        S[i].nd_paz = new int[S[i].pazymiu_sk];
        int kiek = 0;
        int dydis = S[i].pazymiu_sk;
        std::cout << "Iveskite mokinio namu darbu rezultatus (0 - baigti, jei kiekis nezinomas): \n";
            for (int j = 0; j < paz_sk; j++) {
                while (true) {
                    std::string input;
                    std::cin >> input;
                    std::cin.ignore(10000, '\n');
                    if (kiek == dydis && nezinomas_kiek) {
                        dydis *= 2;
                        int *temp = new int[dydis];
                        for(int k = 0; k < kiek; k++)
                            temp[k] = S[i].nd_paz[k];
                        delete[] S[i].nd_paz;
                        S[i].nd_paz = temp;
                    }
                    if(!ar_valid(input))
                    {
                        std::cout << "Klaida! Jusu ivestas pazymys privalo buti sveikas skaicius (1-10). Bandykite is naujo...\n";
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        continue;
                    }
                    if(nezinomas_kiek && stoi(input) == 0)
                    {
                        baigta = true;
                        break;
                    }
                    if ((stoi(input) > 0) && (stoi(input) <= 10)) {
                        S[i].nd_paz[kiek] = stoi(input);
                        kiek++;
                        break;
                    }
                        std::cout << "Klaida! Jusu ivestas pazymys privalo buti sveikas skaicius (1-10). Bandykite is naujo...\n";
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                }
                if(baigta){
                    break;
                }
                else if(nezinomas_kiek)
                {
                    paz_sk++;
                }
            }
        //vidurkio apskaiciavimas
        int paz_suma = 0;
        for(int j = 0; j < kiek; j++){
            paz_suma += S[i].nd_paz[j];
        }
        if(kiek > 0)
            S[i].vidurkis = static_cast<double>(paz_suma) / kiek;
        else
            S[i].vidurkis = 0;
        //egzamino rezultato ivedimas
        S[i].egz_rez = egz_ivedimas();
        metodas = med_ar_vid();
        if (metodas == "vid") {
                S[i].galutinis = 0.4 * S[i].vidurkis + 0.6 * static_cast<double>(S[i].egz_rez);
            }
            else
            {
                std::sort(S[i].nd_paz, S[i].nd_paz + kiek);
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