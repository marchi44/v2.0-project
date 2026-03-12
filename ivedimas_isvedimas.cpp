#include "funkcijos.h"
#include "lib.h"

void ivedimas_is_failo(vector<Studentas> &S, int meniu_pasirinkimas){
    S.reserve(S.size() + 10000);
    std::ifstream in("kursi.txt");
    if (!in) {
        throw std::runtime_error("Klaida! Nepavyko atidaryti failo...\n");
    }
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
        if(meniu_pasirinkimas == 1){
        while(ss >> paz){
            if(paz > 0 && paz <= 10){
                tmp.nd_rez.push_back(paz);
            }
            else{
                throw std::runtime_error("Klaida! Pazymiai turi buti desimtbaleje sistemoje...\n");
            }
        }
        }
        if(!tmp.nd_rez.empty()){
            tmp.egz_rez = tmp.nd_rez.back();
            tmp.nd_rez.pop_back();
        }
        else if(meniu_pasirinkimas == 1){
            throw std::runtime_error("Klaida! Mokinio " + tmp.Vardas + " " + tmp.Pavarde + " namu darbu pazymiai nerasti...\n");
        }
        // int paz_suma = 0;
        // for (const int paz : tmp.nd_rez) {
        //     paz_suma += paz;
        // }
        // tmp.vidurkis = static_cast<double>(paz_suma) / static_cast<double>(tmp.nd_rez.size());
        S.push_back(tmp);
    }
}

void isvedimas_i_faila(std::vector<Studentas> S){
    // if (metodas == "vid") {
    //     std::cout << std::left << std::setw(25) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(18) << "Galutinis (Vid.)\n";
    // }
    // else {
    //     std::cout << std::left << std::setw(25) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(18) << "Galutinis (Med.)\n";
    // }
    std::ofstream out("rezultatai.txt");
    if(!out){
        std::cerr << "Klaida! Nepavyko sukurti failo...\n";
        return;
    }
    out << std::left << std::setw(15) << "Vardas" << std::left << std::setw(25) << "Pavarde" << std::left << std::setw(18) << "Galutinis (Vid.)" << std::left << std::setw(18) << "Galutinis (Med.)\n";
    for (int i = 0; i < 76; i++) {
        out << "-";
    }
    out << std::endl;
    for (auto& s : S) {
        out << std::left << std::setw(15) << s.Vardas << std::left << std::setw(25) << s.Pavarde << std::left << std::setw(18) << std::fixed << std::setprecision(2) << s.galutinis_vid << std::left << std::setw(18) << std::fixed << std::setprecision(2) << s.galutinis_med << std::endl;
    }
}

void isvedimas(std::vector<Studentas> S){
    // if (metodas == "vid") {
    //     std::cout << std::left << std::setw(25) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(18) << "Galutinis (Vid.)\n";
    // }
    // else {
    //     std::cout << std::left << std::setw(25) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(18) << "Galutinis (Med.)\n";
    // }
    std::cout << std::left << std::setw(15) << "Vardas" << std::left << std::setw(25) << "Pavarde" << std::left << std::setw(18) << "Galutinis (Vid.)" << std::left << std::setw(18) << "Galutinis (Med.)\n";
    for (int i = 0; i < 76; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
    for (auto& s : S) {
        std::cout << std::left << std::setw(15) << s.Vardas << std::left << std::setw(25) << s.Pavarde << std::left << std::setw(18) << std::fixed << std::setprecision(2) << s.galutinis_vid << std::left << std::setw(18) << std::fixed << std::setprecision(2) << s.galutinis_med << std::endl;
    }
}