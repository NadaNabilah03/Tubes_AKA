#include <iostream>
#include "cari ruang.h"

using namespace std;

int main()
{
    adrKelas K;
    listKelas LK;
    dataKelas IK;
    createListKelas(LK);
    inputKelas(LK);

    K = firstKelas(LK);
    adrHari H = firstHari(K);
    int kelas;
    string hari;
    int jamAwal;
    int jamAkhir;
/*
    int i;
    for (i = 3; i <= 5;i++){
        infoHari(H).jam[i] = true;
    }

    cout << "Masukkan Kelas yang anda cari jadwalnya: ";
    cin >> kelas;
    cout << "Di hari apa? ";
    cin >> hari;
    cout << "Dari jam berapa? ";
    cin >> jamAwal;
    cout << "Sampai jam berapa? ";
    cin >> jamAkhir;

    cekSediaKelasRekursif(LK, kelas, hari, jamAwal, jamAkhir);*/



    string input;
    showKelas(LK);
    cout << "cari kelas 4705:" << endl;
    K = findKelasBinary(LK, 4705);
    cout << infoKelas(K).nama << endl;

    cout << "cari kelas 4705 rekursif:" << endl;
    K = firstKelas(LK);
    K = findKelasBinaryRekursif(firstKelas(LK), lastKelas(LK), 4705);
    cout << infoKelas(K).nama << endl;

    cout << "cari Hari Senin:" << endl;
    H = findHari(K, "Senin");
    cout << infoHari(H).hari << endl;

    cout << "cari Hari Senin Rekursif:" << endl;
    H = findHariRekursif(H, "Senin");
    cout << infoHari(H).hari << endl;

    return 0;
}
