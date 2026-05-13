#ifndef STUDENTAS_H
#define STUDENTAS_H

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
    Studentas()
        : Vardas_(""), Pavarde_(""), nd_rez_(), egz_rez_(0), vidurkis_(0.0), mediana_(0.0),
        galutinis_vid_(0.0), galutinis_med_(0.0) {}
    Studentas(const std::string& vardas, const string& pavarde, const vector<int>& nd,
              const int& egz, const double& vid, const double& med, const double& gv, const double& gm)
        : Vardas_(vardas), Pavarde_(pavarde), nd_rez_(nd), egz_rez_(egz), vidurkis_(vid), mediana_(med),
        galutinis_vid_(gv), galutinis_med_(gm) {}
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

    // Destruktorius
    ~Studentas() {
        Vardas_ = "";
        Pavarde_ = "";
        nd_rez_.clear();
        egz_rez_ = 0;
        vidurkis_ = 0.0;
        mediana_ = 0.0;
        galutinis_vid_ = 0.0;
        galutinis_med_ = 0.0;
    }

    // Kopijavimo konstruktorius
    Studentas(const Studentas& other)
        : Vardas_(other.Vardas_), Pavarde_(other.Pavarde_), nd_rez_(other.nd_rez_),
          egz_rez_(other.egz_rez_), vidurkis_(other.vidurkis_), mediana_(other.mediana_),
          galutinis_vid_(other.galutinis_vid_), galutinis_med_(other.galutinis_med_) {}

    // Kopijavimo priskyrimo operatorius
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            Vardas_ = other.Vardas_;
            Pavarde_ = other.Pavarde_;
            nd_rez_ = other.nd_rez_;
            egz_rez_ = other.egz_rez_;
            vidurkis_ = other.vidurkis_;
            mediana_ = other.mediana_;
            galutinis_vid_ = other.galutinis_vid_;
            galutinis_med_ = other.galutinis_med_;
        }
        return *this;
    }

    // Perkėlimo konstruktorius
    Studentas(Studentas&& other) noexcept
        : Vardas_(std::move(other.Vardas_)), Pavarde_(std::move(other.Pavarde_)),
          nd_rez_(std::move(other.nd_rez_)), egz_rez_(other.egz_rez_),
          vidurkis_(other.vidurkis_), mediana_(other.mediana_),
          galutinis_vid_(other.galutinis_vid_), galutinis_med_(other.galutinis_med_)  {}

    // Perkėlimo priskyrimo operatorius
    Studentas& operator=(Studentas&& other) noexcept {
        if (this != &other) {
            Vardas_ = std::move(other.Vardas_);
            Pavarde_ = std::move(other.Pavarde_);
            nd_rez_ = std::move(other.nd_rez_);
            egz_rez_ = other.egz_rez_;
            vidurkis_ = other.vidurkis_;
            mediana_ = other.mediana_;
            galutinis_vid_ = other.galutinis_vid_;
            galutinis_med_ = other.galutinis_med_;
            other.egz_rez_ = 0;
            other.vidurkis_ = 0;
            other.mediana_ = 0;
            other.galutinis_vid_ = 0;
            other.galutinis_med_ = 0;
        }
        return *this;
    }

    // Išvedimo operatorius
    friend std::ostream& operator<<(std::ostream& out, const Studentas& s) {
        out << std::left << std::setw(15) << s.Vardas_
        << std::setw(25) << s.Pavarde_
        << std::setw(18) << std::fixed << std::setprecision(2) << s.galutinis_vid_
        << std::setw(18) << s.galutinis_med_ << std::endl;
        return out;
    }

    //ivedimo operatorius
    friend std::istream& operator>>(std::istream& in, Studentas& s) {
    std::string eilute;
    if(!std::getline(in, eilute)) return in;
    if(eilute.empty()) {
        if(!std::getline(in, eilute)) return in;
    }
    
    std::istringstream ss(eilute);
    if(!(ss >> s.Vardas_ >> s.Pavarde_)) return in;
    
    int paz, pazSuma = 0;
    while(ss >> paz) {
        if(paz > 0 && paz <= 10) {
            s.nd_rez_.push_back(paz);
            pazSuma += paz;
        }
    }
    if(!s.nd_rez_.empty()) {
        s.egz_rez_ = s.nd_rez_.back();
        s.nd_rez_.pop_back();
    }
    s.vidurkis_ = static_cast<double>(pazSuma - s.egz_rez_)
                / static_cast<double>(s.nd_rez_.size());
    return in;
}
};

#endif