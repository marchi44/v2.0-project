#include "funkcijos.h"
#include "lib.h"

void mokinio_info_ivedimas(std::vector<Studentas> &S, int mok_sk){

    int i = 0;
    std::string eil, vrd, pvrd;
    if(mok_sk > 0){
    S.reserve(S.size() + mok_sk);
    }
    else {
        S.reserve(S.size() + 10000);
    }

    while(true){

        // jei kiekis zinomas ir jau uzpildyta
        if(mok_sk != 0 && i >= mok_sk){
            break;
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

        S.push_back(Studentas{vrd, pvrd});
        //mokinio nd pazymiu ivedimas
        int paz_sk;
        pazymiu_ivedimas(S, i);
        //vidurkio apskaiciavimas
        S[i].vidurkis = vidurkis(S, i, paz_sk);
        //egzamino rezultato ivedimas
        S[i].egz_rez = egz_ivedimas();
        i++;
    }
}