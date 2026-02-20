#include "funkcijos.h"
#include <sstream>
#include <string>
#include <iostream>

void mokinio_info_ivedimas(std::vector<Studentas> &S, int mok_sk, int paz_sk){

    int i = 0;
    std::string input, eil, vrd, pvrd;

    while(true){

        // jei kiekis zinomas ir jau uzpildyta
        if(mok_sk != 0 && i >= mok_sk){
            break;
        }

        std::cout << "Iveskite " << i+1 << "-ojo mokinio varda ir pavarde. Tuscia eilute - baigti\n";
        std::cin.ignore();
        std::getline(std::cin, eil);

        // jei kiekis nezinomas ir ivedimas baigtas su tuscia eilute
        if(mok_sk == 0 && eil.empty()){
            break;
        }

        std::stringstream ss(eil);

        if(!(ss >> vrd >> pvrd)){
            std::cout << "Klaida! Turite ivesti varda ir pavarde...\n";
            continue;
        }

        S.push_back(Studentas{vrd, pvrd});
        //mokinio nd pazymiu ivedimas
        bool nezinomas_kiek = false;
        bool baigta = false;
        if(paz_sk == 0)
        {
            nezinomas_kiek = true;
            paz_sk = 1;
        }
        std::cout << "Iveskite mokinio " << S[i].Vardas << " " << S[i].Pavarde << "namu darbu rezultatus (0 - baigti, jei kiekis nezinomas): \n";
            for (int j = 0; j < paz_sk; j++) {
                while (true) {
                    std::cin >> input;
                    if(!ar_valid(input))
                    {
                        std::cout << "Klaida! Jusu ivestas pazymys privalo buti sveikas skaicius (1-10). Bandykite is naujo...\n";
                        std::cin.clear();
                        continue;
                    }
                    if(nezinomas_kiek && stoi(input) == 0)
                    {
                        baigta = true;
                        break;
                    }
                    if ((stoi(input) > 0) && (stoi(input) <= 10)) {
                        S[i].nd_rez.push_back(stoi(input));
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
            for (const int paz : S[i].nd_rez) {
                paz_suma += paz;
            }
            S[i].vidurkis = static_cast<double>(paz_suma) / static_cast<double>(paz_sk);
            //egzamino rezultato ivedimas
            std::cout << "Iveskite mokinio " <<  S[i].Vardas << " " << S[i].Pavarde  << " egzamino rezultata: \n";
            while (true) {
                std::cin >> input;
                bool valid = !input.empty();
                if(valid){
                    valid = ar_valid(input);
                }
                if (valid && (stoi(input) > 0) && (stoi(input) <= 10)) {
                    S[i].egz_rez = stoi(input);
                    break;
                }
                std::cout << "Klaida! Jusu ivestas pazymys privalo buti sveikas skaicius (1-10). Bandykite is naujo...\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
            //
            i++;
    }
}