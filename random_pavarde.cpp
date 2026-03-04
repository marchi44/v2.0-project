#include "funkcijos.h"
#include "lib.h"

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