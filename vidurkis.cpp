#include "funkcijos.h"
#include "lib.h"

double vidurkis(vector<Studentas> &S, int i, int paz_sk){
    int paz_suma = 0;
        for (const int paz : S[i].nd_rez) {
            paz_suma += paz;
        }
    return static_cast<double>(paz_suma) / static_cast<double>(paz_sk);
}