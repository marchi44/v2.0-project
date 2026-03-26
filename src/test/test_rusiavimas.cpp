#include "funkcijos.h"
#include "lib.h"

int main()
{
    std::vector<Studentas> v; //pradine strukura
    std::vector<Studentas> dv; //dunduku struktura
    std::vector<Studentas> gv; //galvociu struktura
    std::deque<Studentas> d; //pradine strukura
    std::deque<Studentas> dd; //dunduku struktura
    std::deque<Studentas> gd; //galvociu struktura
    std::list<Studentas> l; //pradine strukura
    std::list<Studentas> dl; //dunduku struktura
    std::list<Studentas> gl; //galvociu struktura
    int dydis = 100000;
    nuskaitymas(v, dydis);
    skaiciavimai(v);
    auto start_v1 = std::chrono::high_resolution_clock::now();
    grupavimas_pirm(v, dv, gv);
    auto end_v1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_v1 = end_v1 - start_v1;
    cout << std::fixed << std::setprecision(4) << "std::vector grupavimas pirmu budu su " << v.size() << " studentu uztruko " << elapsed_v1.count() << " s\n";
    auto start_v2 = std::chrono::high_resolution_clock::now();
    grupavimas_antras(v, dv);
    auto end_v2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_v2 = end_v2 - start_v2;
    cout << std::fixed << std::setprecision(4) << "std::vector grupavimas antru budu su " << dydis << " studentu uztruko " << elapsed_v2.count() << " s\n";
    nuskaitymas(d, dydis);
    skaiciavimai(d);
    auto start_d1 = std::chrono::high_resolution_clock::now();
    grupavimas_pirm(d, dd, gd);
    auto end_d1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_d1 = end_d1 - start_d1;
    cout << std::fixed << std::setprecision(4) << "std::deque grupavimas pirmu budu su " << d.size() << " studentu uztruko " << elapsed_d1.count() << " s\n";
    auto start_d2 = std::chrono::high_resolution_clock::now();
    grupavimas_antras(d, dd);
    auto end_d2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_d2 = end_d2 - start_d2;
    cout << std::fixed << std::setprecision(4) << "std::deque grupavimas antru budu su " << dydis << " studentu uztruko " << elapsed_d2.count() << " s\n";
    nuskaitymas(l, dydis);
    skaiciavimai(l);
    auto start_l1 = std::chrono::high_resolution_clock::now();
    grupavimas_pirm(l, dl, gl);
    auto end_l1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_l1 = end_l1 - start_l1;
    cout << std::fixed << std::setprecision(4) << "std::list grupavimas pirmu budu su " << l.size() << " studentu uztruko " << elapsed_l1.count() << " s\n";
    auto start_l2 = std::chrono::high_resolution_clock::now();
    grupavimas_antras(l, dl);
    auto end_l2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_l2 = end_l2 - start_l2;
    cout << std::fixed << std::setprecision(4) << "std::list grupavimas antru budu su " << dydis << " studentu uztruko " << elapsed_l2.count() << " s\n";
    return 0;
}