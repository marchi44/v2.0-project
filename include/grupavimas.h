#ifndef GRUPAVIMAS_H
#define GRUPAVIMAS_H

#include "lib.h"
#include "studentas.h"

/**
 * @brief Splits students into two groups by iterating over the full container (Strategy 1).
 *
 * Every student whose mean-based final grade is >= 5.0 is pushed into `Galvociai`
 * ("smart ones"), and everyone below 5.0 is pushed into `Dundukai` ("dummies").
 * The original container `S` is left unchanged.
 *
 * @tparam Container Any STL sequence container of Studentas (e.g. std::vector, std::list).
 * @param S         Source container with all students.
 * @param Dundukai  Destination container for students with final grade < 5.0.
 * @param Galvociai Destination container for students with final grade >= 5.0.
 */
template<typename Container>
void grupavimas_pirm(Container &S, Container &Dundukai, Container &Galvociai) {
    for (auto& s : S) {
        if (s.getGalutinisVid() >= 5.0) {
            Galvociai.push_back(s);
        } else {
            Dundukai.push_back(s);
        }
    }
}

/**
 * @brief Splits students by sorting and popping from the back (Strategy 2).
 *
 * Sorts `S` in descending order by final grade (mean-based), then repeatedly
 * removes the last element (the weakest student) into `Dundukai` as long as
 * the back element has a final grade < 5.0. The remaining elements in `S`
 * are the "galvociai" (grade >= 5.0).
 *
 * @note This modifies `S` in-place: failing students are removed from it.
 *
 * @tparam Container Any STL sequence container of Studentas.
 * @param S        Source container; students with grade < 5.0 are moved out.
 * @param Dundukai Destination container for students with final grade < 5.0.
 */
template<typename Container>
void grupavimas_antras(Container& S, Container& Dundukai) {
    rusiavimas(S, 2, 3); // sort descending by galutinis_vid_
    while (S.back().getGalutinisVid() < 5) {
        Dundukai.push_back(S.back());
        S.pop_back();
    }
}

/**
 * @brief Splits students using std::stable_partition (Strategy 3, fastest).
 *
 * Uses `std::stable_partition` to rearrange `S` in-place so that all students
 * with grade >= 5.0 come first, followed by those with grade < 5.0 — without
 * changing the relative order within each group (stable).
 *
 * The failing students are then moved into `Dundukai` and erased from `S`,
 * leaving `S` containing only the passing students.
 *
 * Think of it like a librarian sliding all red books to one end of a shelf,
 * then removing them — the order of both colours is preserved.
 *
 * @tparam Container Any STL sequence container of Studentas (best with std::vector).
 * @param S        Source container; modified in-place; failing students are removed.
 * @param Dundukai Destination container for students with final grade < 5.0.
 */
template<typename Container>
void grupavimas_trecias(Container& S, Container& Dundukai) {
    auto riba = std::stable_partition(S.begin(), S.end(), [](const Studentas& s) {
        return s.getGalutinisVid() >= 5.0;
    });
    Dundukai.insert(Dundukai.end(), riba, S.end());
    S.erase(riba, S.end());
}

#endif