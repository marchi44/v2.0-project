#include "funkcijos.h"
#include <string>
#include <iostream>

int paz_sk_ivedimas(){
    while (true) {
            std::string input;
            std::cout << "Kiek mokinys turi pazymiu is namu darbu? Jei nezinote pazymiu kiekio paspauskite ENTER\n";
            std::getline(std:: cin, input);
            if(input.empty()){
                return 0;
            }
            bool valid = ar_valid(input);
            if (valid && (stoi(input) > 0)) {
                return stoi(input);
            }
            std::cout << "Klaida! Jusu ivestas pazymiu skaicius privalo buti sveikas skaicius (>0). Bandykite is naujo...\n";
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
}