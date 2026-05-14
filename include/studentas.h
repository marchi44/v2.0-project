#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "lib.h"

/**
 * @brief Abstract base class representing a person with a first and last name.
 *
 * Zmogus (Lithuanian: "person") serves as an abstract base class in the
 * class hierarchy. It stores a person's name and surname and enforces a
 * pure virtual `print()` function that all derived classes must implement.
 *
 * It fully satisfies the Rule of Five:
 * - Default and parameterised constructors
 * - Copy constructor and copy assignment operator
 * - Move constructor and move assignment operator
 * - Virtual destructor (required for safe polymorphic deletion)
 */
class Zmogus {
    protected:
        std::string Vardas_;   ///< First name of the person.
        std::string Pavarde_;  ///< Last name (surname) of the person.

    public:
        

        /**
         * @brief Default constructor. Initialises name and surname to empty strings.
         */
        Zmogus()
            : Vardas_(""), Pavarde_("") {}

        /**
         * @brief Parameterised constructor.
         * @param vardas  First name of the person.
         * @param pavarde Surname of the person.
         */
        Zmogus(const std::string& vardas, const std::string& pavarde)
            : Vardas_(vardas), Pavarde_(pavarde) {}

        

        /**
         * @brief Returns the first name.
         * @return First name as a string.
         */
        std::string getVardas() const { return Vardas_; }

        /**
         * @brief Returns the surname.
         * @return Surname as a string.
         */
        std::string getPavarde() const { return Pavarde_; }

        

        /**
         * @brief Sets the first name.
         * @param vardas New first name.
         */
        void setVardas(const std::string& vardas) { Vardas_ = vardas; }

        /**
         * @brief Sets the surname.
         * @param pavarde New surname.
         */
        void setPavarde(const std::string& pavarde) { Pavarde_ = pavarde; }

        

        /**
         * @brief Pure virtual function that prints information about the person.
         *
         * Every derived class must provide its own implementation.
         * This makes Zmogus an abstract class — you cannot create a plain
         * `Zmogus` object directly.
         */
        virtual void print() const = 0;

        

        /**
         * @brief Virtual destructor. Clears name fields before destruction.
         *
         * The destructor is virtual so that deleting a `Zmogus*` that actually
         * points to a `Studentas` will correctly call `Studentas`'s destructor.
         */
        virtual ~Zmogus() {
            Vardas_ = "";
            Pavarde_ = "";
        }

        /**
         * @brief Copy constructor. Creates a deep copy of another Zmogus.
         * @param other The Zmogus instance to copy from.
         */
        Zmogus(const Zmogus& other)
            : Vardas_(other.Vardas_), Pavarde_(other.Pavarde_) {}

        /**
         * @brief Copy assignment operator.
         * @param other The Zmogus instance to copy from.
         * @return Reference to this object.
         */
        Zmogus& operator=(const Zmogus& other) {
            if (this != &other) {
                Vardas_ = other.Vardas_;
                Pavarde_ = other.Pavarde_;
            }
            return *this;
        }

        /**
         * @brief Move constructor. Transfers ownership of name strings.
         * @param other The Zmogus instance to move from. Left in a valid empty state.
         */
        Zmogus(Zmogus&& other) noexcept
            : Vardas_(std::move(other.Vardas_)), Pavarde_(std::move(other.Pavarde_)) {}

        /**
         * @brief Move assignment operator.
         * @param other The Zmogus instance to move from. Left in a valid empty state.
         * @return Reference to this object.
         */
        Zmogus& operator=(Zmogus&& other) noexcept {
            if (this != &other) {
                Vardas_ = std::move(other.Vardas_);
                Pavarde_ = std::move(other.Pavarde_);
            }
            return *this;
        }
};



/**
 * @brief Represents a student with homework grades, an exam result, and computed final scores.
 *
 * Studentas (Lithuanian: "student") inherits from Zmogus and extends it with
 * academic data: a list of homework grades (`nd_rez_`), an exam result (`egz_rez_`),
 * and two versions of the final grade — one based on the mean (`galutinis_vid_`)
 * and one based on the median (`galutinis_med_`).
 *
 * Final grade formula:
 * @code
 *   galutinis = 0.4 * (mean or median of nd_rez_) + 0.6 * egz_rez_
 * @endcode
 *
 * Fully satisfies the Rule of Five, delegating base-class operations to Zmogus.
 */
class Studentas : public Zmogus {
private:
    vector<int> nd_rez_;        ///< Homework grades (namų darbų rezultatai).
    int egz_rez_ = 0;           ///< Exam result (egzamino rezultatas), range [1–10].
    double vidurkis_ = 0.0;     ///< Arithmetic mean of homework grades.
    double mediana_ = 0.0;      ///< Median of homework grades.
    double galutinis_vid_ = 0.0;///< Final grade computed using the mean.
    double galutinis_med_ = 0.0;///< Final grade computed using the median.

public:
    

    /**
     * @brief Default constructor. Initialises all fields to zero/empty.
     */
    Studentas()
        : Zmogus(), nd_rez_(), egz_rez_(0), vidurkis_(0.0), mediana_(0.0),
          galutinis_vid_(0.0), galutinis_med_(0.0) {}

    /**
     * @brief Fully parameterised constructor.
     * @param vardas  First name.
     * @param pavarde Surname.
     * @param nd      Vector of homework grades.
     * @param egz     Exam result.
     * @param vid     Pre-computed mean of homework grades.
     * @param med     Pre-computed median of homework grades.
     * @param gv      Pre-computed final grade (mean-based).
     * @param gm      Pre-computed final grade (median-based).
     */
    Studentas(const std::string& vardas, const string& pavarde, const vector<int>& nd,
              const int& egz, const double& vid, const double& med,
              const double& gv, const double& gm)
        : Zmogus(vardas, pavarde), nd_rez_(nd), egz_rez_(egz), vidurkis_(vid),
          mediana_(med), galutinis_vid_(gv), galutinis_med_(gm) {}

    /**
     * @brief Name-only constructor. Grades are left at default (zero/empty).
     * @param vardas  First name.
     * @param pavarde Surname.
     */
    Studentas(const std::string& vardas, const std::string& pavarde)
        : Zmogus(vardas, pavarde) {}

    

    /**
     * @brief Returns a const reference to the homework grades vector.
     * @return Const reference to nd_rez_.
     */
    const vector<int>& getNdRez() const { return nd_rez_; }

    /**
     * @brief Returns a mutable reference to the homework grades vector.
     *
     * Allows direct modification, e.g. `s.getNdRez().push_back(8)`.
     * @return Reference to nd_rez_.
     */
    vector<int>& getNdRez() { return nd_rez_; }

    /**
     * @brief Returns the exam result.
     * @return Exam result in range [1–10].
     */
    int getEgzRez() const { return egz_rez_; }

    /**
     * @brief Returns the arithmetic mean of homework grades.
     * @return Mean value as a double.
     */
    double getVidurkis() const { return vidurkis_; }

    /**
     * @brief Returns the median of homework grades.
     * @return Median value as a double.
     */
    double getMediana() const { return mediana_; }

    /**
     * @brief Returns the final grade computed using the mean.
     * @return Final grade (mean-based) as a double.
     */
    double getGalutinisVid() const { return galutinis_vid_; }

    /**
     * @brief Returns the final grade computed using the median.
     * @return Final grade (median-based) as a double.
     */
    double getGalutinisMed() const { return galutinis_med_; }

    

    /**
     * @brief Sets the exam result.
     * @param egz Exam result, expected in range [1–10].
     */
    void setEgzRez(int egz) { egz_rez_ = egz; }

    /**
     * @brief Sets the arithmetic mean of homework grades.
     * @param vid Computed mean value.
     */
    void setVidurkis(double vid) { vidurkis_ = vid; }

    /**
     * @brief Sets the median of homework grades.
     * @param med Computed median value.
     */
    void setMediana(double med) { mediana_ = med; }

    /**
     * @brief Sets the final grade based on the mean.
     * @param gv Final grade (mean-based).
     */
    void setGalutinisVid(double gv) { galutinis_vid_ = gv; }

    /**
     * @brief Sets the final grade based on the median.
     * @param gm Final grade (median-based).
     */
    void setGalutinisMed(double gm) { galutinis_med_ = gm; }

    

    /**
     * @brief Prints the student's name and mean-based final grade to stdout.
     *
     * Implements the pure virtual `print()` from Zmogus.
     */
    void print() const override {
        std::cout << Vardas_ << " " << Pavarde_
                  << " | Galutinis pazymys: " << galutinis_vid_ << "\n";
    }

    

    /**
     * @brief Destructor. Clears all grade data and resets numeric fields.
     */
    ~Studentas() {
        nd_rez_.clear();
        egz_rez_ = 0;
        vidurkis_ = 0.0;
        mediana_ = 0.0;
        galutinis_vid_ = 0.0;
        galutinis_med_ = 0.0;
    }

    /**
     * @brief Copy constructor. Performs a deep copy of all fields.
     * @param other The Studentas instance to copy from.
     */
    Studentas(const Studentas& other)
        : Zmogus(other), nd_rez_(other.nd_rez_),
          egz_rez_(other.egz_rez_), vidurkis_(other.vidurkis_),
          mediana_(other.mediana_),
          galutinis_vid_(other.galutinis_vid_),
          galutinis_med_(other.galutinis_med_) {}

    /**
     * @brief Copy assignment operator.
     * @param other The Studentas instance to copy from.
     * @return Reference to this object.
     */
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            Zmogus::operator=(other);
            nd_rez_ = other.nd_rez_;
            egz_rez_ = other.egz_rez_;
            vidurkis_ = other.vidurkis_;
            mediana_ = other.mediana_;
            galutinis_vid_ = other.galutinis_vid_;
            galutinis_med_ = other.galutinis_med_;
        }
        return *this;
    }

    /**
     * @brief Move constructor. Transfers resources without copying.
     * @param other The Studentas instance to move from. Left in a valid empty state.
     */
    Studentas(Studentas&& other) noexcept
        : Zmogus(std::move(other)), nd_rez_(std::move(other.nd_rez_)), egz_rez_(other.egz_rez_),
          vidurkis_(other.vidurkis_), mediana_(other.mediana_),
          galutinis_vid_(other.galutinis_vid_), galutinis_med_(other.galutinis_med_)  {
            other.egz_rez_ = 0;
            other.vidurkis_ = 0;
            other.mediana_ = 0;
            other.galutinis_vid_ = 0;
            other.galutinis_med_ = 0;
          }

    /**
     * @brief Move assignment operator.
     * @param other The Studentas instance to move from. Left in a valid empty state.
     * @return Reference to this object.
     */
    Studentas& operator=(Studentas&& other) noexcept {
        if (this != &other) {
            Zmogus::operator=(std::move(other));
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
