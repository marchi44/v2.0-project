#include "funkcijos.h"

int main() {
    std::vector<Studentas> S;
    nuskaitymas(S, 10);
    skaiciavimai(S);

    // Kopijavimo konstruktorius
    Studentas s1(S[0]);
    cout << "Kopijavimo konstruktorius:\n";
    cout << "Originalas: " << S[0].getVardas() << " " << S[0].getGalutinisVid() << "\n";
    cout << "Kopija:     " << s1.getVardas()   << " " << s1.getGalutinisVid()   << "\n\n";

    // Kopijavimo priskyrimo operatorius
    Studentas s2;
    s2 = S[1];
    cout << "Kopijavimo priskyrimas:\n";
    cout << "Originalas: " << S[1].getVardas() << " " << S[1].getGalutinisVid() << "\n";
    cout << "Kopija:     " << s2.getVardas()   << " " << s2.getGalutinisVid()   << "\n\n";

    // Perkėlimo konstruktorius
    Studentas s3(std::move(S[2]));
    cout << "Perkėlimo konstruktorius:\n";
    cout << "Po perkėlimo S[2] vardas: '" << S[2].getVardas() << "' (turėtų būti tuščias)\n";
    cout << "Perkeltas:  " << s3.getVardas() << " " << s3.getGalutinisVid() << "\n\n";

    // Perkėlimo priskyrimo operatorius
    Studentas s4;
    s4 = std::move(S[3]);
    cout << "Perkėlimo priskyrimas:\n";
    cout << "Po perkėlimo S[3] vardas: '" << S[3].getVardas() << "' (turėtų būti tuščias)\n";
    cout << "Perkeltas:  " << s4.getVardas() << " " << s4.getGalutinisVid() << "\n\n";

    return 0;
}