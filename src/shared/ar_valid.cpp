#include "funkcijos.h"

bool ar_valid(const string& input){
    for (const char c : input) {
            if (!isdigit(c)) {
                return false;
            }
        }
    return true;
}