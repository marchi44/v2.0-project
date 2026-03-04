#include "funkcijos.h"
#include "lib.h"

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