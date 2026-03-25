#include "lib.h"
#include "funkcijos.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::stringstream;
using std::getline;

void mokinio_info_ivedimas(std::vector<Studentas> &S, int mok_sk){

    int i = 0;
    std::string eil, vrd, pvrd;
    while(true){

        // jei kiekis zinomas ir jau uzpildyta
        if(mok_sk != 0 && i >= mok_sk){
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
            std::cout << "Klaida! Turite ivesti varda ir pavarde...\n";
            std::cin.clear();
            continue;
        }

        S.push_back(Studentas{vrd, pvrd});
        //mokinio nd pazymiu ivedimas
        int paz_sk;
        pazymiu_ivedimas(S.back());
        //vidurkio apskaiciavimas
        S.back().vidurkis = vidurkis(S.back(), paz_sk);
        //egzamino rezultato ivedimas
        S.back().egz_rez = egz_ivedimas();
        i++;
    }
}

int main() {
    srand(time(NULL));
    //test_failu_generavimas();
    //antras_tyrimas();
    vector<Studentas> S;
    string input;
    int paz_sk;
    int mok_sk;
    int meniu_pasirinkimas = meniu();
    while(meniu_pasirinkimas != 5){
    switch(meniu_pasirinkimas){
        case 1:{
        cout << "0 - ivedimas ranka, 1 - ivedimas is failo\n";
        int input;
        try {
            cin >> input;
            cin.ignore(10000, '\n');
            if(!cin || (input != 0 && input != 1)){
                throw std::runtime_error("Klaida! Turite ivesti 0 arba 1...\n");
            }
        }
        catch (const std::exception& e) {
            std::cerr << e.what();
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
        bool ar_is_failo = (input == 1);
        if(ar_is_failo){
            try
            {
               ivedimas_is_failo(S, meniu_pasirinkimas);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what();
                break;
            }
        }
        else{
            mok_sk = mok_sk_ivedimas();
            mokinio_info_ivedimas(S, mok_sk);
        }
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
        cout << "1 - isvesti i konsole, 2 - isvesti i faila\n";
        int kur_isvesti;
        try {
            cin >> kur_isvesti;
            cin.ignore(10000, '\n');
            if(!cin || (kur_isvesti != 1 && kur_isvesti != 2)){
                throw std::runtime_error("Klaida! Neteisingai ivedete rezultatu isvedimo buda...\n");
            }
        }
        catch (const std::exception& e) {
            std::cerr << e.what();
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
        if(kur_isvesti == 1){
        isvedimas(S);
        }
        else{
            isvedimas_i_faila(S);
        }
        break;
    }
        case 2:{
        pasirinkimas2(S, meniu_pasirinkimas);
        break;
        }
        case 3:{
        pasirinkimas3(S, meniu_pasirinkimas);
        break;
        }
        case 4:{
        try{
            failo_generavimas();
        }
        catch(const std::exception& e){
            std::cerr << e.what();
        }
        break;
        }
    }
    S.clear();
    meniu_pasirinkimas = meniu();
    }
    return 0;
}