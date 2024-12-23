#ifndef CARI_RUANG_H_INCLUDED
#define CARI_RUANG_H_INCLUDED

#include <iostream>

#define infoKelas(K) K->infoKelas
#define nextKelas(K) K->nextKelas
#define prevKelas(K) K->prevKelas
#define firstHari(K) K->firstHari
#define infoHari(H) H->infoHari
#define nextHari(H) H->nextHari
#define firstKelas(LK) LK.firstKelas
#define lastKelas(LK) LK.lastKelas


using namespace std;

typedef struct kelas *adrKelas;
typedef struct Hari *adrHari;

struct dataKelas{
    int nama;
};

struct kelas{
    dataKelas infoKelas;
    adrKelas nextKelas;
    adrKelas prevKelas;
    adrHari firstHari;
};

struct dataHari{
    string hari;
    bool jam[21] = {true};
};

struct Hari{
    dataHari infoHari;
    adrHari nextHari;
};

struct listKelas{
    adrKelas firstKelas;
    adrKelas lastKelas;
};


void createListKelas(listKelas &LK);
adrKelas createElementKelas(dataKelas X);
adrHari createElementHari(dataHari X);
void insertHari(listKelas &LK, adrKelas K, string hari);

void showKelas(listKelas LK);
void insertLastKelas(listKelas &LK, adrKelas K);
adrHari findHari(adrKelas K, string namaHari);
void cekSediaKelas(listKelas LK, int namaKelas, string namaHari, int jamAwal, int jamAkhir);

adrHari findHariRekursif(adrHari H, string namaHari);
void cekSediaKelasRekursif(listKelas LK, int namaKelas, string namaHari, int jamAwal, int jamAkhir);

adrKelas findKelasBinary(listKelas LK, int namaKelas);
adrKelas findKelasBinaryRekursif(adrKelas left, adrKelas right, int namaKelas);

void inputKelas(listKelas &LK);

#endif // CARI_RUANG_H_INCLUDED
