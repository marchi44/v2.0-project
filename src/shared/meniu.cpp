#include "funkcijos.h"
#include "lib.h"

/**
 * @brief Displays the main menu and returns the user's validated choice.
 *
 * Prints the five available options and loops until the user enters a
 * valid integer in the range [1, 5]. Invalid input (non-integer or
 * out-of-range) clears the stream and prompts again.
 *
 * Menu options:
 *   - 1: Enter all data manually.
 *   - 2: Enter student names manually or from file, generate grades randomly.
 *   - 3: Generate all student data (names + grades) randomly.
 *   - 4: Generate a data file.
 *   - 5: Exit the program.
 *
 * @return The chosen menu option as an integer in [1, 5].
 */
int meniu() {
    int meniu_pasirinkimas;
    std::cout << "1 - viska ivesti ranka\n"
              << "2 - generuoti tik pazymius\n"
              << "3 - generuoti studentu vardus, pavardes ir pazymius\n"
              << "4 - generuoti duomenu faila\n"
              << "5 - baigti darba.\n";
    while (true) {
        std::cin >> meniu_pasirinkimas;
        if (std::cin.fail() || (meniu_pasirinkimas < 1 || meniu_pasirinkimas > 5)) {
            std::cout << "Klaida! Iveskite sveika skaiciu (1-5)...\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        std::cin.ignore(10000, '\n');
        return meniu_pasirinkimas;
    }
}
