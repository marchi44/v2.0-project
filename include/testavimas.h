#ifndef TESTAVIMAS_H
#define TESTAVIMAS_H

#include "lib.h"
#include "studentas.h"

/**
 * @brief Reads student data from a generated test file into a container.
 *
 * Opens a file named `test_<dydis>.txt` (e.g. `test_100000.txt`), skips the
 * header line, and parses each subsequent line in the format:
 * @code
 *   Vardas Pavarde ND1 ND2 ... NDn Egzaminas
 * @endcode
 * The last integer on each line is treated as the exam result; all preceding
 * integers are homework grades. The mean is computed and stored.
 *
 * On file-open failure an error is printed and the function returns early.
 *
 * @tparam Container Any STL sequence container of Studentas.
 * @param S     Destination container; students are appended via push_back.
 * @param dydis Number of records the file is expected to contain (used only
 *              to construct the filename, e.g. 100000 or 1000000).
 */
template<typename Container>
void nuskaitymas(Container &S, const int& dydis) {
    string path = "test_" + std::to_string(dydis) + ".txt";
    cout << "Skaitomas failas " << path << "...\n";
    std::ifstream in(path);
    if (!in) {
        std::cerr << "Klaida! Nepavyko atidaryti failo " << path << "...\n";
        return;
    }
    string eil;
    getline(in, eil); // skip header row
    while (getline(in, eil)) {
        if (eil.empty()) continue;

        std::istringstream ss(eil);
        int paz, pazSuma = 0;
        Studentas tmp;
        string vrd, pvrd;
        ss >> vrd >> pvrd;
        tmp.setVardas(vrd);
        tmp.setPavarde(pvrd);
        while (ss >> paz) {
            if (paz > 0 && paz <= 10) {
                tmp.getNdRez().push_back(paz);
                pazSuma += paz;
            }
        }
        if (!tmp.getNdRez().empty()) {
            tmp.setEgzRez(tmp.getNdRez().back());
            tmp.getNdRez().pop_back();
        }
        tmp.setVidurkis(static_cast<double>(pazSuma - tmp.getEgzRez())
                        / static_cast<double>(tmp.getNdRez().size()));
        S.push_back(tmp);
    }
    in.close();
}

/**
 * @brief Computes median and final grades for every student, then sorts the container.
 *
 * For each student in `S`:
 *   - Sorts the homework grades to find the median.
 *   - Sets the median-based and mean-based final grades using the formula:
 *     @code
 *       galutinis = 0.4 * (mean or median) + 0.6 * egz_rez_
 *     @endcode
 *
 * After computing, sorts `S` ascending by mean-based final grade.
 *
 * @tparam Container Any STL sequence container of Studentas.
 * @param S Container of students to process in-place.
 */
template<typename Container>
void skaiciavimai(Container &S) {
    for (auto& s : S) {
        std::sort(s.getNdRez().begin(), s.getNdRez().end());
        if (s.getNdRez().size() % 2 == 0) {
            s.setMediana((s.getNdRez()[s.getNdRez().size() / 2]
                        + s.getNdRez()[s.getNdRez().size() / 2 - 1]) / 2.0);
        } else {
            s.setMediana(s.getNdRez()[s.getNdRez().size() / 2]);
        }
        s.setGalutinisVid(0.4 * s.getVidurkis()
                          + 0.6 * static_cast<double>(s.getEgzRez()));
        s.setGalutinisMed(0.4 * s.getMediana()
                          + 0.6 * static_cast<double>(s.getEgzRez()));
    }
    rusiavimas(S, 1, 3);
}

/**
 * @brief Benchmarks reading, grouping, and file output for various dataset sizes.
 *
 * Runs a performance test over the sizes {1k, 10k, 100k, 1M, 10M}, measuring
 * three phases separately for each size using `std::chrono::high_resolution_clock`:
 *   1. **Reading** — loading the file into a Container via `nuskaitymas()`.
 *   2. **Grouping** — computing final grades and splitting into two groups via
 *      `skaiciavimai()` + `grupavimas_pirm()`.
 *   3. **Output** — writing both groups to files via `isvedimas_i_faila()`.
 *
 * Results and totals are printed to stdout.
 *
 * @tparam Container STL container type to use for the benchmark (e.g. std::vector<Studentas>).
 */
template<typename Container>
void antras_tyrimas() {
    int dydziai[] = {1000, 10000, 100000, 1000000, 10000000};
    for (const int& dydis : dydziai) {
        auto start_nusk = std::chrono::high_resolution_clock::now();
        Container S;
        nuskaitymas(S, dydis);
        auto end_nusk = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_nusk = end_nusk - start_nusk;
        cout << std::fixed << std::setprecision(6)
             << "Failas su " << dydis << " studentu nuskaitytas per "
             << elapsed_nusk.count() << " s\n";

        auto start_grupe = std::chrono::high_resolution_clock::now();
        Container Dundukai, Galvociai;
        skaiciavimai(S);
        grupavimas_pirm(S, Dundukai, Galvociai);
        auto end_grupe = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_grupe = end_grupe - start_grupe;
        cout << std::fixed << std::setprecision(6)
             << dydis << " studentu surusiuoti i dvi grupes per "
             << elapsed_grupe.count() << " s\n";

        auto start_isv = std::chrono::high_resolution_clock::now();
        isvedimas_i_faila(Dundukai, Galvociai);
        auto end_isv = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_isv = end_isv - start_isv;
        cout << std::fixed << std::setprecision(6)
             << dydis << " studentu isvesti i skirtingus failus pagal grupes per "
             << elapsed_isv.count() << " s\n";
        cout << std::fixed << std::setprecision(6)
             << "Visas procesas su " << dydis << " studentu uztruko "
             << elapsed_nusk.count() + elapsed_grupe.count() + elapsed_isv.count()
             << " s\n\n\n";
    }
}

#endif
