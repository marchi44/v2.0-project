#ifndef FUNKCIJOS_TEMP_H
#define FUNKCIJOS_TEMP_H

#include "lib.h"
#include "struktura.h"

template<typename Container>
void mokinio_info_ivedimas(Container &S, int mok_sk){

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

template<typename Container>
void ivedimas_is_failo(Container &S, int meniu_pasirinkimas){
    string path;
    cout << "Iveskite failo, is kurio norite nuskaityti, pavadinima (pvz., kursiokai.txt): ";
    cin >> path;
    if(path.empty() || path.size() < 4 || path.substr(path.size() - 4) != ".txt"){
        cin.clear();
        throw std::runtime_error("Klaida! Failo pavadinimas turi baigtis .txt...\n");
    }
    std::ifstream in(path);
    if (!in) {
        throw std::runtime_error("Klaida! Nepavyko atidaryti failo...\n");
    }
    string eil;
    getline(in, eil); // praleiziama header
    while(getline(in, eil)){
        int paz_suma = 0;
        if(eil.empty()){
            continue;
        }
        std::istringstream ss(eil);
        int paz;
        Studentas tmp;
        ss >> tmp.Vardas >> tmp.Pavarde;
        if(meniu_pasirinkimas == 1){
        while(ss >> paz){
            if(paz > 0 && paz <= 10){
                tmp.nd_rez.push_back(paz);
                paz_suma += paz;
            }
            else{
                throw std::runtime_error("Klaida! Pazymiai turi buti desimtbaleje sistemoje...\n");
            }
        }
        }
        if(!tmp.nd_rez.empty()){
            tmp.egz_rez = tmp.nd_rez.back();
            tmp.nd_rez.pop_back();
        }
        else if(meniu_pasirinkimas == 1){
            throw std::runtime_error("Klaida! Mokinio " + tmp.Vardas + " " + tmp.Pavarde + " namu darbu pazymiai nerasti...\n");
        }
        tmp.vidurkis = static_cast<double>(paz_suma) / static_cast<double>(tmp.nd_rez.size());
        S.push_back(tmp);
    }
}

template<typename Container>
void rasyti_i_faila(const Container& grupe, const std::string& failo_pavadinimas) {
    std::ofstream out(failo_pavadinimas);
    if (!out) {
        std::cerr << "Klaida! Nepavyko sukurti failo " << failo_pavadinimas << "...\n";
        return;
    }

    out << std::fixed << std::setprecision(2);
    out << std::left << std::setw(15) << "Vardas" << std::setw(25) << "Pavarde" << std::setw(18) << "Galutinis (Vid.)" << std::setw(18) << "Galutinis (Med.)" << '\n';
    out << std::string(76, '-') << '\n';

    for (const auto& s : grupe) {
        out << std::left << std::setw(15) << s.Vardas
            << std::setw(25) << s.Pavarde
            << std::setw(18) << s.galutinis_vid
            << std::setw(18) << s.galutinis_med
            << '\n';
    }
}

template<typename Container>
void isvedimas_i_faila(const Container &Dundukai, const Container &Galvociai){
    rasyti_i_faila(Dundukai, "dundukai.txt");
    rasyti_i_faila(Galvociai, "galvociai.txt");
}

template<typename Container>
void isvedimas(Container S){
    std::cout << std::left << std::setw(15) << "Vardas" << std::left << std::setw(25) << "Pavarde" << std::left << std::setw(18) << "Galutinis (Vid.)" << std::left << std::setw(18) << "Galutinis (Med.)\n";
    for (int i = 0; i < 76; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
    for (auto& s : S) {
        std::cout << std::left << std::setw(15) << s.Vardas << std::left << std::setw(25) << s.Pavarde << std::left << std::setw(18) << std::fixed << std::setprecision(2) << s.galutinis_vid << std::left << std::setw(18) << std::fixed << std::setprecision(2) << s.galutinis_med << std::endl;
    }
}
template<typename Container>
void pasirinkimas2(Container &S, int meniu_pasirinkimas){
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
                for(auto& s : S){
                    s.nd_rez.clear();
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
        for(int i = 0; i < n; i++){
            int rnd_paz = rand() % 10 + 1;
            s.nd_rez.push_back(rnd_paz);
        }
        s.egz_rez = rand() % 10 + 1;
        s.vidurkis = vidurkis(s, s.nd_rez.size());
    }
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
    if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
        rusiavimo_pasirinkimas_list(S);
    }    
    else {
        rusiavimo_pasirinkimas(S);
    }
    Container Dundukai;
    Container Galvociai;
    for(auto& s : S){
            if(s.galutinis_vid >= 5.0){
                Galvociai.push_back(s);
            }
            else {
                Dundukai.push_back(s);
            }
    }
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
            isvedimas_i_faila(Dundukai, Galvociai);
        }
}

template<typename Container>
void pasirinkimas3(Container &S, int meniu_pasirinkimas){
    std::cout << "Generuojami studentu vardai ir pavardes...\n";
    int mok_sk = rand() % 100 + 1;
    for(int i = 0; i < mok_sk; i++){
        bool vyras = rand() % 2;
        string vardas = rnd_vardas(vyras);
        string pavarde = rnd_pavarde(vyras);
        S.push_back(Studentas{vardas, pavarde});
        int n = rand() % 100 + 1; //pazymiu skaicius nuo 1 iki 100
        for(int j = 0; j < n; j++){
            int rnd_paz = rand() % 10 + 1;
            S.back().nd_rez.push_back(rnd_paz);
        }
        S.back().egz_rez = rand() % 10 + 1;
        int paz_sk = S.back().nd_rez.size();
        S.back().vidurkis = vidurkis(S.back(), paz_sk);
        sort(S.back().nd_rez.begin(), S.back().nd_rez.end());
                if (S.back().nd_rez.size() % 2 == 0) {
                    S.back().mediana = (S.back().nd_rez[S.back().nd_rez.size() / 2] + S.back().nd_rez[S.back().nd_rez.size() / 2 - 1]) / 2.0;
                }
                else {
                S.back().mediana = S.back().nd_rez[S.back().nd_rez.size() / 2];
                }
                S.back().galutinis_vid = 0.4 * S.back().vidurkis + 0.6 * static_cast<double>(S.back().egz_rez);
                S.back().galutinis_med = 0.4 * S.back().mediana + 0.6 * static_cast<double>(S.back().egz_rez);
        }
         if constexpr (std::is_same_v<Container, std::list<Studentas>>) {
        rusiavimo_pasirinkimas_list(S);
        }    
        else {
            rusiavimo_pasirinkimas(S);
        }
        Container Dundukai;
        Container Galvociai;
        for(auto& s : S){
            if(s.galutinis_vid >= 5.0){
                Galvociai.push_back(s);
            }
            else {
                Dundukai.push_back(s);
            }
        }
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
            isvedimas_i_faila(Dundukai, Galvociai);
        }
}
#endif