#include "funkcijos.h"
#include "lib.h"

int egz_ivedimas(){
    std::string input;
    std::cout << "Iveskite mokinio egzamino rezultata: \n";
            while (true) {
                std::cin >> input;
                std::cin.ignore(10000, '\n');
                bool valid = !input.empty();
                if(valid){
                    valid = ar_valid(input);
                }
                if (valid && (stoi(input) > 0) && (stoi(input) <= 10)) {
                    return stoi(input);
                    break;
                }
                std::cout << "Klaida! Jusu ivestas pazymys privalo buti sveikas skaicius (1-10). Bandykite is naujo...\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
}