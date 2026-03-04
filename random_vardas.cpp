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