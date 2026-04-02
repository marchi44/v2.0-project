## 📦 Releases
### 📌 v1.1
- Removed `std::list` and `std::deque` versions
- Switched from structures to classes
- Minor code optimisations

## 📊 Tyrimų rezultatai
### 💻 Testavimo sistema
- OS: WSL (Ubuntu)
- CPU: AMD Ryzen 5 8645HS
- RAM: 16 GB
- Disk: 512 GB NVMe SSD

### Tyrimas 1
Palyginimas programos spartos su struktūromis ir klasėmis

| Tipas | Struct (100k entries) | Struct (1mil entries) | Class (100k entries) | Class (1mil entries) |
|-------|-----------------------|-----------------------|----------------------|----------------------|
| 1.    | 0.1430 s              | 1.4835 s              | 0.1823 s             | 1.6224 s             |
| 2.    | 0.1614 s              | 1.4305 s              | 0.1766 s             | 1.7295 s             |
| 3.    | 0.1491 s              | 1.3892 s              | 0.1889 s             | 1.5770 s             |
| Avg   | 0.1512 s              | 1.4344 s              | 0.1826 s             | 1.6429 s             |

- Struct ir Class našumas yra praktiškai lygiavertis
- Class rekomenduojama dėl kodo struktūros
### Tyrimas 2
- Tyrimui naudotas 1 000 000 įrašų failas
Failų dydžiai:
- -01 -> 130 KB
- -O2 -> 136 KB
- -O3 -> 138 KB

Laikai:
| Flag | -O1      | -O2      | -O3      |
|------|----------|----------|----------|
| 1.   | 1.6027 s | 1.6642 s | 1.5093 s |
| 2.   | 1.5855 s | 1.6890 s | 1.4715 s |
| 3.   | 1.5214 s | 1.6133 s | 1.5829 s |
| Avg. | 1.5699 s | 1.6555 s | 1.5212 s |

Išvados:
- -O1 geriausias, jei tikslas optimizuoti failų dydį
- -O3 geriausias, jei tikslas optimizuoti programos spartą

## 🚀 Naudojimosi instrukcija

### ⚙️ CMake ir C++ kompiliatoriaus įdiegimas
#### Linux
1. Atsidarykite Terminal
2. Susiraskite jūsų naudojamą Linux OS ir įrašykite pateiktas komandas
- 🐌 Ubuntu / Debian
```
sudo apt update
sudo apt install cmake g++ make
```
- 🎩 Fedora
```
sudo dnf install cmake gcc-c++ make
```
- 🐉 Arch Linux
```
sudo pacman -S cmake gcc make
```
3. Patikrinkite ar atsisiuntė
```
cmake --version
g++ --version
make --version
```
#### 🪟 Windows

1. Įdiekite MSYS2

Atsisiųsitek ir įdiekite MSYS2 iš oficialaus puslapio.
https://www.msys2.org/

2. Atnaujinkite MSYS2

MSYS2 terminale paleisk:
```
pacman -Syu
```
3. Įdiekite GCC/G++ ir CMake

Rekomenduojama naudoti mingw64 aplinką:
```
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake make
```
Patikrinimui:
```
g++ --version
cmake --version
make --version
```
#### 🍎 macOS

1. Įdiek Command Line Tools

Terminale paleisk:
```
xcode-select --install
```
Po įdiegimo patikrinimui:
```
clang++ --version
make --version
```
2. Įdiek CMake
 - Atsisiųsti HomeBrew (jei dar neturite)
 ```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
brew install cmake
 ```
 - Patikrinimui:
 ```
   cmake --version
```
### 🔧 Programos paleidimas
- Linux ir macOS naudokite Terminal, Windows aplinkoje MSYS2 MinGW-64
1. Nuklonuokite projektą:
```
git clone -b v1.1 https://github.com/marchi44/v2.0-project.git
cd v2.0-project
```
2. Susikurkite build aplanką ir sukompiliuokite projektą:
```
mkdir build
cd build
cmake ..
cmake --build .
```
3. Paleiskite programą:
   - `./v1.0_vector` (Windows aplinkoje naudokite `./v1.0_vector.exe`)

### 📥 Duomenų įvedimas

Programa palaiko kelis darbo režimus:

1. Rankinis įvedimas
Vartotojas įveda:
- vardą ir pavardę
- namų darbų pažymius
- egzamino pažymį
2. Atsitiktinis duomenų generavimas
- Vartotojas gali pasirinkti automatinį pažymių generavimą
- Pažymiai generuojami intervale [1–10]
3. Duomenų nuskaitymas iš failo
- Programa nuskaito duomenis iš failo (pvz. kursiokai.txt)
- Failo struktūra:
`Vardas Pavarde ND1 ND2 ND3 ... Egzaminas`

### 📊 Duomenų apdorojimas

Programa atlieka šiuos veiksmus:

- apskaičiuoja galutinį balą:
- pagal vidurkį arba medianą
- surūšiuoja studentus pagal:
   1. vardą
   2. pavardę
   3. galutinį balą
- padalina studentus į grupes:
   1. „dundukai“ (balas < 5.0)
   2. „galvociai“ (balas ≥ 5.0)

### 📤 Rezultatų išvedimas

Rezultatai gali būti:

- atvaizduojami ekrane
- išvedami į failus
