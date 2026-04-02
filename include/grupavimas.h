#ifndef GRUPAVIMAS_H
#define GRUPAVIMAS_H
#include "lib.h"
#include "studentas.h"

template<typename Container>
void grupavimas_pirm(Container &S, Container &Dundukai, Container &Galvociai){
    for(auto& s : S){
        if(s.galutinis_vid >= 5.0){
            Galvociai.push_back(s);
        }
        else {
            Dundukai.push_back(s);
        }
    }
}

template<typename Container>
void grupavimas_antras(Container& S, Container& Dundukai){
    rusiavimas(S, 2, 3);
    while(S.back().galutinis_vid<5){
        Dundukai.push_back(S.back());
        S.pop_back();
    }
}

template<typename Container>
void grupavimas_trecias(Container& S, Container& Dundukai){
    auto riba = std::stable_partition(S.begin(), S.end(), [](const Studentas& s){
        return s.galutinis_vid >= 5.0;
    });
    Dundukai.insert(Dundukai.end(), riba, S.end());
    S.erase(riba, S.end());
}

#endif