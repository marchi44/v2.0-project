#include "funkcijos.h"
#include "lib.h"

void pazymiu_ivedimas(vector<Studentas> &S, int i){
    std::string input;
    int paz_sk = paz_sk_ivedimas();
    if(paz_sk > 0){
        S[i].nd_rez.reserve(S[i].nd_rez.size() + paz_sk);
    }
        bool nezinomas_kiek = false;
        bool baigta = false;
        if(paz_sk == 0)
        {
            S[i].nd_rez.reserve(S[i].nd_rez.size() + 1000);
            nezinomas_kiek = true;
            paz_sk = 1;
        }
    std::cout << "Iveskite mokinio namu darbu rezultatus (0 - baigti, jei kiekis nezinomas): \n";
            for (int j = 0; j < paz_sk; j++) {
                while (true) {
                    std::cin >> input;
                    std::cin.ignore(10000, '\n');
                    if(!ar_valid(input))
                    {
                        std::cout << "Klaida! Jusu ivestas pazymys privalo buti sveikas skaicius (1-10). Bandykite is naujo...\n";
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        continue;
                    }
                    if(nezinomas_kiek && stoi(input) == 0)
                    {
                        baigta = true;
                        break;
                    }
                    if ((stoi(input) > 0) && (stoi(input) <= 10)) {
                        S[i].nd_rez.push_back(stoi(input));
                        break;
                    }
                        std::cout << "Klaida! Jusu ivestas pazymys privalo buti sveikas skaicius (1-10). Bandykite is naujo...\n";
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                }
                if(baigta){
                    break;
                }
                else if(nezinomas_kiek)
                {
                    paz_sk++;
                }
            }
}