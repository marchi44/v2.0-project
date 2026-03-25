Tyrimas 1 - Duomenų failo generavimas
<img width="868" height="292" alt="image" src="https://github.com/user-attachments/assets/2025384c-51a9-40ae-b507-d965dc28bb4c" />

<img width="929" height="287" alt="image" src="https://github.com/user-attachments/assets/a195deff-be3e-4f1b-a8b5-7048bd0fd703" />

<img width="863" height="290" alt="image" src="https://github.com/user-attachments/assets/eeed41a1-4cd3-41e0-8b8a-195475465c51" />

<img width="528" height="178" alt="image" src="https://github.com/user-attachments/assets/74213d40-be62-4aa8-b9c5-de02b81248a7" />


Tyrimas 2
Failas su 1000 įrašų
<img width="1023" height="162" alt="image" src="https://github.com/user-attachments/assets/62a0ce43-91f7-429f-a85a-6d4f456c77dd" />

<img width="991" height="164" alt="image" src="https://github.com/user-attachments/assets/fd1881b9-dcc4-4587-a464-3adb476146bb" />

<img width="975" height="155" alt="image" src="https://github.com/user-attachments/assets/13af7b39-e378-44d3-b287-9b1175da9420" />


Failas su 10000 įrašų
<img width="1051" height="177" alt="image" src="https://github.com/user-attachments/assets/213b2410-6d4f-490c-b626-2ef8e956527e" />

<img width="1015" height="173" alt="image" src="https://github.com/user-attachments/assets/0c3af6e4-3008-42eb-9cba-e3f607a2ca6b" />

<img width="1001" height="151" alt="image" src="https://github.com/user-attachments/assets/0873c936-a8ab-43d6-b68f-c750b84275d0" />



Failas su 100000 įrašų
<img width="1023" height="169" alt="image" src="https://github.com/user-attachments/assets/07b1ab55-2899-4eb1-ab10-44cab06a106c" />

<img width="1032" height="155" alt="image" src="https://github.com/user-attachments/assets/17d94ceb-1fc8-4662-a27a-97f332dcc275" />

<img width="1023" height="155" alt="image" src="https://github.com/user-attachments/assets/2441c132-0550-44d2-bc4f-5258a07a1eb3" />



Failas su 1000000 įrašų
<img width="1066" height="173" alt="image" src="https://github.com/user-attachments/assets/59fe7c93-b8a4-4943-8262-e93aade837f2" />

<img width="1024" height="154" alt="image" src="https://github.com/user-attachments/assets/36dcfc6b-02d1-45be-903d-4db33ed71ba2" />

<img width="1034" height="152" alt="image" src="https://github.com/user-attachments/assets/15763f8c-68e0-4a5b-98ee-48a3ca922c11" />



Failas su 10000000 įrašų

<img width="1086" height="178" alt="image" src="https://github.com/user-attachments/assets/c24d75ef-0748-4c8c-955c-9a3f9c025060" />

<img width="1057" height="156" alt="image" src="https://github.com/user-attachments/assets/353930c9-60c5-415f-a41d-90540658cfb4" />

<img width="1050" height="156" alt="image" src="https://github.com/user-attachments/assets/9372c8f9-9ba9-4a91-b53d-bc0bc112736f" />


<img width="604" height="496" alt="image" src="https://github.com/user-attachments/assets/dd865a60-ad05-467b-ad34-75e8bf411df4" />

Tyrimas 3
Sistemos informacija:
WSL:Ubuntu
CPU - AMD Ryzen 5 8645HS
RAM - 16GB
SSD - 512GB NVME PCIe 4.0

 std::vector
 test_1000.txt
 1 - 0.113893 s
 2 - 0.110467 s
 3 - 0.140469 s
 Vidurkis - 0.121 s

 test_10000.txt
 1 - 0.053908 s
 2 - 0.053852 s
 3 - 0.058564 s
 Vidurkis - 0.056 s

 test_100000.txt
 1 - 0.579506 s
 2 - 0.590213 s
 3 - 0.595172 s
 Vidurkis - 0.588 s

 test_1000000.txt
 1 - 6.569682 s
 2 - 6.967758 s
 3 - 7.039329 s
 Vidurkis - 6.859 s

 test_10000000.txt
 1 - 91.776730 s
 2 - 87.465872 s
 3 - 86.342231 s
 Vidurkis - 88.528 s

std::deque
 test_1000.txt
 1 - 2.127309 s
 2 - 2.771223 s
 3 - 2.155803 s
 Vidurkis - 2.351445 s

 test_10000.txt
 1 - 0.050624 s
 2 - 0.065636 s
 3 - 0.048987 s
 Vidurkis - 0.055082 s

 test_100000.txt
 1 - 0.604149 s
 2 - 0.633011 s
 3 - 0.542207 s
 Vidurkis - 0.593122 s

 test_1000000.txt
 1 - 8.604124 s
 2 - 6.549174 s
 3 - 6.297341 s
 Vidurkis - 7.150213 s

 test_10000000.txt
 1 - 83.687118 s
 2 - 83.985311 s
 3 - 76.094143 s
 Vidurkis - 81.255524 s

 std::list
 test_1000.txt
 1 - 1.680508 s
 2 - 1.561571 s
 3 - 1.467715 s
 Vidurkis - 1.569931 s

 test_10000.txt
 1 - 0.150532 s
 2 - 0.142958 s
 3 - 0.140435 s
 Vidurkis - 0.144642 s

 test_100000.txt
 1 - 0.322517 s
 2 - 0.362596 s
 3 - 0.339868 s
 Vidurkis - 0.341660 s

 test_1000000.txt
 1 - 3.898043 s
 2 - 3.985849 s
 3 - 3.898897 s
 Vidurkis - 3.927596 s

 test_10000000.txt
 1 - 57.251327 s
 2 - 51.093084 s
 3 - 46.938994 s
 Vidurkis - 51.761135 s



