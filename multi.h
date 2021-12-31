#ifndef MULTI_H_INCLUDED
#define MULTI_H_INCLUDED
#include <iostream>

using namespace std;

struct infotype_dosen{
    string nama_dosen;
    string kepakaran;
    int juml_bimbingan;
};
typedef struct elm_dosen *adr_dosen;
typedef struct elm_mhs *adr_mhs;

struct list_dosen{
    adr_dosen firstDosen;
};

struct list_mhs{
    adr_mhs firstMhs;
};

struct elm_dosen{
    infotype_dosen infoDosen;
    adr_dosen nextDosen;
    list_mhs mahasiswa;
};

struct infotype_mahasiswa{
    string nama_mhs;
    string NIM;
    string topikTA;
    int SKS_Lulus;
};

struct elm_mhs{
    infotype_mahasiswa infoMhs;
    adr_mhs nextMhs;
};

//connector
struct connector{
    adr_mhs next;
    adr_mhs mahasiswa;
};




#endif // MULTI_H_INCLUDED
