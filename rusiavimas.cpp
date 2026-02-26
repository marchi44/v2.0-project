#include "funkcijos.h"
#include <vector>
#include <iostream>
#include <algorithm>

void rusiavimas(vector<Studentas> &S){
    std::cout << "1 - rusiuoti didejanciai, 2 - rusiuoti mazejanciai\n";
    int did_ar_maz;
    try {
        std::cin >> did_ar_maz;
        std::cin.ignore(10000, '\n');
        if(!std::cin || (did_ar_maz != 1 && did_ar_maz != 2)){
            throw std::runtime_error("Klaida! Neteisingai pasirinktas rusiavimas...\n");
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }
    int pagal_ka_rusiuoti;
    std::cout << "1 - rusiuoti pagal varda, 2 - rusiuoti pagal pavarde, 3 - rusiuoti pagal galutini (Vid.) rezultata, 4 - rusiuoti pagal galutini (Med.) rezultata\n";
    try {
        std::cin >> pagal_ka_rusiuoti;
        std::cin.ignore(10000, '\n');
        if(!std::cin || pagal_ka_rusiuoti < 1 || pagal_ka_rusiuoti > 4){
            throw std::runtime_error("Klaida! Neteisingai pasirinkta pagal ka rusiuoti...\n");
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }
    if(did_ar_maz == 1){
        switch(pagal_ka_rusiuoti){
            case 1:
                std::sort(S.begin(), S.end(), [](const Studentas& a, const Studentas& b) {
                    return a.Vardas < b.Vardas;
                });
                break;
            case 2:
                std::sort(S.begin(), S.end(), [](const Studentas& a, const Studentas& b) {
                    return a.Pavarde < b.Pavarde;
                });
                break;
            case 3:
                std::sort(S.begin(), S.end(), [](const Studentas& a, const Studentas& b) {
                    return a.galutinis_vid < b.galutinis_vid;
                });
                break;
            case 4:
                std::sort(S.begin(), S.end(), [](const Studentas& a, const Studentas& b) {
                    return a.galutinis_med < b.galutinis_med;
                });
                break;
        }
    }
    else{
        switch(pagal_ka_rusiuoti){
            case 1:
                std::sort(S.begin(), S.end(), [](const Studentas& a, const Studentas& b) {
                    return a.Vardas > b.Vardas;
                });
                break;
            case 2:
                std::sort(S.begin(), S.end(), [](const Studentas& a, const Studentas& b) {
                    return a.Pavarde > b.Pavarde;
                });
                break;
            case 3:
                std::sort(S.begin(), S.end(), [](const Studentas& a, const Studentas& b) {
                    return a.galutinis_vid > b.galutinis_vid;
                });
                break;
            case 4:
                std::sort(S.begin(), S.end(), [](const Studentas& a, const Studentas& b) {
                    return a.galutinis_med > b.galutinis_med;
                });
                break;
        }
    }
}