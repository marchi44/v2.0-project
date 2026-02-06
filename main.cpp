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
    int mok_sk = 0;
    int paz_sk = 0;
    cout << "Įveskite kiek yra mokinių: \n";
    cin >> mok_sk;
    vector<Studentas> S;
    S.resize(mok_sk);
    for (int i = 0; i < mok_sk; i++) {
        cout << "Įveskite " << i+1 << "-ojo mokinio vardą ir pavardę: \n";
        stringstream ss;
        string eil;
        cin.ignore();
        std::getline(cin, eil, '\n');
        ss << eil;
        ss >> S[i].Vardas >> S[i].Pavarde;
        cout << "Kiek mokinys turi pažymių iš namų darbų? \n";
        cin >> paz_sk;
        S[i].nd_rez.resize(paz_sk);
        cout << "Įveskite mokinio " << S[i].Vardas << " " << S[i].Pavarde << " tarpinius namų darbų rezultatus: \n";
        for (int j = 0; j < paz_sk; j++) {
            int tmp;
            cin >> tmp;
            S[i].nd_rez.push_back(tmp);
        }
        cout << "Įveskite mokinio " <<  S[i].Vardas << " " << S[i].Pavarde  << " egzamino rezultatą: \n";
        cin >> S[i].egz_rez;
    }
    for (auto& s : S) {
        int paz_suma = 0;
        for (int paz : s.nd_rez) {
            paz_suma += paz;
        }
        paz_suma += s.egz_rez;
        s.vidurkis = paz_suma / (paz_sk + 1.0);
    }
    cout << std::left << std::setw(25) << "Pavardė" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(18) << std::setprecision(2) << "Galutinis (Vid.) \n";
    for (int i = 0; i < 58; i++) {
        cout << "-";
    }
    cout << std::endl;
    for (auto& s : S) {
        cout << std::left << std::setw(25) << s.Pavarde << std::left << std::setw(15) << s.Vardas << std::left << std::setw(18) << s.vidurkis << std::endl;
    }
    return 0;
}