#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

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
};

int main() {
    double mok_sk = 0;
    int paz_sk = 0;
    cout << "Iveskite kiek yra mokiniu: \n";
    cin >> mok_sk;
    if (mok_sk != int(mok_sk)) {
        cout << "Klaida: ivestas mokiniu kiekis turi buti sveikas skaicius!\n";
        return 1;
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
        cout << "Kiek mokinys turi pazymiu is namu darbu? \n";
        cin >> paz_sk;
        S[i].nd_rez.resize(paz_sk);
        cout << "Iveskite mokinio " << S[i].Vardas << " " << S[i].Pavarde << " tarpinius namu darbu rezultatus: \n";
        for (int j = 0; j < paz_sk; j++) {
            int tmp;
            cin >> tmp;
            if (tmp < 0 || tmp > 10) {
                cout << "Klaida: pazymys turi buti desimbaleje skaleje!\n";
                return 1;
            }
            S[i].nd_rez.push_back(tmp);
        }
        cout << "Iveskite mokinio " <<  S[i].Vardas << " " << S[i].Pavarde  << " egzamino rezultata: \n";
        cin >> S[i].egz_rez;
        if (S[i].egz_rez < 0 || S[i].egz_rez > 10) {
            cout << "Klaida: pazymys turi buti desimbaleje skaleje!\n";
            return 1;
        }
    }
    for (auto& s : S) {
        int paz_suma = 0;
        for (int paz : s.nd_rez) {
            paz_suma += paz;
        }
        paz_suma += s.egz_rez;
        s.vidurkis = paz_suma / (paz_sk + 1.0);
    }
    cout << std::left << std::setw(25) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(18) << std::setprecision(2) << "Galutinis (Vid.) \n";
    for (int i = 0; i < 58; i++) {
        cout << "-";
    }
    cout << std::endl;
    for (auto& s : S) {
        cout << std::left << std::setw(25) << s.Pavarde << std::left << std::setw(15) << s.Vardas << std::left << std::setw(18) << s.vidurkis << std::endl;
    }
    return 0;
}