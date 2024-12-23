#include "cari ruang.h"

void createListKelas(listKelas &LK){
    firstKelas(LK) = NULL;
    lastKelas(LK) = NULL;
}


adrKelas createElementKelas(dataKelas X){
    adrKelas K = new kelas;
    infoKelas(K) = X;
    nextKelas(K) = NULL;
    prevKelas(K) = NULL;
    return K;
}

adrHari createElementHari(dataHari X){
    adrHari H = new Hari;
    infoHari(H) = X;
    nextHari(H) = NULL;
    return H;
}


void insertLastKelas(listKelas &LK, adrKelas K){
    if(firstKelas(LK) == NULL){
        firstKelas(LK) = K;
        lastKelas(LK) = K;
    }else{
        adrKelas last = lastKelas(LK);
        nextKelas(last) = K;
        prevKelas(K) = last;
        lastKelas(LK) = K;
    }
    insertHari(LK, K, "Senin");
    insertHari(LK, K, "Selasa");
    insertHari(LK, K, "Rabu");
    insertHari(LK, K, "Kamis");
    insertHari(LK, K, "Jumat");
    insertHari(LK, K, "Sabtu");
    insertHari(LK, K, "Minggu");
}

void showKelas(listKelas LK){
    adrKelas K = firstKelas(LK);
    while (K != NULL){
        cout << infoKelas(K).nama << endl;
        K = nextKelas(K);
    }
}

void insertHari(listKelas &LK, adrKelas K, string hari){
    dataHari IH;
    IH.hari = hari;
    adrHari H = createElementHari(IH);

    if (firstHari(K) == NULL){
        firstHari(K) = H;
    }else{
        adrHari temp = firstHari(K);
        while (nextHari(temp) != NULL){
            temp = nextHari(temp);
        }
        nextHari(temp) = H;
    }
}


adrHari findHari(adrKelas K, string namaHari){
    adrHari H = firstHari(K);
    while (H != NULL){
        if (namaHari == infoHari(H).hari){
            return H;
        }
        H = nextHari(H);
    }
    return NULL;
}

void cekSediaKelas(listKelas LK, int namaKelas, string namaHari, int jamAwal, int jamAkhir){
    adrKelas K = findKelasBinary(LK, namaKelas);
    adrHari H = findHari(K, namaHari);
    int i;
    int penuh = 0;
    for (i = jamAwal;i <= jamAkhir; i++){
        if (infoHari(H).jam[i] == true){
            penuh = i;
            break;
        }
    }
    if (penuh == 0){
        cout << "Kelas " << namaKelas << " tersedia di hari dan jam tersebut" << endl;
    }else{
        cout << "Kelas " << namaKelas << " tidak tersedia mulai dari jam " << penuh << endl;
    }
}

adrHari findHariRekursif(adrHari H, string namaHari){
    if (H == NULL){
        return NULL;
    }else{
        if (namaHari == infoHari(H).hari){
            return H;
        }else{
            return findHariRekursif(nextHari(H), namaHari);
        }
    }
    return NULL;
}

void cekSediaKelasRekursif(listKelas LK, int namaKelas, string namaHari, int jamAwal, int jamAkhir) {
    adrKelas K = firstKelas(LK);
    K = findKelasBinaryRekursif(firstKelas(LK), lastKelas(LK), namaKelas);
    adrHari H = firstHari(K);
    H = findHariRekursif(H, namaHari);

    if (jamAwal > jamAkhir) {
        cout << "Kelas " << namaKelas << " tersedia di hari dan jam tersebut." << endl;
    }else if (infoHari(H).jam[jamAwal] == true) {
        cout << "Kelas " << namaKelas << " tidak tersedia mulai dari jam " << jamAwal << endl;
    }else {
        cekSediaKelas(LK, namaKelas, namaHari, jamAwal + 1, jamAkhir);
    }
}

adrKelas findKelasBinary(listKelas LK, int namaKelas){
    adrKelas left = firstKelas(LK);
    adrKelas right = lastKelas(LK);

    while (left != NULL && right != NULL && left != nextKelas(right)) {
        adrKelas mid = left;
        adrKelas temp = left;
        int count = 0;

        while (temp != nextKelas(right)) {
            count++;
            temp = nextKelas(temp);
        }


        for (int i = 0; i < count / 2; i++) {
            mid = nextKelas(mid);
        }

        if (infoKelas(mid).nama == namaKelas) {
            return mid;
        } else if (infoKelas(mid).nama < namaKelas) {
            left = nextKelas(mid);
        } else {
            right = prevKelas(mid);
        }
    }
    return NULL;
}

adrKelas findKelasBinaryRekursif(adrKelas left, adrKelas right, int namaKelas) {
    adrKelas mid = left;
    adrKelas temp = left;
    int count = 0;

    if (left == NULL || right == NULL || left == nextKelas(right) || right == nextKelas(left)) {
        return NULL;
    }

    while (temp != nextKelas(right)) {
        count++;
        temp = nextKelas(temp);
    }

    for (int i = 0; i < count / 2; i++) {
        if (mid == NULL) {
            return NULL;
        }
        mid = nextKelas(mid);
    }

    if (infoKelas(mid).nama == namaKelas) {
        return mid;
    }
    else if (infoKelas(mid).nama < namaKelas) {
        return findKelasBinaryRekursif(nextKelas(mid), right, namaKelas);
    }
    else {
        return findKelasBinaryRekursif(left, prevKelas(mid), namaKelas);
    }
}
