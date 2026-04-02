#include "funkcijos.h"
#include "lib.h"

int main()
{
    std::vector<Studentas> v0; //pradine strukura
    std::vector<Studentas> dv; //dunduku struktura
    std::vector<Studentas> gv; //galvociu struktura
    int dydis = 100000;
    //su std::vector
    nuskaitymas(v0, dydis);
    skaiciavimai(v0);
    {
        auto v = v0;
        auto start_v1 = std::chrono::high_resolution_clock::now();
        grupavimas_pirm(v, dv, gv);
        auto end_v1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_v1 = end_v1 - start_v1;
        cout << std::fixed << std::setprecision(4) << "std::vector grupavimas pirmu budu su " << v.size() << " studentu uztruko " << elapsed_v1.count() << " s\n";
        dv.clear();
        gv.clear();
    }
    {
        auto v = v0;
        auto start_v2 = std::chrono::high_resolution_clock::now();
        grupavimas_antras(v, dv);
        auto end_v2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_v2 = end_v2 - start_v2;
        cout << std::fixed << std::setprecision(4) << "std::vector grupavimas antru budu su " << dydis << " studentu uztruko " << elapsed_v2.count() << " s\n";
        dv.clear();
        gv.clear();
    }
    {
        auto v = v0;
        auto start_v3 = std::chrono::high_resolution_clock::now();
        grupavimas_trecias(v, dv);
        auto end_v3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_v3 = end_v3 - start_v3;
        cout << std::fixed << std::setprecision(4) << "std::vector grupavimas treciu budu su " << dydis << " studentu uztruko " << elapsed_v3.count() << " s\n";
    }
    return 0;
}