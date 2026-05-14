#include "doctest.h"
#include "funkcijos.h"

TEST_CASE("Studentas: Copy and Move Semantics") {
    // 1. SETUP: This code runs fresh for EVERY subcase below
    std::vector<Studentas> S;
    nuskaitymas(S, 10);
    skaiciavimai(S);

    // Ensure we actually loaded enough students before running tests
    // REQUIRE stops the test immediately if it fails, preventing crashes.
    REQUIRE(S.size() >= 4); 

    SUBCASE("Copy Constructor") {
        Studentas s1(S[0]);
        
        // Assert that the copy matches the original
        CHECK(s1.getVardas() == S[0].getVardas());
        CHECK(s1.getGalutinisVid() == doctest::Approx(S[0].getGalutinisVid())); 
    }

    SUBCASE("Copy Assignment") {
        Studentas s2;
        s2 = S[1];
        
        CHECK(s2.getVardas() == S[1].getVardas());
        CHECK(s2.getGalutinisVid() == doctest::Approx(S[1].getGalutinisVid()));
    }

    SUBCASE("Move Constructor") {
        // Save the original values BEFORE moving so we can verify them later
        std::string expectedVardas = S[2].getVardas();
        double expectedVid = S[2].getGalutinisVid();

        Studentas s3(std::move(S[2]));
        
        // Assert the new object got the data
        CHECK(s3.getVardas() == expectedVardas);
        CHECK(s3.getGalutinisVid() == doctest::Approx(expectedVid));
        
        // Assert the old object was successfully hollowed out
        CHECK(S[2].getVardas() == ""); 
    }

    SUBCASE("Move Assignment") {
        // Save the original values
        std::string expectedVardas = S[3].getVardas();
        double expectedVid = S[3].getGalutinisVid();

        Studentas s4;
        s4 = std::move(S[3]);
        
        CHECK(s4.getVardas() == expectedVardas);
        CHECK(s4.getGalutinisVid() == doctest::Approx(expectedVid));
        
        CHECK(S[3].getVardas() == ""); 
    }
}