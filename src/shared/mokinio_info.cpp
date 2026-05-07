#include "funkcijos.h"
#include "lib.h"

/**
 * @brief Asks the user how many students there are and returns that count.
 *
 * The user may either type a positive integer or press Enter without typing
 * anything (unknown count). In the latter case 0 is returned, signalling to
 * the caller that the number of students is not known in advance.
 *
 * Input is validated with `ar_valid()` to prevent non-numeric strings from
 * reaching `stoi()`.
 *
 * @return Number of students as a positive integer, or 0 if the count is unknown.
 */
int mok_sk_ivedimas() {
    std::string input;
    while (true) {
        std::cout << "Iveskite kiek yra mokiniu (jei is anksto nezinote paspauskite ENTER) \n";
        std::getline(std::cin, input, '\n');
        if (input.empty()) return 0;

        bool valid = ar_valid(input);
        if (valid && stoi(input) > 0) return stoi(input);

        std::cout << "Klaida! Jusu ivestas mokiniu skaicius privalo buti sveikas skaicius didesnis uz nuli. Bandykite is naujo...\n";
        std::cin.clear();
    }
}

/**
 * @brief Asks the user how many homework grades a student has.
 *
 * Works the same as `mok_sk_ivedimas()`: the user may press Enter to signal
 * that the count is unknown (returns 0). Otherwise a positive integer is expected.
 *
 * @return Number of homework grades as a positive integer, or 0 if unknown.
 */
int paz_sk_ivedimas() {
    while (true) {
        std::string input;
        std::cout << "Kiek mokinys turi pazymiu is namu darbu? Jei nezinote pazymiu kiekio paspauskite ENTER\n";
        std::getline(std::cin, input);
        if (input.empty()) return 0;

        bool valid = ar_valid(input);
        if (valid && stoi(input) > 0) return stoi(input);

        std::cout << "Klaida! Jusu ivestas pazymiu skaicius privalo buti sveikas skaicius (>0). Bandykite is naujo...\n";
    }
}

/**
 * @brief Reads homework grades from the keyboard and stores them in a student object.
 *
 * First calls `paz_sk_ivedimas()` to determine how many grades to expect.
 * If the count is unknown (returns 0), the user signals the end by entering `0`.
 *
 * Each grade is validated:
 *   - Must pass `ar_valid()` (digits only).
 *   - Must be in [1, 10].
 *
 * Grades are stored directly into the student's `nd_rez_` vector via
 * the mutable reference returned by `getNdRez()`.
 *
 * @param s Reference to the Studentas whose `nd_rez_` will be populated.
 */
void pazymiu_ivedimas(Studentas &s) {
    std::string input;
    int paz_sk = paz_sk_ivedimas();
    bool nezinomas_kiek = (paz_sk == 0);
    bool baigta = false;
    if (nezinomas_kiek) paz_sk = 1;

    std::cout << "Iveskite mokinio namu darbu rezultatus (0 - baigti, jei kiekis nezinomas): \n";
    for (int j = 0; j < paz_sk; j++) {
        while (true) {
            std::cin >> input;
            std::cin.ignore(10000, '\n');
            if (!ar_valid(input)) {
                std::cout << "Klaida! Jusu ivestas pazymys privalo buti sveikas skaicius (1-10). Bandykite is naujo...\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            if (nezinomas_kiek && stoi(input) == 0) {
                baigta = true;
                break;
            }
            if (stoi(input) > 0 && stoi(input) <= 10) {
                s.getNdRez().push_back(stoi(input));
                break;
            }
            std::cout << "Klaida! Jusu ivestas pazymys privalo buti sveikas skaicius (1-10). Bandykite is naujo...\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        if (baigta) break;
        else if (nezinomas_kiek) paz_sk++;
    }
}

/**
 * @brief Reads and validates a single exam result from the keyboard.
 *
 * Loops until the user enters a digit-only string representing an integer
 * in [1, 10]. On invalid input an error message is printed and the user
 * is prompted again.
 *
 * @return The exam result as an integer in [1, 10].
 */
int egz_ivedimas() {
    std::string input;
    std::cout << "Iveskite mokinio egzamino rezultata: \n";
    while (true) {
        std::cin >> input;
        std::cin.ignore(10000, '\n');
        bool valid = !input.empty() && ar_valid(input);
        if (valid && stoi(input) > 0 && stoi(input) <= 10) {
            return stoi(input);
        }
        std::cout << "Klaida! Jusu ivestas pazymys privalo buti sveikas skaicius (1-10). Bandykite is naujo...\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}

/**
 * @brief Computes the arithmetic mean of a student's homework grades.
 *
 * Sums all values in `s.getNdRez()` and divides by `paz_sk`.
 * Both operands are cast to `double` to avoid integer division.
 *
 * @param s      The student whose homework grades are used.
 * @param paz_sk The number of homework grades (divisor). Must be > 0.
 * @return The arithmetic mean as a double.
 */
double vidurkis(Studentas &s, int paz_sk) {
    int paz_suma = 0;
    for (const int paz : s.getNdRez()) {
        paz_suma += paz;
    }
    return static_cast<double>(paz_suma) / static_cast<double>(paz_sk);
}

/**
 * @brief Asks the user to choose between mean ("vid") and median ("med") for final grade.
 *
 * Loops until the user types exactly `vid` or `med` (case-sensitive).
 * The returned string is used elsewhere to decide which final grade field to display.
 *
 * @return "vid" if the user chose mean, "med" if the user chose median.
 */
string med_ar_vid() {
    string vid_ar_med;
    std::cout << "Koki metoda norite naudoti galutinio pazymio apskaiciavimui? vid (vidurkio) ar med (medianos)?\n";
    while (true) {
        std::cin >> vid_ar_med;
        std::cin.ignore(10000, '\n');
        if (vid_ar_med == "vid" || vid_ar_med == "med") return vid_ar_med;
        std::cout << "Klaida! Privalote ivesti vid arba med... \n";
    }
}
