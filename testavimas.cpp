#include "lib.h"
#include "funkcijos.h"
#include "struktura.h"
#include <chrono>

void test_failu_generavimas(){
    int dydziai [] = {1000, 10000, 100000, 1000000, 10000000};
    for(const int& dydis : dydziai){
        int mok_sk = dydis;
        string path = "test_" + std::to_string(dydis) + ".txt";
        cout << "Generuojamas failas " << path << " su " << mok_sk << " mokiniu...\n";
        auto start = std::chrono::high_resolution_clock::now();
        std::ofstream out(path);
        out << std::left << std::setw(15) << "Vardas" << std::setw(25) << "Pavarde" << std::setw(5) << "ND1" << std::setw(5) << "ND2" << std::setw(5) << "ND3" << std::setw(5) << "ND4" << std::setw(5) << "ND5" << std::setw(10) << "Egzaminas\n";
        for (int i = 0; i < mok_sk; i++) {
            bool lytis = rand() % 2;
            out << std::setw(15) << rnd_vardas(lytis) << std::setw(25) << rnd_pavarde(lytis) << " ";
            int paz_sk = rand() % 5 + 1;
            for (int j = 0; j < paz_sk; j++) {
                out << std::setw(5) << rand() % 10 + 1;
            }
            for (int j = paz_sk; j < 5; j++) {
                out << std::setw(5) << " ";
            }
            out << std::setw(10) << rand() % 10 + 1 << "\n";
        }
        out.close();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        cout << "Failas " << path << " sukurtas per " << elapsed.count() << " s\n";
    }
}
void antras_tyrimas(){
    int dydziai [] = {1000, 10000, 100000, 1000000, 10000000};
    for(const int& dydis : dydziai){
        string path = "test_" + std::to_string(dydis) + ".txt";
        cout << "Skaitomas failas " << path << "...\n";
        auto start_nusk = std::chrono::high_resolution_clock::now();
        std::ifstream in(path);
        vector<Studentas> S;
        S.reserve(S.size() + dydis);
        string eil;
        getline(in, eil); // praleiziama header
        while(getline(in, eil)){
            if(eil.empty()){
                continue;
            }
            std::istringstream ss(eil);
            int paz;
            Studentas tmp;
            ss >> tmp.Vardas >> tmp.Pavarde;
            while(ss >> paz){
                if(paz > 0 && paz <= 10){
                    tmp.nd_rez.push_back(paz);
                }
        }
        if(!tmp.nd_rez.empty()){
            tmp.egz_rez = tmp.nd_rez.back();
            tmp.nd_rez.pop_back();
        }
        S.push_back(tmp);
    }
    in.close();
    auto end_nusk = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_nusk = end_nusk - start_nusk;
    cout << std::fixed << std::setprecision(6) << "Failas su " << dydis << " studentu nuskaitytas per " << elapsed_nusk.count() << " s\n";
    auto start_grupe = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < S.size(); i++) {
        S[i].vidurkis = vidurkis(S, i, S[i].nd_rez.size());
        std::sort(S[i].nd_rez.begin(), S[i].nd_rez.end());
        if (S[i].nd_rez.size() % 2 == 0) {
            S[i].mediana = (S[i].nd_rez[S[i].nd_rez.size() / 2] + S[i].nd_rez[S[i].nd_rez.size() / 2 - 1]) / 2.0;
            }
        else {
            S[i].mediana = S[i].nd_rez[S[i].nd_rez.size() / 2];
            }
            S[i].galutinis_vid = 0.4 * S[i].vidurkis + 0.6 * static_cast<double>(S[i].egz_rez);
            S[i].galutinis_med = 0.4 * S[i].mediana + 0.6 * static_cast<double>(S[i].egz_rez);
            if(S[i].galutinis_vid >= 5.0){
                S[i].grupe = galvociai;
            }
            else{
                S[i].grupe = dundukai;
            }
        }
        auto end_grupe = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_grupe = end_grupe - start_grupe;
        cout << std::fixed << std::setprecision(6) << dydis << " studentu surusiuoti i dvi grupes per " << elapsed_grupe.count() << " s\n";
        auto start_isv = std::chrono::high_resolution_clock::now();
        rusiavimas(S, 1, 3);
        isvedimas_i_faila(S);
        auto end_isv = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_isv = end_isv - start_isv;
        cout << std::fixed << std::setprecision(6) << dydis << " studentu isvesti i skirtingus failus pagal grupes per " << elapsed_isv.count() << " s\n";
        cout << std::fixed << std::setprecision(6) << "Visas procesas su " << dydis << " studentu uztruko " << elapsed_nusk.count() + elapsed_grupe.count() + elapsed_isv.count() << " s\n";
        cout << std::endl << std::endl;
    }
}