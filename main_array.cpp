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

        break;
        case 3:

        break;
        }
    }
    return 0;
}