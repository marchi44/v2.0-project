#ifndef FUNKCIJOS_TEMP_H
#define FUNKCIJOS_TEMP_H

#include "lib.h"
#include "studentas.h"

/**
 * @brief Interactively reads student data (name + grades) from the keyboard.
 *
 * Prompts the user to enter one student per iteration. For each student:
 *   - Name and surname are read from a single line.
 *   - Homework grades are entered via `pazymiu_ivedimas()`.
 *   - The mean is computed and stored.
 *   - The exam result is entered via `egz_ivedimas()`.
 *
 * The loop stops when:
 *   - `mok_sk` entries have been entered (if `mok_sk != 0`), **or**
 *   - The user submits an empty line (if `mok_sk == 0`, unknown count).
 *
 * @tparam Container Any STL sequence container of Studentas.
 * @param S       Destination container; students are appended via push_back.
 * @param mok_sk  Known number of students to read, or 0 if unknown (user
 *                signals end with an empty line).
 */
template<typename Container>
void mokinio_info_ivedimas(Container &S, int mok_sk) {
    int i = 0;
    std::string eil, vrd, pvrd;
    while (true) {
        if (mok_sk != 0 && i >= mok_sk) break;

        std::cout << "Iveskite " << i + 1 << "-ojo mokinio varda ir pavarde. Tuscia eilute - baigti\n";
        std::getline(std::cin, eil);

        if (mok_sk == 0 && eil.empty() && i != 0) break;

        std::stringstream ss(eil);
        if (!(ss >> vrd >> pvrd)) {
            std::cout << "Klaida! Turite ivesti varda ir pavarde...\n";
            std::cin.clear();
            continue;
        }

        S.push_back(Studentas(vrd, pvrd));
        int paz_sk;
        pazymiu_ivedimas(S.back());
        S.back().setVidurkis(vidurkis(S.back(), paz_sk));
        S.back().setEgzRez(egz_ivedimas());
        i++;
    }
}

/**
 * @brief Reads student data from a `.txt` file into a container.
 *
 * The file path is entered interactively. The file must:
 *   - Have a `.txt` extension.
 *   - Contain a header line (skipped automatically).
 *   - Have one student per line in the format:
 *     @code
 *       Vardas Pavarde ND1 ND2 ... Egzaminas
 *     @endcode
 *
 * The last integer on each line is treated as the exam result.
 * All grades must be in [1–10]; any out-of-range value throws a runtime_error.
 *
 * @note When `meniu_pasirinkimas == 1` the function validates each grade strictly.
 *       Otherwise the grade parsing loop is skipped (e.g. for random-generation mode).
 *
 * @tparam Container Any STL sequence container of Studentas.
 * @param S                   Destination container; students are appended via push_back.
 * @param meniu_pasirinkimas  Menu choice from the main menu (affects grade reading).
 *
 * @throws std::runtime_error If the filename is invalid, the file cannot be opened,
 *                            a grade is out of range, or a student has no homework grades.
 */
template<typename Container>
void ivedimas_is_failo(Container &S, int meniu_pasirinkimas) {
    string path;
    cout << "Iveskite failo, is kurio norite nuskaityti, pavadinima (pvz., kursiokai.txt): ";
    cin >> path;
    if (path.empty() || path.size() < 4 || path.substr(path.size() - 4) != ".txt") {
        cin.clear();
        throw std::runtime_error("Klaida! Failo pavadinimas turi baigtis .txt...\n");
    }
    std::ifstream in(path);
    if (!in) {
        throw std::runtime_error("Klaida! Nepavyko atidaryti failo...\n");
    }
    string eil;
    getline(in, eil); // skip header
    while (getline(in, eil)) {
        int paz_suma = 0;
        if (eil.empty()) continue;

        std::istringstream ss(eil);
        int paz;
        Studentas tmp;
        string vrd, pvrd;
        ss >> vrd >> pvrd;
        tmp.setVardas(vrd);
        tmp.setPavarde(pvrd);
        if (meniu_pasirinkimas == 1) {
            while (ss >> paz) {
                if (paz > 0 && paz <= 10) {
                    tmp.getNdRez().push_back(paz);
                    paz_suma += paz;
                } else {
                    throw std::runtime_error("Klaida! Pazymiai turi buti desimtbaleje sistemoje...\n");
                }
            }
        }
        if (!tmp.getNdRez().empty()) {
            tmp.setEgzRez(tmp.getNdRez().back());
            tmp.getNdRez().pop_back();
        } else if (meniu_pasirinkimas == 1) {
            throw std::runtime_error("Klaida! Mokinio " + tmp.getVardas() + " "
                                     + tmp.getPavarde() + " namu darbu pazymiai nerasti...\n");
        }
        tmp.setVidurkis(static_cast<double>(paz_suma - tmp.getEgzRez())
                        / static_cast<double>(tmp.getNdRez().size()));
        S.push_back(tmp);
    }
}

/**
 * @brief Writes one group of students to a formatted `.txt` file.
 *
 * Creates (or overwrites) the file at `failo_pavadinimas` and writes a table with
 * columns: Vardas, Pavarde, Galutinis (Vid.), Galutinis (Med.).
 * All values are formatted to 2 decimal places.
 *
 * @tparam Container Any STL sequence container of Studentas.
 * @param grupe            Container of students to write.
 * @param failo_pavadinimas Output filename (e.g. "dundukai.txt").
 */
template<typename Container>
void rasyti_i_faila(const Container& grupe, const std::string& failo_pavadinimas) {
    std::ofstream out(failo_pavadinimas);
    if (!out) {
        std::cerr << "Klaida! Nepavyko sukurti failo " << failo_pavadinimas << "...\n";
        return;
    }
    out << std::fixed << std::setprecision(2);
    out << std::left
        << std::setw(15) << "Vardas"
        << std::setw(25) << "Pavarde"
        << std::setw(18) << "Galutinis (Vid.)"
        << std::setw(18) << "Galutinis (Med.)" << '\n';
    out << std::string(76, '-') << '\n';
    for (const auto& s : grupe) {
        out << std::left
            << std::setw(15) << s.getVardas()
            << std::setw(25) << s.getPavarde()
            << std::setw(18) << s.getGalutinisVid()
            << std::setw(18) << s.getGalutinisMed()
            << '\n';
    }
}

/**
 * @brief Writes both student groups to their respective output files.
 *
 * Calls `rasyti_i_faila()` twice:
 *   - `Dundukai` → `dundukai.txt`
 *   - `Galvociai` → `galvociai.txt`
 *
 * @tparam Container Any STL sequence container of Studentas.
 * @param Dundukai  Container of students with final grade < 5.0.
 * @param Galvociai Container of students with final grade >= 5.0.
 */
template<typename Container>
void isvedimas_i_faila(const Container &Dundukai, const Container &Galvociai) {
    rasyti_i_faila(Dundukai, "dundukai.txt");
    rasyti_i_faila(Galvociai, "galvociai.txt");
}

/**
 * @brief Prints a formatted student table to stdout.
 *
 * Outputs a table with columns: Vardas, Pavarde, Galutinis (Vid.), Galutinis (Med.).
 * All grade values are printed with 2 decimal places.
 *
 * @tparam Container Any STL sequence container of Studentas (passed by value — a copy is made).
 * @param S Container of students to display.
 */
template<typename Container>
void isvedimas(Container S) {
    std::cout << std::left
              << std::setw(15) << "Vardas"
              << std::setw(25) << "Pavarde"
              << std::setw(18) << "Galutinis (Vid.)"
              << std::setw(18) << "Galutinis (Med.)\n";
    for (int i = 0; i < 76; i++) std::cout << "-";
    std::cout << std::endl;
    for (auto& s : S) {
        std::cout << std::left
                  << std::setw(15) << s.getVardas()
                  << std::setw(25) << s.getPavarde()
                  << std::setw(18) << std::fixed << std::setprecision(2) << s.getGalutinisVid()
                  << std::setw(18) << std::fixed << std::setprecision(2) << s.getGalutinisMed()
                  << std::endl;
    }
}

/**
 * @brief Handles menu option 2: names entered manually or from file, grades generated randomly.
 *
 * Workflow:
 *   1. Asks whether to enter names manually or read from a file.
 *   2. If from file, calls `ivedimas_is_failo()`.
 *   3. If manually, reads names in a loop.
 *   4. Generates random homework grades (1–100 grades, each in [1–10]) and a random exam result.
 *   5. Computes mean, median, and both final grades.
 *   6. Interactively sorts via `rusiavimo_pasirinkimas()`.
 *   7. Splits into Dundukai / Galvociai.
 *   8. Asks whether to output to console or file.
 *
 * @tparam Container Any STL sequence container of Studentas.
 * @param S                  Destination container for the students.
 * @param meniu_pasirinkimas The main menu choice (passed through to `ivedimas_is_failo`).
 */
template<typename Container>
void pasirinkimas2(Container &S, int meniu_pasirinkimas) {
    int mok_sk;
    std::cout << "0 - ivedimas ranka, 1 - ivedimas is failo\n";
    int input;
    try {
        std::cin >> input;
        std::cin.ignore(10000, '\n');
        if (!std::cin || (input != 0 && input != 1)) {
            throw std::runtime_error("Klaida! Turite ivesti 0 arba 1...\n");
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }
    bool ar_is_failo = (input == 1);
    if (ar_is_failo) {
        try {
            ivedimas_is_failo(S, meniu_pasirinkimas);
            for (auto& s : S) s.getNdRez().clear();
        }
        catch (const std::exception& e) {
            std::cerr << e.what();
            return;
        }
    } else {
        mok_sk = mok_sk_ivedimas();
    }

    int i = 0;
    std::string eil, vrd, pvrd;
    while (true) {
        if (ar_is_failo || (mok_sk != 0 && i >= mok_sk)) break;

        std::cout << "Iveskite " << i + 1 << "-ojo mokinio varda ir pavarde. Tuscia eilute - baigti\n";
        std::getline(std::cin, eil);

        if (mok_sk == 0 && eil.empty() && i != 0) break;

        std::stringstream ss(eil);
        if (!(ss >> vrd >> pvrd)) {
            std::cerr << "Klaida! Turite ivesti varda ir pavarde...\n";
            std::cin.clear();
            continue;
        }
        S.push_back(Studentas(vrd, pvrd));
        i++;
    }

    std::cout << "Generuojami pazymiai...\n";
    for (auto& s : S) {
        int n = rand() % 100 + 1;
        for (int i = 0; i < n; i++) s.getNdRez().push_back(rand() % 10 + 1);
        s.setEgzRez(rand() % 10 + 1);
        s.setVidurkis(vidurkis(s, s.getNdRez().size()));
    }
    for (auto& s : S) {
        std::sort(s.getNdRez().begin(), s.getNdRez().end());
        if (s.getNdRez().size() % 2 == 0) {
            s.setMediana((s.getNdRez()[s.getNdRez().size() / 2]
                         + s.getNdRez()[s.getNdRez().size() / 2 - 1]) / 2.0);
        } else {
            s.setMediana(s.getNdRez()[s.getNdRez().size() / 2]);
        }
        s.setGalutinisVid(0.4 * s.getVidurkis() + 0.6 * static_cast<double>(s.getEgzRez()));
        s.setGalutinisMed(0.4 * s.getMediana() + 0.6 * static_cast<double>(s.getEgzRez()));
    }

    rusiavimo_pasirinkimas(S);
    Container Dundukai, Galvociai;
    for (auto& s : S) {
        if (s.getGalutinisVid() >= 5.0) Galvociai.push_back(s);
        else Dundukai.push_back(s);
    }

    std::cout << "1 - isvesti i konsole, 2 - isvesti i faila\n";
    int kur_isvesti;
    try {
        std::cin >> kur_isvesti;
        std::cin.ignore(10000, '\n');
        if (!std::cin || (kur_isvesti != 1 && kur_isvesti != 2)) {
            throw std::runtime_error("Klaida! Neteisingai ivedete rezultatu isvedimo buda...\n");
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }
    if (kur_isvesti == 1) isvedimas(S);
    else isvedimas_i_faila(Dundukai, Galvociai);
}

/**
 * @brief Handles menu option 3: everything (names, surnames, grades) generated randomly.
 *
 * Workflow:
 *   1. Randomly generates between 1 and 100 students using `rnd_vardas()` / `rnd_pavarde()`.
 *   2. For each student: generates 1–100 random homework grades and one random exam result.
 *   3. Computes mean, median, and both final grades.
 *   4. Interactively sorts via `rusiavimo_pasirinkimas()`.
 *   5. Splits into Dundukai / Galvociai.
 *   6. Asks whether to output to console or file.
 *
 * @tparam Container Any STL sequence container of Studentas.
 * @param S                  Destination container for the generated students.
 * @param meniu_pasirinkimas The main menu choice (currently unused, reserved for future use).
 */
template<typename Container>
void pasirinkimas3(Container &S, int meniu_pasirinkimas) {
    std::cout << "Generuojami studentu vardai ir pavardes...\n";
    int mok_sk = rand() % 100 + 1;
    for (int i = 0; i < mok_sk; i++) {
        bool vyras = rand() % 2;
        string vardas = rnd_vardas(vyras);
        string pavarde = rnd_pavarde(vyras);
        S.push_back(Studentas(vardas, pavarde));
        int n = rand() % 100 + 1;
        for (int j = 0; j < n; j++) S.back().getNdRez().push_back(rand() % 10 + 1);
        S.back().setEgzRez(rand() % 10 + 1);
        int paz_sk = S.back().getNdRez().size();
        S.back().setVidurkis(vidurkis(S.back(), paz_sk));
        sort(S.back().getNdRez().begin(), S.back().getNdRez().end());
        if (S.back().getNdRez().size() % 2 == 0) {
            S.back().setMediana((S.back().getNdRez()[S.back().getNdRez().size() / 2]
                                + S.back().getNdRez()[S.back().getNdRez().size() / 2 - 1]) / 2.0);
        } else {
            S.back().setMediana(S.back().getNdRez()[S.back().getNdRez().size() / 2]);
        }
        S.back().setGalutinisVid(0.4 * S.back().getVidurkis()
                                 + 0.6 * static_cast<double>(S.back().getEgzRez()));
        S.back().setGalutinisMed(0.4 * S.back().getMediana()
                                 + 0.6 * static_cast<double>(S.back().getEgzRez()));
    }

    rusiavimo_pasirinkimas(S);
    Container Dundukai, Galvociai;
    for (auto& s : S) {
        if (s.getGalutinisVid() >= 5.0) Galvociai.push_back(s);
        else Dundukai.push_back(s);
    }

    std::cout << "1 - isvesti i konsole, 2 - isvesti i faila\n";
    int kur_isvesti;
    try {
        std::cin >> kur_isvesti;
        std::cin.ignore(10000, '\n');
        if (!std::cin || (kur_isvesti != 1 && kur_isvesti != 2)) {
            throw std::runtime_error("Klaida! Neteisingai ivedete rezultatu isvedimo buda...\n");
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }
    if (kur_isvesti == 1) isvedimas(S);
    else isvedimas_i_faila(Dundukai, Galvociai);
}

#endif