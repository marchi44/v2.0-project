#include "funkcijos.h"
#include "lib.h"

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