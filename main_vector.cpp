#include "lib.h"
#include "funkcijos.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::stringstream;
using std::getline;

int main() {
    srand(time(NULL));
    //failo_generavimas();
    vector<Studentas> S;
    string input;
    int paz_sk;
    int mok_sk;
    int meniu_pasirinkimas = meniu();
    while(meniu_pasirinkimas != 4){
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
               for(int i = 0; i < S.size(); i++){
                    S[i].vidurkis = vidurkis(S, i, S[i].nd_rez.size());
               }
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
        }
        rusiavimas(S);
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
    }
    S.clear();
    meniu_pasirinkimas = meniu();
    }
    return 0;
}