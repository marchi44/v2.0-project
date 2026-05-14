#include "doctest.h"
#include "funkcijos.h"

TEST_CASE("Studentas: I/O Operators and Data Integrity") {
    // Išvedimo operatoriaus testas
    std::vector<Studentas> S;
    nuskaitymas(S, 10);
    skaiciavimai(S);
    rusiavimas(S, 1, 1);

    SUBCASE("Console and File Output") {
        std::cout << "operator<< testas (i konsole) \n";
        std::cout << std::left << std::setw(15) << "Vardas" 
                  << std::setw(25) << "Pavarde"
                  << std::setw(18) << "Galutinis (Vid.)"
                  << std::setw(18) << "Galutinis (Med.)" << '\n';
        std::cout << std::string(76, '-') << '\n';
        for (const auto& s : S) {
            std::cout << s;
        }

        std::ofstream out("test_output.txt");
        REQUIRE(out.is_open());
        out << std::left << std::setw(15) << "Vardas"
            << std::setw(25) << "Pavarde"
            << std::setw(18) << "Galutinis (Vid.)"
            << std::setw(18) << "Galutinis (Med.)" << '\n';
        out << std::string(76, '-') << '\n';
        for (const auto& s : S) {
            out << s;
        }
        out.close();
        
        std::ifstream checkFile("test_output.txt");
        CHECK(checkFile.good());
    }

    SUBCASE("Input Operator and Comparison Logic") {
        std::vector<Studentas> S2;
        std::ifstream in("test_10.txt");
        if (!in) {
            FAIL("Klaida! Nepavyko atidaryti test_10.txt");
        }

        std::string header;
        std::string eilute;
        std::getline(in, header);
        while(std::getline(in, eilute)) {
            if(eilute.empty()) continue;
            std::istringstream ss(eilute);
            Studentas tmp;
            ss >> tmp;
            S2.push_back(tmp);
        }
        in.close();

        skaiciavimai(S2);
        rusiavimas(S2, 1, 1);

        // Move Semantics Test using a temporary copy
        if (!S2.empty()) {
            Studentas tempCopy = S2[0]; 
            std::string nameBefore = tempCopy.getVardas();
            
            Studentas movedTo(std::move(tempCopy)); 
            
            CHECK(movedTo.getVardas() == nameBefore);
            CHECK(tempCopy.getVardas() == ""); 
            CHECK(tempCopy.getNdRez().empty());
        }

        // Original Comparison Logic
        bool sutampa = (S.size() == S2.size());
        if (sutampa) {
            for (size_t i = 0; i < S.size(); i++) {
                if (S[i].getVardas() != S2[i].getVardas() ||
                    S[i].getPavarde() != S2[i].getPavarde() || 
                    S[i].getEgzRez() != S2[i].getEgzRez()) {
                    sutampa = false;
                    break;
                }
                
                auto nd1 = S[i].getNdRez();
                auto nd2 = S2[i].getNdRez();
                if(nd1.size() != nd2.size()) {
                    sutampa = false;
                    break;
                }
                
                for(size_t j = 0; j < nd1.size(); j++){
                    if(nd1[j] != nd2[j]){
                        sutampa = false;
                        break;
                    }
                }
                if(!sutampa) break;
            }
        }
        
        CHECK(sutampa == true);
    }
}