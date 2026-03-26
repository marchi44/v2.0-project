#include "funkcijos.h"
#include "lib.h"

int main()
{
    std::vector<Studentas> v0; //pradine strukura
    std::vector<Studentas> dv; //dunduku struktura
    std::vector<Studentas> gv; //galvociu struktura
    std::deque<Studentas> d0; //pradine strukura
    std::deque<Studentas> dd; //dunduku struktura
    std::deque<Studentas> gd; //galvociu struktura
    std::list<Studentas> l0; //pradine strukura
    std::list<Studentas> dl; //dunduku struktura
    std::list<Studentas> gl; //galvociu struktura
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
    //su std::deque
    nuskaitymas(d0, dydis);
    skaiciavimai(d0);
    {
        auto d = d0;
        auto start_d1 = std::chrono::high_resolution_clock::now();
        grupavimas_pirm(d, dd, gd);
        auto end_d1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_d1 = end_d1 - start_d1;
        cout << std::fixed << std::setprecision(4) << "std::deque grupavimas pirmu budu su " << d.size() << " studentu uztruko " << elapsed_d1.count() << " s\n";
        dd.clear();
        gd.clear();
    }
    {
        auto d = d0;
        auto start_d2 = std::chrono::high_resolution_clock::now();
        grupavimas_antras(d, dd);
        auto end_d2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_d2 = end_d2 - start_d2;
        cout << std::fixed << std::setprecision(4) << "std::deque grupavimas antru budu su " << dydis << " studentu uztruko " << elapsed_d2.count() << " s\n";
        dd.clear();
        gd.clear();
    }
    {
        auto d = d0;
        auto start_d3 = std::chrono::high_resolution_clock::now();
        grupavimas_trecias(d, dd);
        auto end_d3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_d3 = end_d3 - start_d3;
        cout << std::fixed << std::setprecision(4) << "std::deque grupavimas treciu budu su " << dydis << " studentu uztruko " << elapsed_d3.count() << " s\n";
    }
    //su std::list
    nuskaitymas(l0, dydis);
    skaiciavimai(l0);
    {
        auto l = l0;
        auto start_l1 = std::chrono::high_resolution_clock::now();
        grupavimas_pirm(l, dl, gl);
        auto end_l1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_l1 = end_l1 - start_l1;
        cout << std::fixed << std::setprecision(4) << "std::list grupavimas pirmu budu su " << l.size() << " studentu uztruko " << elapsed_l1.count() << " s\n";
        dl.clear();
        gl.clear();
    }
    {
        auto l = l0;
        auto start_l2 = std::chrono::high_resolution_clock::now();
        grupavimas_antras(l, dl);
        auto end_l2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_l2 = end_l2 - start_l2;
        cout << std::fixed << std::setprecision(4) << "std::list grupavimas antru budu su " << dydis << " studentu uztruko " << elapsed_l2.count() << " s\n";
        dl.clear();
        gl.clear();
    }
    {
        auto l = l0;
        auto start_l3 = std::chrono::high_resolution_clock::now();
        grupavimas_trecias(l, dl);
        auto end_l3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_l3 = end_l3 - start_l3;
        cout << std::fixed << std::setprecision(4) << "std::list grupavimas treciu budu su " << dydis << " studentu uztruko " << elapsed_l3.count() << " s\n";
    }
    return 0;
}