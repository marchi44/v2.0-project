#include "funkcijos.h"
#include "lib.h"

int mok_sk_ivedimas(){
    std::string input;
    while (true) {
        std::cout << "Iveskite kiek yra mokiniu (jei is anksto nezinote paspauskite ENTER) \n";
        std::getline(std::cin, input, '\n');
        if(input.empty()){
            return 0;
        }
        bool valid = ar_valid(input);
        if (valid && stoi(input) > 0) {
            return stoi(input);
        }
        std::cout << "Klaida! Jusu ivestas mokiniu skaicius privalo buti sveikas skaicius didesnis uz nuli. Bandykite is naujo...\n";
        std::cin.clear();
    }
}

int paz_sk_ivedimas(){
    while (true) {
            std::string input;
            std::cout << "Kiek mokinys turi pazymiu is namu darbu? Jei nezinote pazymiu kiekio paspauskite ENTER\n";
            std::getline(std:: cin, input);
            if(input.empty()){
                return 0;
            }
            bool valid = ar_valid(input);
            if (valid && (stoi(input) > 0)) {
                return stoi(input);
            }
            std::cout << "Klaida! Jusu ivestas pazymiu skaicius privalo buti sveikas skaicius (>0). Bandykite is naujo...\n";
        }
}

void pazymiu_ivedimas(vector<Studentas> &S, int i){
    std::string input;
    int paz_sk = paz_sk_ivedimas();
    if(paz_sk > 0){
        S[i].nd_rez.reserve(S[i].nd_rez.size() + paz_sk);
    }
        bool nezinomas_kiek = false;
        bool baigta = false;
        if(paz_sk == 0)
        {
            S[i].nd_rez.reserve(S[i].nd_rez.size() + 1000);
            nezinomas_kiek = true;
            paz_sk = 1;
        }
    std::cout << "Iveskite mokinio namu darbu rezultatus (0 - baigti, jei kiekis nezinomas): \n";
            for (int j = 0; j < paz_sk; j++) {
                while (true) {
                    std::cin >> input;
                    std::cin.ignore(10000, '\n');
                    if(!ar_valid(input))
                    {
                        std::cout << "Klaida! Jusu ivestas pazymys privalo buti sveikas skaicius (1-10). Bandykite is naujo...\n";
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        continue;
                    }
                    if(nezinomas_kiek && stoi(input) == 0)
                    {
                        baigta = true;
                        break;
                    }
                    if ((stoi(input) > 0) && (stoi(input) <= 10)) {
                        S[i].nd_rez.push_back(stoi(input));
                        break;
                    }
                        std::cout << "Klaida! Jusu ivestas pazymys privalo buti sveikas skaicius (1-10). Bandykite is naujo...\n";
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                }
                if(baigta){
                    break;
                }
                else if(nezinomas_kiek)
                {
                    paz_sk++;
                }
            }
}

int egz_ivedimas(){
    std::string input;
    std::cout << "Iveskite mokinio egzamino rezultata: \n";
            while (true) {
                std::cin >> input;
                std::cin.ignore(10000, '\n');
                bool valid = !input.empty();
                if(valid){
                    valid = ar_valid(input);
                }
                if (valid && (stoi(input) > 0) && (stoi(input) <= 10)) {
                    return stoi(input);
                    break;
                }
                std::cout << "Klaida! Jusu ivestas pazymys privalo buti sveikas skaicius (1-10). Bandykite is naujo...\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
}

double vidurkis(vector<Studentas> &S, int i, int paz_sk){
    int paz_suma = 0;
        for (const int paz : S[i].nd_rez) {
            paz_suma += paz;
        }
    return static_cast<double>(paz_suma) / static_cast<double>(paz_sk);
}

string med_ar_vid(){
    string vid_ar_med;
    std::cout << "Koki metoda norite naudoti galutinio pazymio apskaiciavimui? vid (vidurkio) ar med (medianos)?\n";
    while (true) {
        std::cin >> vid_ar_med;
        std::cin.ignore(10000, '\n');
        if(vid_ar_med == "vid" || vid_ar_med == "med"){
            return vid_ar_med;
        }
        std::cout << "Klaida! Privalote ivesti vid arba med... \n";
    }
}

void mokinio_info_ivedimas(std::vector<Studentas> &S, int mok_sk){

    int i = 0;
    std::string eil, vrd, pvrd;
    if(mok_sk > 0){
    S.reserve(S.size() + mok_sk);
    }
    else {
        S.reserve(S.size() + 10000);
    }

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
        pazymiu_ivedimas(S, i);
        //vidurkio apskaiciavimas
        S[i].vidurkis = vidurkis(S, i, paz_sk);
        //egzamino rezultato ivedimas
        S[i].egz_rez = egz_ivedimas();
        i++;
    }
}