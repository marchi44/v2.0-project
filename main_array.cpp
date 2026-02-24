#include <iostream>
#include <string>
#include <algorithm>
#include "funkcijos.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::stringstream;
using std::getline;

int main() {
    int meniu_pasirinkimas = meniu();
    while(meniu_pasirinkimas != 4){
        switch(meniu_pasirinkimas){
        case 1:
        pasirinkimas1_arr();
        break;
        case 2:
        pasirinkimas2_arr();
        break;
        case 3:
        pasirinkimas3_arr();
        break;
        }
        meniu_pasirinkimas = meniu();
    }
    return 0;
}