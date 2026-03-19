#include "funkcijos.h"
#include "lib.h"

void pasirinkimas2(vector<Studentas> &S, int meniu_pasirinkimas){
    int mok_sk;
    std::cout << "0 - ivedimas ranka, 1 - ivedimas is failo\n";
        int input;
        try {
            std::cin >> input;
            std::cin.ignore(10000, '\n');
            if(!std::cin || (input != 0 && input != 1)){
                throw std::runtime_error("Klaida! Turite ivesti 0 arba 1...\n");
            }
        }
        catch (const std::exception& e) {
            std::cerr << e.what();
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            return;
        }
        bool ar_is_failo = (input == 1);
        if(ar_is_failo){
            try
            {
                ivedimas_is_failo(S, meniu_pasirinkimas);
                for(int i = 0; i < S.size(); i++){
                    S[i].nd_rez.clear();
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what();
                return;
            }
        }
        else{
            int mok_sk = mok_sk_ivedimas();
            if(mok_sk > 0){
            S.reserve(S.size() + mok_sk);
            }
            else {
                S.reserve(S.size() + 10000);
            }
        }
    int i = 0;
    std::string eil, vrd, pvrd;
    while(true){
        // jei kiekis zinomas ir jau uzpildyta
        if(ar_is_failo || (mok_sk != 0 && i >= mok_sk)){
            break;
        }

        std::cout << "Iveskite " << i+1 << "-ojo mokinio varda ir pavarde. Tuscia eilute - baigti\n";
        std::getline(std::cin, eil);

        // jei kiekis nezinomas ir ivedimas baigtas su tuscia eilute
        if(mok_sk == 0 && eil.empty() && i != 0){
            break;
        }

        std::stringstream ss(eil);

        if(!(ss >> vrd >> pvrd)){
            std::cerr << "Klaida! Turite ivesti varda ir pavarde...\n";
            std::cin.clear();
            continue;
        }

        S.push_back(Studentas{vrd, pvrd});
        i++;
    }
    std::cout << "Generuojami pazymiai...\n";
    for(auto& s : S){
        int n = rand() % 100 + 1; //pazymiu skaicius nuo 1 iki 100
        s.nd_rez.reserve(s.nd_rez.size() + n);
        for(int i = 0; i < n; i++){
            int rnd_paz = rand() % 10 + 1;
            s.nd_rez.push_back(rnd_paz);
        }
        s.egz_rez = rand() % 10 + 1;
        s.vidurkis = vidurkis(S, &s - &S[0], s.nd_rez.size());
    }
    // for(size_t i = 0; i < S.size(); i++){
    //     S[i].vidurkis = vidurkis(S, i, S[i].nd_rez.size());
    // }
    //string metodas = med_ar_vid();
    for (auto& s : S) {
                std::sort(s.nd_rez.begin(), s.nd_rez.end());
                if (s.nd_rez.size() % 2 == 0) {
                    s.mediana = (s.nd_rez[s.nd_rez.size() / 2] + s.nd_rez[s.nd_rez.size() / 2 - 1]) / 2.0;
                }
                else {
                s.mediana = s.nd_rez[s.nd_rez.size() / 2];
                }
                s.galutinis_vid = 0.4 * s.vidurkis + 0.6 * static_cast<double>(s.egz_rez);
                s.galutinis_med = 0.4 * s.mediana + 0.6 * static_cast<double>(s.egz_rez);
                if(s.galutinis_vid >= 5.0){
                    s.grupe = galvociai;
                }
                else{
                    s.grupe = dundukai;
                }
        }
    rusiavimo_pasirinkimas(S);
        std::cout << "1 - isvesti i konsole, 2 - isvesti i faila\n";
        int kur_isvesti;
        try {
            std::cin >> kur_isvesti;
            std::cin.ignore(10000, '\n');
            if(!std::cin || (kur_isvesti != 1 && kur_isvesti != 2)){
                throw std::runtime_error("Klaida! Neteisingai ivedete rezultatu isvedimo buda...\n");
            }
        }
        catch (const std::exception& e) {
            std::cerr << e.what();
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            return;
        }
        if(kur_isvesti == 1){
            isvedimas(S);
        }
        else{
            isvedimas_i_faila(S);
        }
}