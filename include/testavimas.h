#ifndef TESTAVIMAS_H
#define TESTAVIMAS_H

#include "lib.h"
#include "studentas.h"
template<typename Container>
void nuskaitymas(Container &S, const int& dydis){
        string path = "test_" + std::to_string(dydis) + ".txt";
        cout << "Skaitomas failas " << path << "...\n";
        std::ifstream in(path);
        if(!in){
            std::cerr << "Klaida! Nepavyko atidaryti failo " << path << "...\n";
            return;
        }
        string eil;
        getline(in, eil); // praleiziama header
        while(getline(in, eil)){
            if(eil.empty()){
                continue;
            }
            std::istringstream ss(eil);
            int paz, pazSuma = 0;
            Studentas tmp;
            string vrd, pvrd;
            ss >> vrd >> pvrd;
            tmp.setVardas(vrd);
            tmp.setPavarde(pvrd);
            while(ss >> paz){
                if(paz > 0 && paz <= 10){
                    tmp.getNdRez().push_back(paz);
                    pazSuma += paz;
                }
        }
        if(!tmp.getNdRez().empty()){
            tmp.setEgzRez(tmp.getNdRez().back());
            tmp.getNdRez().pop_back();
        }
        tmp.setVidurkis(static_cast<double>(pazSuma - tmp.getEgzRez()) / static_cast<double>(tmp.getNdRez().size()));
        S.push_back(tmp);
    }
    in.close();
}
template<typename Container>
void skaiciavimai(Container &S){
        for (auto& s : S) {
        //s.setVidurkis(vidurkis(s, s.getNdRez().size()));
        std::sort(s.getNdRez().begin(), s.getNdRez().end());
        if (s.getNdRez().size() % 2 == 0) {
            s.setMediana((s.getNdRez()[s.getNdRez().size() / 2] + s.getNdRez()[s.getNdRez().size() / 2 - 1]) / 2.0);
            }
        else {
            s.setMediana(s.getNdRez()[s.getNdRez().size() / 2]);
            }
            s.setGalutinisVid(0.4 * s.getVidurkis() + 0.6 * static_cast<double>(s.getEgzRez()));
            s.setGalutinisMed(0.4 * s.getMediana() + 0.6 * static_cast<double>(s.getEgzRez()));
        }
        rusiavimas(S, 1, 3);
}

template<typename Container>
void antras_tyrimas(){
    int dydziai [] = {1000, 10000, 100000, 1000000, 10000000};
    for(const int& dydis : dydziai){
    auto start_nusk = std::chrono::high_resolution_clock::now();
    Container S;
    nuskaitymas(S, dydis);
    auto end_nusk = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_nusk = end_nusk - start_nusk;
    cout << std::fixed << std::setprecision(6) << "Failas su " << dydis << " studentu nuskaitytas per " << elapsed_nusk.count() << " s\n";
    auto start_grupe = std::chrono::high_resolution_clock::now();
    Container Dundukai;
    Container Galvociai;
    skaiciavimai(S);
    grupavimas_pirm(S, Dundukai, Galvociai);
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