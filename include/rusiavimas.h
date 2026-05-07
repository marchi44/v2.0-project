#ifndef RUSIAVIMAS_H
#define RUSIAVIMAS_H

#include "funkcijos.h"
#include "lib.h"

/**
 * @brief Interactively asks the user to choose a sort direction and sort key,
 *        then sorts the container accordingly.
 *
 * Prompts for:
 *   1. Direction: ascending (1) or descending (2).
 *   2. Key: first name (1), surname (2), mean-based final grade (3),
 *           or median-based final grade (4).
 *
 * On invalid input an error message is printed and the function returns early
 * without sorting.
 *
 * @tparam Container Any STL sequence container of Studentas (e.g. std::vector).
 * @param S Container of students to sort in-place.
 */
template<typename Container>
void rusiavimo_pasirinkimas(Container &S) {
    std::cout << "1 - rusiuoti didejanciai, 2 - rusiuoti mazejanciai\n";
    int did_ar_maz;
    try {
        std::cin >> did_ar_maz;
        std::cin.ignore(10000, '\n');
        if (!std::cin || (did_ar_maz != 1 && did_ar_maz != 2)) {
            throw std::runtime_error("Klaida! Neteisingai pasirinktas rusiavimas...\n");
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }

    int pagal_ka_rusiuoti;
    std::cout << "1 - rusiuoti pagal varda, 2 - rusiuoti pagal pavarde, "
              << "3 - rusiuoti pagal galutini (Vid.) rezultata, "
              << "4 - rusiuoti pagal galutini (Med.) rezultata\n";
    try {
        std::cin >> pagal_ka_rusiuoti;
        std::cin.ignore(10000, '\n');
        if (!std::cin || pagal_ka_rusiuoti < 1 || pagal_ka_rusiuoti > 4) {
            throw std::runtime_error("Klaida! Neteisingai pasirinkta pagal ka rusiuoti...\n");
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }

    rusiavimas(S, did_ar_maz, pagal_ka_rusiuoti);
}

/**
 * @brief Sorts a container of students by a chosen field in ascending or descending order.
 *
 * Uses `std::sort` with a lambda comparator selected by `pagal_ka_rusiuoti`.
 * Sorting is performed in-place on the container.
 *
 * | pagal_ka_rusiuoti | Sorted by                        |
 * |-------------------|----------------------------------|
 * | 1                 | First name (alphabetical)        |
 * | 2                 | Surname (alphabetical)           |
 * | 3                 | Mean-based final grade (numeric) |
 * | 4                 | Median-based final grade (numeric)|
 *
 * @tparam Container Any STL random-access sequence container of Studentas.
 * @param S                  Container of students to sort.
 * @param did_ar_maz         Sort direction: 1 = ascending, 2 = descending.
 * @param pagal_ka_rusiuoti  Sort key (1–4), see table above.
 */
template<typename Container>
void rusiavimas(Container &S, int did_ar_maz, int pagal_ka_rusiuoti) {
    if (did_ar_maz == 1) {
        switch (pagal_ka_rusiuoti) {
            case 1:
                std::sort(S.begin(), S.end(), [](const Studentas& a, const Studentas& b) {
                    return a.getVardas() < b.getVardas();
                });
                break;
            case 2:
                std::sort(S.begin(), S.end(), [](const Studentas& a, const Studentas& b) {
                    return a.getPavarde() < b.getPavarde();
                });
                break;
            case 3:
                std::sort(S.begin(), S.end(), [](const Studentas& a, const Studentas& b) {
                    return a.getGalutinisVid() < b.getGalutinisVid();
                });
                break;
            case 4:
                std::sort(S.begin(), S.end(), [](const Studentas& a, const Studentas& b) {
                    return a.getGalutinisMed() < b.getGalutinisMed();
                });
                break;
        }
    } else {
        switch (pagal_ka_rusiuoti) {
            case 1:
                std::sort(S.begin(), S.end(), [](const Studentas& a, const Studentas& b) {
                    return a.getVardas() > b.getVardas();
                });
                break;
            case 2:
                std::sort(S.begin(), S.end(), [](const Studentas& a, const Studentas& b) {
                    return a.getPavarde() > b.getPavarde();
                });
                break;
            case 3:
                std::sort(S.begin(), S.end(), [](const Studentas& a, const Studentas& b) {
                    return a.getGalutinisVid() > b.getGalutinisVid();
                });
                break;
            case 4:
                std::sort(S.begin(), S.end(), [](const Studentas& a, const Studentas& b) {
                    return a.getGalutinisMed() > b.getGalutinisMed();
                });
                break;
        }
    }
}

#endif
