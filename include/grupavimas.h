#ifndef GRUPAVIMAS_H
#define GRUPAVIMAS_H
#include "lib.h"
#include "struktura.h"

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
    for(auto it = S.begin(); it != S.end(); ){
        if(it->galutinis_vid < 5.0){
            Dundukai.push_back(*it);
            it = S.erase(it);
        } else {
            ++it;
        }
    }
}

#endif