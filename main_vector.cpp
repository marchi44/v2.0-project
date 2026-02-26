#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "funkcijos.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::stringstream;
using std::getline;

int main() {
    vector<Studentas> S;
    string input;
    int paz_sk;
    int mok_sk;
    int meniu_pasirinkimas = meniu();
    while(meniu_pasirinkimas != 4){
    switch(meniu_pasirinkimas){
        case 1:{
        cout << "0 - ivedimas ranka, 1 - ivedimas is failo\n";
        bool ar_is_failo;
        cin >> ar_is_failo;
        cin.ignore();
        if(ar_is_failo){
            ivedimas_is_failo(S, meniu_pasirinkimas);
        }
        else{
            mok_sk = mok_sk_ivedimas();
            mokinio_info_ivedimas(S, mok_sk);
        }
        string metodas = med_ar_vid();
        for (auto& s : S) {
            if (metodas == "vid") {
                s.galutinis = 0.4 * s.vidurkis + 0.6 * static_cast<double>(s.egz_rez);
            }
            else
            {
                std::sort(s.nd_rez.begin(), s.nd_rez.end());
                if (s.nd_rez.size() % 2 == 0) {
                    s.mediana = (s.nd_rez[s.nd_rez.size() / 2] + s.nd_rez[s.nd_rez.size() / 2 - 1]) / 2.0;
                }
                else {
                s.mediana = s.nd_rez[s.nd_rez.size() / 2];
                }
                s.galutinis = 0.4 * s.mediana + 0.6 * static_cast<double>(s.egz_rez);
            }
        }
        isvedimas(S, metodas);
        }
        break;
        case 2:
        pasirinkimas2(S);
        break;
        case 3:{
        pasirinkimas3(S);
        break;
        }
    }
    S.clear();
    meniu_pasirinkimas = meniu();
}
    return 0;
}