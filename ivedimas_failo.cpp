#include "funkcijos.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::string;
using std::getline;

void ivedimas_is_failo(vector<Studentas> &S, int meniu_pasirinkimas){
    S.reserve(S.size() + 10000);
    std::ifstream in("kursiokai.txt");
    if (!in) {
        std::cerr << "Klaida! Nepavyko atidaryti failo.\n";
        return;
    }
    string eil;
    getline(in, eil); // praleiziama header
    int i = 0;
    while(getline(in, eil)){
        if(eil.empty()){
            continue;
        }
        std::istringstream ss(eil);
        int paz;
        Studentas tmp;
        ss >> tmp.Vardas >> tmp.Pavarde;
        if(meniu_pasirinkimas == 1){
        while(ss >> paz){
            if(paz > 0 && paz <= 10){
                tmp.nd_rez.push_back(paz);
            }
            else std::cerr << "Klaida! Pazymys turi buti desimtbaleje sistemoje...\n";
        }
        }
        if(!tmp.nd_rez.empty()){
            tmp.egz_rez = tmp.nd_rez.back();
            tmp.nd_rez.pop_back();
        }
        else{
            std::cerr << "Klaida! Mokinio " << tmp.Vardas << " " << tmp.Pavarde << " namu darbu pazymiai nerasti...\n";
            continue;
        }
        int paz_suma = 0;
        for (const int paz : tmp.nd_rez) {
            paz_suma += paz;
        }
        tmp.vidurkis = static_cast<double>(paz_suma) / static_cast<double>(tmp.nd_rez.size());
        S.push_back(tmp);
        i++;
    }
}