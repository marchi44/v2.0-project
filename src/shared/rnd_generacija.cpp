#include "funkcijos.h"
#include "lib.h"

/**
 * @brief Returns a random Lithuanian first name based on gender.
 *
 * Picks uniformly at random from a list of 25 male or 25 female names.
 * Uses `rand()` — call `srand()` beforehand for different sequences.
 *
 * @param vyras true for a male name, false for a female name.
 * @return A randomly selected first name as a string.
 */
std::string rnd_vardas(bool vyras) {
    vector<string> vyr_vardai = {
        "Jonas","Matas","Lukas","Tomas","Paulius",
        "Nojus","Domantas","Karolis","Rokas","Ignas",
        "Dovydas","Emilis","Arnas","Austejus","Danielius",
        "Edvinas","Gytis","Jokubas","Justas","Laurynas",
        "Martynas","Mykolas","Pijus","Simonas","Tadas"
    };
    vector<string> mot_vardai = {
        "Austeja","Gabija","Emilija","Ugne","Ieva",
        "Gabriele","Liepa","Smilte","Egle","Agne",
        "Kamile","Patricija","Monika","Karolina","Ruta",
        "Simona","Juste","Gintare","Indre","Aiste",
        "Viktorija","Greta","Laura","Milda","Marija"
    };
    if (vyras) return vyr_vardai[rand() % vyr_vardai.size()];
    else       return mot_vardai[rand() % mot_vardai.size()];
}

/**
 * @brief Returns a random Lithuanian surname based on gender.
 *
 * Picks uniformly at random from a list of 10 male or 10 female surnames.
 * Female surnames are the grammatically correct feminine forms of the male surnames.
 *
 * @param vyras true for a male surname, false for a female surname.
 * @return A randomly selected surname as a string.
 */
std::string rnd_pavarde(bool vyras) {
    vector<string> vyr_pavarde = {
        "Kazlauskas","Petrauskas","Jankauskas","Stankevicius","Vasiliauskas",
        "Zukauskas","Paulauskas","Urbonas","Kavaliauskas","Navickas"
    };
    vector<string> mot_pavarde = {
        "Kazlauskaite","Petrauskaite","Jankauskaite","Stankeviciute","Vasiliauskaite",
        "Zukauskaite","Paulauskaite","Urbonaite","Kavaliauskaite","Navickaite"
    };
    if (vyras) return vyr_pavarde[rand() % vyr_pavarde.size()];
    else       return mot_pavarde[rand() % mot_pavarde.size()];
}

/**
 * @brief Generates a student data file with random names, homework grades, and exam results.
 *
 * Interactively asks for:
 *   - A filename (must end in `.txt`).
 *   - The number of students to generate (must be a positive integer).
 *
 * For each student:
 *   - Gender is chosen at random (50/50).
 *   - Name and surname are generated with `rnd_vardas()` / `rnd_pavarde()`.
 *   - Between 1 and 5 homework grades are generated, each in [1, 10].
 *   - One exam result is generated in [1, 10].
 *
 * The output file has a fixed-width header row followed by one student per line:
 * @code
 *   Vardas          Pavarde                   ND1  ND2  ND3  ND4  ND5  Egzaminas
 * @endcode
 *
 * @throws std::runtime_error If the filename does not end in `.txt`, the student
 *                            count is not a positive integer, or the file cannot be created.
 */
void failo_generavimas() {
    cout << "Iveskite failo, i kuri norite generuoti duomenis, pavadinima (pvz., kursiokai.txt): ";
    string path;
    cin >> path;
    cin.ignore(10000, '\n');
    if (path.empty() || path.size() < 4 || path.substr(path.size() - 4) != ".txt") {
        cin.clear();
        throw std::runtime_error("Klaida! Failo pavadinimas turi baigtis .txt...\n");
    }
    std::ofstream out(path);

    cout << "Iveskite mokiniu skaiciu, kuri norite generuoti: ";
    int mok_sk;
    cin >> mok_sk;
    cin.ignore(10000, '\n');
    if (cin.fail() || mok_sk <= 0) {
        cin.clear();
        throw std::runtime_error("Klaida! Turite ivesti teigiama sveika skaiciu...\n");
        return;
    }

    // Write header
    out << std::left
        << std::setw(15) << "Vardas"
        << std::setw(25) << "Pavarde"
        << std::setw(5)  << "ND1"
        << std::setw(5)  << "ND2"
        << std::setw(5)  << "ND3"
        << std::setw(5)  << "ND4"
        << std::setw(5)  << "ND5"
        << std::setw(10) << "Egzaminas\n";

    for (int i = 0; i < mok_sk; i++) {
        bool lytis = rand() % 2;
        out << std::setw(15) << rnd_vardas(lytis)
            << std::setw(25) << rnd_pavarde(lytis) << " ";
        int paz_sk = rand() % 5 + 1;
        for (int j = 0; j < paz_sk; j++) {
            out << std::setw(5) << rand() % 10 + 1;
        }
        // Pad missing columns with spaces to keep the layout aligned
        if (paz_sk < 5) {
            for (int j = paz_sk; j < 5; j++) {
                out << std::setw(5) << " ";
            }
        }
        out << std::setw(10) << rand() % 10 + 1 << "\n";
    }
    out.close();
}
