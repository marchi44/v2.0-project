#include "funkcijos.h"
#include <string>
#include <iostream>

int mok_sk_ivedimas(){
    std::string input;
    while (true) {
        std::cout << "Iveskite kiek yra mokiniu (jei is anksto nezinote paspauskite ENTER) \n";
        std::getline(std::cin, input, '\n');
        if(input.empty()){
            return 0;
        }
        bool valid = ar_valid(input);
        if (valid && stoi(input) > 0) {
            return stoi(input);
        }
        std::cout << "Klaida! Jusu ivestas mokiniu skaicius privalo buti sveikas skaicius didesnis uz nuli. Bandykite is naujo...\n";
        std::cin.clear();
    }
}