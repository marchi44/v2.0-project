COMMON = ar_valid.cpp egz_paz_ivedimas.cpp med_ar_vid.cpp random_vardas.cpp random_pavarde.cpp paz_sk_ivedimas.cpp meniu.cpp mok_sk_ivedimas.cpp
ARR = pasirinkimas1_arr.cpp pasirinkimas2_arr.cpp pasirinkimas3_arr.cpp main_array.cpp
VEC = pasirinkimas2_vec.cpp pasirinkimas3_vec.cpp main_vector.cpp isvedimas.cpp mokinio_info.cpp nd_paz_ivedimas.cpp vidurkis.cpp

arr:
	g++ $(COMMON) $(ARR) -o main_array.exe
vec:
	g++ $(COMMON) $(VEC) -o main_vector.exe