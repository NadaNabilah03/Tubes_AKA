#include "cari ruang.h"

void inputKelas(listKelas &LK){
    adrKelas K;
    dataKelas IK;

    IK.nama = 4701;
    K = createElementKelas(IK);
    insertLastKelas(LK, K);

    IK.nama = 4702;
    K = createElementKelas(IK);
    insertLastKelas(LK, K);

    IK.nama = 4703;
    K = createElementKelas(IK);
    insertLastKelas(LK, K);

    IK.nama = 4704;
    K = createElementKelas(IK);
    insertLastKelas(LK, K);

    IK.nama = 4705;
    K = createElementKelas(IK);
    insertLastKelas(LK, K);

    IK.nama = 4706;
    K = createElementKelas(IK);
    insertLastKelas(LK, K);

    IK.nama = 4707;
    K = createElementKelas(IK);
    insertLastKelas(LK, K);
}
