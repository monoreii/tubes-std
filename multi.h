#ifndef MULTI_H_INCLUDED
#define MULTI_H_INCLUDED
#include <iostream>

#define firstDosen(p) (p).firstDosen
#define nextDosen(p) (p)->nextDosen
#define infoDosen(p) (p)->infoDosen

#define firstMhs(p) (p).firstMhs
#define nextMhs(p) (p)->nextMhs
#define infoMhs(p) (p)->infoMhs

#define firstRelasi(p) (p).firstRelasi
#define nextRelasi(p) (p)->nextRelasi

using namespace std;

struct infotype_dosen{
    string nama_dosen;
    string kepakaran;
    int juml_bimbingan;
};
typedef struct elm_dosen *adr_dosen;
typedef struct elm_mhs *adr_mhs;
typedef struct elm_relasi *adr_relasi;

struct list_dosen{
    adr_dosen firstDosen;
};

struct list_mhs{
    adr_mhs firstMhs;
};
struct list_relasi{
    adr_relasi firstRelasi;
};

struct relasi{
    adr_relasi firstRelasi;
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
struct elm_relasi{
    adr_mhs nextMhs;
    adr_dosen nextDosen;
    adr_relasi nextRelasi;
};


//function & proc
void createlistDosen(list_dosen &d);
void createlistMhs(list_mhs &m);
adr_dosen createElmDosen(infotype_dosen dosen);
adr_mhs createElmMhs(infotype_mahasiswa mahasiswa);

    // createList relasi
void createListRelasi(list_relasi &r);
adr_relasi createElmRelasi(list_relasi r);

    // insertFirst SLL
void insertDosen(list_dosen &d, adr_dosen p);
void insertMhs(list_mhs &m, adr_mhs p);

    // Fungsi Pencarian
adr_dosen searchDosen(list_dosen &d, infotype_dosen dosen);
adr_mhs searchMhs(list_mhs m, infotype_mahasiswa mhs);

    //delete first SLL
void deleteDosen(list_dosen &d, infotype_dosen dosen, list_relasi &r);
void deleteMhs(list_mhs &m, infotype_mahasiswa mhs, list_relasi &r);

    //menghapus relasi
void deleteRelasi(list_relasi &r, adr_relasi p);

void showAll(list_dosen d, list_mhs m);
void showDosen(list_dosen d);

    //update
void updateBimbingan(list_dosen &d, infotype_dosen dosen);
adr_dosen searchDosenUpdate(list_dosen d, infotype_dosen);

    //kuota
void kuota(list_dosen kuotaDosen);
    // TA
int TA(list_dosen dosen);

int menu();
#endif // MULTI_H_INCLUDED
