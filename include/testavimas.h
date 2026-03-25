#ifndef TESTAVIMAS_H
#define TESTAVIMAS_H

#include "lib.h"
#include "struktura.h"

template<typename Container>
void antras_tyrimas(){
    int dydziai [] = {1000, 10000, 100000, 1000000, 10000000};
    for(const int& dydis : dydziai){
        string path = "test_" + std::to_string(dydis) + ".txt";
        cout << "Skaitomas failas " << path << "...\n";
        auto start_nusk = std::chrono::high_resolution_clock::now();
        std::ifstream in(path);
        if(!in){
            std::cerr << "Klaida! Nepavyko atidaryti failo " << path << "...\n";
            continue;
        }
        Container S;
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
    Container Dundukai;
    Container Galvociai;
    for (auto& s : S) {
        s.vidurkis = vidurkis(s, s.nd_rez.size());
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
        if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
            rusiavimas_list(S, 1, 3);
        }    
        else {
            rusiavimas(S, 1, 3);
        }
        for(auto& s : S){
            if(s.galutinis_vid >= 5.0){
                Galvociai.push_back(s);
            }
            else {
                Dundukai.push_back(s);
            }
        }
        auto end_grupe = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_grupe = end_grupe - start_grupe;
        cout << std::fixed << std::setprecision(6) << dydis << " studentu surusiuoti i dvi grupes per " << elapsed_grupe.count() << " s\n";
        auto start_isv = std::chrono::high_resolution_clock::now();
        isvedimas_i_faila(Dundukai, Galvociai);
        auto end_isv = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_isv = end_isv - start_isv;

        cout << std::fixed << std::setprecision(6) << dydis << " studentu isvesti i skirtingus failus pagal grupes per " << elapsed_isv.count() << " s\n";
        cout << std::fixed << std::setprecision(6) << "Visas procesas su " << dydis << " studentu uztruko " << elapsed_nusk.count() + elapsed_grupe.count() + elapsed_isv.count() << " s\n";
        cout << std::endl << std::endl;
    }
}
#endif