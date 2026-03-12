#include "funkcijos.h"
#include "lib.h"

std::string rnd_vardas(bool vyras){
    vector<string>vyr_vardai = {"Jonas","Matas","Lukas","Tomas","Paulius",
    "Nojus","Domantas","Karolis","Rokas","Ignas",
    "Dovydas","Emilis","Arnas","Austejus","Danielius",
    "Edvinas","Gytis","Jokubas","Justas","Laurynas",
    "Martynas","Mykolas","Pijus","Simonas","Tadas"};
    vector<string>mot_vardai = {
    "Austeja","Gabija","Emilija","Ugne","Ieva",
    "Gabriele","Liepa","Smilte","Egle","Agne",
    "Kamile","Patricija","Monika","Karolina","Ruta",
    "Simona","Juste","Gintare","Indre","Aiste",
    "Viktorija","Greta","Laura","Milda","Marija"
    };
    if(vyras){
        int i = rand() % vyr_vardai.size();
        return vyr_vardai[i];
    }
    else{
        int i = rand() % mot_vardai.size();
        return mot_vardai[i];
    }
}

std::string rnd_pavarde(bool vyras){
    vector<string>vyr_pavarde = {
    "Kazlauskas",
    "Petrauskas",
    "Jankauskas",
    "Stankevicius",
    "Vasiliauskas",
    "Zukauskas",
    "Paulauskas",
    "Urbonas",
    "Kavaliauskas",
    "Navickas"
    };
    vector<string>mot_pavarde = {
    "Kazlauskaite",
    "Petrauskaite",
    "Jankauskaite",
    "Stankeviciute",
    "Vasiliauskaite",
    "Zukauskaite",
    "Paulauskaite",
    "Urbonaite",
    "Kavaliauskaite",
    "Navickaite"
    };
    if(vyras){
        int i = rand() % vyr_pavarde.size();
        return vyr_pavarde[i];
    }
    else {
        int i = rand() % mot_pavarde.size();
        return mot_pavarde[i];
    }
}

void failo_generavimas() {
    cout << "Iveskite failo, i kuri norite generuoti duomenis, pavadinima (pvz., kursiokai.txt): ";
    string path;
    cin >> path;
    cin.ignore(10000, '\n');
    if(path.empty() || path.size() < 4 || path.substr(path.size() - 4) != ".txt"){
        cin.clear();
        throw std::runtime_error("Klaida! Failo pavadinimas turi baigtis .txt...\n");
    }
    std::ofstream out(path);
    //srand(time(0));
    //int mok_sk = rand();
    cout << "Iveskite mokiniu skaiciu, kuri norite generuoti: ";
    int mok_sk;
    cin >> mok_sk;
    cin.ignore(10000, '\n');
    if(cin.fail() || mok_sk <= 0){
        cin.clear();
        throw std::runtime_error("Klaida! Turite ivesti teigiama sveika skaiciu...\n");
        return;
    }
    out << std::left << std::setw(15) << "Vardas" << std::setw(25) << "Pavarde" << std::setw(5) << "ND1" << std::setw(5) << "ND2" << std::setw(5) << "ND3" << std::setw(5) << "ND4" << std::setw(5) << "ND5" << std::setw(10) << "Egzaminas\n";
    for (int i = 0; i < mok_sk; i++) {
        bool lytis = rand() % 2;
        out << std::setw(15) << rnd_vardas(lytis) << std::setw(25) << rnd_pavarde(lytis) << " ";
        int paz_sk = rand() % 5 + 1;
        for (int j = 0; j < paz_sk; j++) {
            out << std::setw(5) << rand() % 10 + 1;
        }
        if(paz_sk < 5){
            for (int j = paz_sk; j < 5; j++) {
                out << std::setw(5) << " ";
            }
        }
        out << std::setw(10) << rand() % 10 + 1 << "\n";
    }
    out.close();
}