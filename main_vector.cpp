#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::stringstream;

struct Studentas {
    string Vardas;
    string Pavarde;
    vector<int> nd_rez;
    int egz_rez;
    double vidurkis;
    double mediana;
    double galutinis;
};

int main() {
    string input;
    int mok_sk;
    int paz_sk;
    while (true) {
        cout << "Iveskite kiek yra mokiniu: \n";
        cin >> input;
        bool valid = !input.empty();
        for (const char c : input) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }
        if (valid && (stoi(input) > 0)) {
            mok_sk = stoi(input);
            break;
        }
        cout << "Klaida! Jusu ivestas mokiniu skaicius privalo buti sveikas skaicius didesnis uz nuli. Bandykite is naujo...\n";
        cin.clear();
        cin.ignore();
    }
    vector<Studentas> S;
    S.resize(mok_sk);
    for (int i = 0; i < mok_sk; i++) {
        cout << "Iveskite " << i+1 << "-ojo mokinio varda ir pavarde: \n";
        stringstream ss;
        string eil;
        cin.ignore();
        std::getline(cin, eil, '\n');
        ss << eil;
        ss >> S[i].Vardas >> S[i].Pavarde;
        while (true) {
            cout << "Kiek mokinys turi pazymiu is namu darbu? \n";
            cin >> input;
            bool valid = !input.empty();
            for (const char c : input) {
                if (!isdigit(c)) {
                    valid = false;
                    break;
                }
            }
            if (valid && (stoi(input) > 0)) {
                paz_sk = stoi(input);
                break;
            }
            cout << "Klaida! Jusu ivestas pazymiu skaicius privalo buti sveikas skaicius. Bandykite is naujo...\n";
            cin.clear();
            cin.ignore(10000,'\n');
        }
        S[i].nd_rez.resize(paz_sk);
            cout << "Iveskite mokinio " << S[i].Vardas << " " << S[i].Pavarde << " tarpinius namu darbu rezultatus: \n";
            for (int j = 0; j < paz_sk; j++) {
                while (true) {
                    cin >> input;
                    bool valid = !input.empty();
                    for (const char c : input) {
                        if (!isdigit(c)) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid && (stoi(input) > 0) && (stoi(input) <= 10)) {
                        S[i].nd_rez[j] = stoi(input);
                        break;
                    }
                        cout << "Klaida! Jusu ivestas pazymys privalo buti sveikas skaicius (1-10). Bandykite is naujo...\n";
                        cin.clear();
                        cin.ignore();
                }
            }
        int paz_suma = 0;
        for (const int paz : S[i].nd_rez) {
            paz_suma += paz;
        }
        S[i].vidurkis = static_cast<double>(paz_suma) / static_cast<double>(paz_sk);
        cout << "Iveskite mokinio " <<  S[i].Vardas << " " << S[i].Pavarde  << " egzamino rezultata: \n";
        while (true) {
            cin >> input;
            bool valid = !input.empty();
            for (const char c : input) {
                if (!isdigit(c)) {
                    valid = false;
                    break;
                }
            }
            if (valid && (stoi(input) > 0) && (stoi(input) <= 10)) {
                S[i].egz_rez = stoi(input);
                break;
            }
            cout << "Klaida! Jusu ivestas pazymys privalo buti sveikas skaicius (1-10). Bandykite is naujo...\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    string vid_ar_med;
    while (vid_ar_med != "vid" && vid_ar_med != "med") {
        cout << "Koki metoda norite naudoti galutinio pazymio apskaiciavimui? vid (vidurkio) ar med (medianos)?\n";
        cin >> vid_ar_med;
        if (vid_ar_med != "vid" && vid_ar_med != "med") {
            cout << "Privalote ivesti vid - jei norite naudoti skaiciavima su vidurkiu, arba med - jei norite naudoti skaiciavima su mediana!\n";
        }
    }
    for (auto& s : S) {
        if (vid_ar_med == "vid") {
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
    if (vid_ar_med == "vid") {
        cout << std::left << std::setw(25) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(18) << "Galutinis (Vid.)\n";
    }
    else {
        cout << std::left << std::setw(25) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(18) << "Galutinis (Med.)\n";
    }
    for (int i = 0; i < 58; i++) {
        cout << "-";
    }
    cout << std::endl;
    for (auto& s : S) {
        cout << std::left << std::setw(25) << s.Pavarde << std::left << std::setw(15) << s.Vardas << std::left << std::setw(18) << std::fixed << std::setprecision(2) << s.galutinis << std::endl;
    }
    return 0;
}