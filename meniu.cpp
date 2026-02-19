#include "funkcijos.h"

int meniu(){
    int meniu_pasirinkimas;
    std::cout << "1 - viska ivesti ranka, 2 - generuoti tik pazymius, 3 - generuoti studentu vardus, pavardes ir pazymius, 4 - baigti darba.\n";
    while(true){
        std::cin >> meniu_pasirinkimas;
        if(std::cin.fail() || (meniu_pasirinkimas < 1 || meniu_pasirinkimas > 4)){
            std::cout << "Klaida! Iveskite sveika skaiciu (1-4)...\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        return meniu_pasirinkimas;
    }
}