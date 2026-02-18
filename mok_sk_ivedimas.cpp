#include "funkcijos.h"
#include <string>
#include <iostream>

void mok_sk_ivedimas(string input, int& mok_sk){
    while (true) {
        std::cout << "Iveskite kiek yra mokiniu (jei is anksto nezinote paspauskite ENTER) \n";
        getline(std::cin, input);
        if(input.empty()){
            break;
        }
        bool valid = ar_valid(input);
        if (valid && (stoi(input) > 0)) {
            mok_sk = stoi(input);
            break;
        }
        std::cout << "Klaida! Jusu ivestas mokiniu skaicius privalo buti sveikas skaicius didesnis uz nuli. Bandykite is naujo...\n";
        std::cin.clear();
        std::cin.ignore();
    }
}