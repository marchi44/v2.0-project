📦 Releases
📌 v.pradinė

Pradinė programos versija.
Realizuotas studento duomenų įvedimas, galutinio balo skaičiavimas pagal vidurkį ir medianą bei rezultatų išvedimas formatuotu pavidalu.

📌 v0.1

Programa išplėsta darbui su nežinomu studentų ir namų darbų kiekiu įvedimo metu.
Įgyvendintos dvi realizacijos: naudojant C masyvus ir std::vector. Taip pat pridėta galimybė generuoti pažymius atsitiktinai.

📌 v0.2

Pridėtas duomenų nuskaitymas iš failo (naudojant std::vector).
Realizuotas studentų rūšiavimas pagal vartotojo pasirinktą kriterijų (vardą, pavardę arba galutinį balą pagal vidurkį / medianą). Užtikrintas tvarkingas ir išlygintas rezultatų išvedimas. Programa ištestuota su dideliais duomenų failais.

📌 v0.3

Atliktas programos kodo reorganizavimas (refactoring).
Įdiegta struktūrizuota projekto architektūra, išskaidant kodą į kelis .cpp ir .h failus. Taip pat pridėtas išimčių (exception handling) valdymas patikimesniam veikimui.

📌 v0.4

Sukurta failų generavimo funkcija ir sugeneruoti dideli testiniai duomenų rinkiniai.
Įgyvendintas studentų skirstymas į dvi kategorijas pagal galutinį balą bei rezultatų išvedimas į atskirus failus. Atlikta programos veikimo spartos analizė, matuojant skirtingus duomenų apdorojimo etapus.

📌 v1.0

Galutinė programos versija.
Atlikta konteinerių (std::vector, std::list, std::deque) veikimo spartos analizė bei jų palyginimas. Optimizuotas studentų skirstymo algoritmas, pritaikant skirtingas strategijas ir STL algoritmus. Pateikti testavimo rezultatai ir išvados README faile.

📊 Tyrimų rezultatai
💻 Testavimo sistema
 OS: WSL (Ubuntu)
 CPU: AMD Ryzen 5 8645HS
 RAM: 16 GB
 Diskas: 512 GB NVMe SSD
⚙️ Tyrimas 3 – konteinerių palyginimas
📈 Vidutiniai rezultatai (Laikai pateikti apskaičiavus vidurkį iš 3 bandymų)
Įrašų kiekis	Vector (s)	Deque (s)	List (s)
1 000	       0.121	     2.351	    1.570
10 000	      0.056	     0.055	    0.145
100 000	     0.588	     0.593	    0.342
1 000 000	   6.859	     7.150	    3.928
10 000 000	  88.528	    81.256	   51.761
🧠 Išvados
Mažiems duomenų kiekiams std::vector yra greičiausias
Dideliems duomenų kiekiams std::list pasirodė greičiausias šiame teste

⚙️ Tyrimas 4 – skirstymo strategijos
Testuota su 100 000 įrašų

📈 Strategija 1 (kopijavimas į 2 konteinerius)
Konteineris	Laikas 1 (s)	Laikas 2 (s)	Laikas 3 (s)	Vidurkis (s)
Vector	     0.0285	      0.0284	      0.0274	      0.0281
Deque	      0.0196	      0.0218	      0.0204	      0.0206
List	       0.0278	      0.0292	      0.0293	      0.0288

📈 Strategija 2 (trinant iš pagrindinio)
Konteineris	Laikas 1 (s)	Laikas 2 (s)	Laikas 3 (s)	Vidurkis (s)
Vector	     21.1763	     21.9315	     21.6982	     21.6020 ❗
Deque	      0.0035	      0.0043	      0.0034	      0.0037
List	       0.0068	      0.0115	      0.0058	      0.0080

📈 Strategija 3 (optimizuota – std::stable_partition)
Konteineris	Laikas 1 (s)	Laikas 2 (s)	Laikas 3 (s)	Vidurkis (s)
Vector	     0.0157	      0.0137      	0.0168	      0.0154
Deque	      0.0046	      0.0049	      0.0052	      0.0049
List	       0.0278	      0.0247	      0.0272	      0.0266

🧠 Galutinės išvados
Vector su 2 strategija pasirodė prasčiausiai, nes kopijavimas std::vector yra labai brangus
Strategija 3 yra optimaliausia visais atvejais

👉 Geriausias pasirinkimas:
konteineris: std::deque
strategija: 3 (stable_partition pagrindu)

🚀 Naudojimosi instrukcija

⚙️ CMake ir C++ kompiliatoriaus įdiegimas
Linux
1. Atsidarykite Terminal
2. Susiraskite jūsų naudojamą Linux OS ir įrašykite pateiktas komandas
🐌 Ubuntu / Debian

sudo apt update
sudo apt install cmake g++ make

🎩 Fedora
sudo dnf install cmake gcc-c++ make

🐉 Arch Linux
sudo pacman -S cmake gcc make

3. Patikrinkite ar atsisiuntė
cmake --version
g++ --version
make --version

🪟 Windows

1. Įdiek MSYS2

Atsisiųsk ir įdiek MSYS2 iš oficialaus puslapio.
https://www.msys2.org/

2. Atnaujink MSYS2

MSYS2 terminale paleisk:

pacman -Syu

Jei paprašys uždaryti langą, atidaryk jį iš naujo ir pakartok:

pacman -Su
3. Įdiek GCC/G++ ir CMake

Rekomenduojama naudoti mingw64 aplinką:

pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake make

Patikrinimui:

g++ --version
cmake --version
make --version

🍎 macOS

1. Įdiek Command Line Tools

Terminale paleisk:

xcode-select --install

Po įdiegimo patikrinimui:

clang++ --version
make --version
2. Įdiek CMake
 - Atsisiųsti HomeBrew (jei dar neturite)
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
 - brew install cmake
 - Patikrinimui:
   cmake --version

🔧 Programos paleidimas
- Linux ir macOS naudokite Terminal, Windows aplinkoje MSYS2 MinGW-64
1. Nuklonuokite projektą:
   git clone -b v1.0 https://github.com/marchi44/vu-cpp.git
   cd vu-cpp
2. Susikurkite build aplanką ir sukompiliuokite projektą:
   mkdir build
   cd build
   cmake ..
   cmake --build .
3. Paleiskite programą:
   - ./v1.0_vector (paleidžia programą su std::vector konteineriu, Windows aplinkoje naudokite ./v1.0_vector.exe)
   - ./v1.0_deque (paleidžia programą su std::deque konteineriu, Windows aplinkoje naudokite ./v1.0_deque.exe)
   - ./v1.0_list (paleidžia programą su std::list konteineriu, Windows aplinkoje naudokite ./v1.0_list.exe)

📥 Duomenų įvedimas

Programa palaiko kelis darbo režimus:

1. Rankinis įvedimas
Vartotojas įveda:
vardą ir pavardę
namų darbų pažymius
egzamino pažymį
Pasirenkamas galutinio balo skaičiavimo būdas:
vidurkis
mediana
2. Atsitiktinis duomenų generavimas
Vartotojas gali pasirinkti automatinį pažymių generavimą
Pažymiai generuojami intervale [1–10]
3. Duomenų nuskaitymas iš failo
Programa nuskaito duomenis iš failo (pvz. kursiokai.txt)
Failo struktūra:
Vardas Pavarde ND1 ND2 ND3 ... Egzaminas
📊 Duomenų apdorojimas

Programa atlieka šiuos veiksmus:

apskaičiuoja galutinį balą:
pagal vidurkį arba medianą
surūšiuoja studentus pagal:
vardą
pavardę
galutinį balą
padalina studentus į grupes:
„dundukai“ (balas < 5.0)
„galvociai“ (balas ≥ 5.0)
📤 Rezultatų išvedimas

Rezultatai gali būti:

atvaizduojami ekrane
išvedami į failus:
dundukai.txt
galvociai.txt
