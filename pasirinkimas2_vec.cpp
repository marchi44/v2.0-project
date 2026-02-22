#include "funkcijos.h"
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <algorithm>

void pasirinkimas2(vector<Studentas> &S){
    std::cin.ignore(10000, '\n');
    int mok_sk = mok_sk_ivedimas();
    if(mok_sk > 0){
        S.reserve(S.size() + mok_sk);
    }
    else {
        S.reserve(S.size() + 10000);
    }
    int i = 0;
    std::string eil, vrd, pvrd;
    std::cin.ignore(10000, '\n');
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
        i++;
    }
    std::cout << "Generuojami pazymiai...\n";
    srand(time(NULL));
    for(auto& s : S){
        int n = rand() % 100 + 1; //pazymiu skaicius nuo 1 iki 100
        s.nd_rez.reserve(s.nd_rez.size() + n);
        for(int i = 0; i < n; i++){
            int rnd_paz = rand() % 10 + 1;
            s.nd_rez.push_back(rnd_paz);
        }
        s.egz_rez = rand() % 10 + 1;
    }
    for(size_t i = 0; i < S.size(); i++){
        int paz_sk = S[i].nd_rez.size();
        S[i].vidurkis = vidurkis(S, i, paz_sk);
    }
    string metodas = med_ar_vid();
    for (auto& s : S) {
            if (metodas == "vid") {
                s.galutinis = 0.4 * s.vidurkis + 0.6 * static_cast<double>(s.egz_rez);
            }
            else
            {
                std::sort(s.nd_rez.begin(), s.nd_rez.end());
                if (s.nd_rez.size() % 2 == 0) {
                    s.mediana = (s.nd_rez[s.nd_rez.size() / 2] + s.nd_rez[s.nd_rez.size() / 2 - 1]) / 2.0;
                }
                else {
                s.mediana = s.nd_rez[s.nd_rez.size() / 2];
                }
                s.galutinis = 0.4 * s.mediana + 0.6 * static_cast<double>(s.egz_rez);
            }
        }
    isvedimas(S, metodas);
}