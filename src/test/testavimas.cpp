#include "lib.h"
#include "funkcijos.h"
#include "struktura.h"
#include <chrono>

void test_failu_generavimas(){
    int dydziai [] = {1000, 10000, 100000, 1000000, 10000000};
    for(const int& dydis : dydziai){
        int mok_sk = dydis;
        string path = "test_" + std::to_string(dydis) + ".txt";
        cout << "Generuojamas failas " << path << " su " << mok_sk << " mokiniu...\n";
        auto start = std::chrono::high_resolution_clock::now();
        std::ofstream out(path);
        out << std::left << std::setw(15) << "Vardas" << std::setw(25) << "Pavarde" << std::setw(5) << "ND1" << std::setw(5) << "ND2" << std::setw(5) << "ND3" << std::setw(5) << "ND4" << std::setw(5) << "ND5" << std::setw(10) << "Egzaminas\n";
        for (int i = 0; i < mok_sk; i++) {
            bool lytis = rand() % 2;
            out << std::setw(15) << rnd_vardas(lytis) << std::setw(25) << rnd_pavarde(lytis) << " ";
            int paz_sk = rand() % 5 + 1;
            for (int j = 0; j < paz_sk; j++) {
                out << std::setw(5) << rand() % 10 + 1;
            }
            for (int j = paz_sk; j < 5; j++) {
                out << std::setw(5) << " ";
            }
            out << std::setw(10) << rand() % 10 + 1 << "\n";
        }
        out.close();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        cout << "Failas " << path << " sukurtas per " << elapsed.count() << " s\n";
    }
}
int main(){
    srand(time(NULL));
    //test_failu_generavimas();
    cout << "Vector:\n";
    antras_tyrimas<std::vector<Studentas>>();
    cout << "List:\n";
    antras_tyrimas<std::list<Studentas>>();
    cout << "Deque:\n";
    antras_tyrimas<std::deque<Studentas>>();
    return 0;
}