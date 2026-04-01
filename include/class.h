#ifndef CLASS_H
#define CLASS_H

#include "lib.h"
/*
struct Studentas {
    std::string Vardas;
    std::string Pavarde;
    vector<int> nd_rez;
    int egz_rez;
    double vidurkis;
    double mediana;
    double galutinis_vid;
    double galutinis_med;
};
*/

class Studentas {
private:
    std::string Vardas_;
    std::string Pavarde_;
    vector<int> nd_rez_;
    int egz_rez_ = 0;
    double vidurkis_ = 0.0;
    double mediana_ = 0.0;
    double galutinis_vid_ = 0.0;
    double galutinis_med_ = 0.0;

public:
    // Konstruktoriai
    Studentas() = default;
    Studentas(const std::string& vardas, const std::string& pavarde)
        : Vardas_(vardas), Pavarde_(pavarde) {}

    // Getteriai
    std::string getVardas() const { return Vardas_; }
    std::string getPavarde() const { return Pavarde_; }
    const vector<int>& getNdRez() const { return nd_rez_; }
    vector<int>& getNdRez() { return nd_rez_; }
    int getEgzRez() const { return egz_rez_; }
    double getVidurkis() const { return vidurkis_; }
    double getMediana() const { return mediana_; }
    double getGalutinisVid() const { return galutinis_vid_; }
    double getGalutinisMed() const { return galutinis_med_; }

    // Setteriai
    void setVardas(const std::string& vardas) { Vardas_ = vardas; }
    void setPavarde(const std::string& pavarde) { Pavarde_ = pavarde; }
    void setEgzRez(int egz) { egz_rez_ = egz; }
    void setVidurkis(double vid) { vidurkis_ = vid; }
    void setMediana(double med) { mediana_ = med; }
    void setGalutinisVid(double gv) { galutinis_vid_ = gv; }
    void setGalutinisMed(double gm) { galutinis_med_ = gm; }
};

#endif