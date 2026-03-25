#include "funkcijos.h"
#include "lib.h"

int meniu(){
    int meniu_pasirinkimas;
    std::cout << "1 - viska ivesti ranka\n2 - generuoti tik pazymius\n3 - generuoti studentu vardus, pavardes ir pazymius\n4 - generuoti duomenu faila\n5 - baigti darba.\n";
    while(true){
        std::cin >> meniu_pasirinkimas;
        if(std::cin.fail() || (meniu_pasirinkimas < 1 || meniu_pasirinkimas > 5)){
            std::cout << "Klaida! Iveskite sveika skaiciu (1-5)...\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cin.ignore(10000, '\n');
        return meniu_pasirinkimas;
    }
}