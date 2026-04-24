#include "funkcijos.h"

int main() {
    vector<Studentas> S;
    nuskaitymas(S, 10);
    skaiciavimai(S);
{
    vector<Studentas> cp(S);
    cout << "Kopijavimas\n";
    cout << "Studentas S:" << std::setw(40) << std::right << "Studentas cp:\n";
    for(int i = 0; i < 10; i++){
        cout <<  S[i].getVardas() << " " << S[i].getPavarde() << " " << S[i].getGalutinisVid();
        cout << std::setw(20) << std::right << cp[i].getVardas() << " " << cp[i].getPavarde() << " " << cp[i].getGalutinisVid()<< std::endl;
    }
}
    cout << std::endl << std::endl << "Perkelimas\n";
{
    vector<Studentas> mv = std::move(S);
    if(!S.empty()){
    for(int i = 0; i < 10; i++){
        cout << "Studentas S:" << std::setw(40) << std::right << "Studentas cp:\n";
        cout <<  S[i].getVardas() << " " << S[i].getPavarde() << " " << S[i].getGalutinisVid();
        cout << std::setw(20) << std::right << mv[i].getVardas() << " " << mv[i].getPavarde() << " " << mv[i].getGalutinisVid()<< std::endl;
    }
    }
    else{
        cout << "Studentas S is empty after moving\n" << "Studentas cp: \n";
        for(int i = 0; i < 10; i++)
        cout << mv[i].getVardas() << " " << mv[i].getPavarde() << " " << mv[i].getGalutinisVid()<< std::endl;
    }
}

    return 0;
}