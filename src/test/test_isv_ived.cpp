#include "funkcijos.h"

int main() {
    // Išvedimo operatoriaus testas
    std::vector<Studentas> S;
    nuskaitymas(S, 10);
    skaiciavimai(S);
    rusiavimas(S, 1, 1);

    cout << "operator<< testas (i konsole) \n";
    cout << std::left << std::setw(15) << "Vardas" 
                      << std::setw(25) << "Pavarde"
                      << std::setw(18) << "Galutinis (Vid.)"
                      << std::setw(18) << "Galutinis (Med.)" << '\n';
    cout << std::string(76, '-') << '\n';
    for (const auto& s : S) {
        cout << s;
    }

    // Išvedimo į failą testas
    cout << "\noperator<< testas (i faila test_output.txt)\n";
    std::ofstream out("test_output.txt");
    out << std::left << std::setw(15) << "Vardas"
                     << std::setw(25) << "Pavarde"
                     << std::setw(18) << "Galutinis (Vid.)"
                     << std::setw(18) << "Galutinis (Med.)" << '\n';
    out << std::string(76, '-') << '\n';
    for (const auto& s : S) {
        out << s;
    }
    out.close();
    cout << "Isvesta i test_output.txt\n";

    // Įvedimo operatoriaus testas
    cout << "\noperator>> testas (is failo) \n";
    std::vector<Studentas> S2;
    std::ifstream in("test_10.txt");
    if (!in) {
        std::cerr << "Klaida! Nepavyko atidaryti test_10.txt\n";
        return 1;
    }
    std::string header;
    std::string eilute;
    std::getline(in, header);
    while(std::getline(in, eilute)) {
        if(eilute.empty()) continue;
        std::istringstream ss(eilute);
        Studentas tmp;
        ss >> tmp;
        S2.push_back(tmp);
    }
    in.close();

    skaiciavimai(S2);
    rusiavimas(S2, 1, 1);

    cout << "Nuskaityti " << S2.size() << " studentai per operator>>\n";
    cout << std::string(76, '-') << '\n';
    for (const auto& s : S2) {
        cout << s;
    }
    

    // Palyginimas
    cout << "\nPalyginimas: nuskaitymas() vs operator>> \n";
    bool sutampa = (S.size() == S2.size());
    if (sutampa) {
        for (int i = 0; i < S.size(); i++) {
            if (S[i].getVardas() != S2[i].getVardas() ||
                S[i].getPavarde() != S2[i].getPavarde() || S[i].getEgzRez() != S2[i].getEgzRez()) {
                sutampa = false;
                break;
            }
            for(int j = 0; j < S[i].getNdRez().size(); j++){
                if(S[i].getNdRez()[j] != S2[i].getNdRez()[j]){
                    sutampa = false;
                    break;
                }
            }
        }
    }
    cout << (sutampa ? "OK: abu metodai nuskaitė tuos pačius studentus\n"
                     : "KLAIDA: studentai nesutampa!\n");

    return 0;
}