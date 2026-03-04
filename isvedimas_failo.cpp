#include "funkcijos.h"
#include "lib.h"

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