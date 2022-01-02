#include "multi.h"

//function & proc
void createlistDosen(list_dosen &d){
    firstDosen(d) = NULL;
}
void createlistMhs(list_mhs &m){
    firstMhs(m) = NULL;
}
adr_dosen createElmDosen(infotype_dosen dosen){
    adr_dosen p = new elm_dosen;
    infoDosen(p) = dosen;
    nextDosen(p) = NULL;
    return p;
}
adr_mhs createElmMhs(infotype_mahasiswa mahasiswa){
    adr_mhs p = new elm_mhs;
    infoMhs(p) = mahasiswa;
    nextMhs(p) = NULL;

    return p;
}

    // createList relasi
void createListRelasi(list_relasi &r){
    firstRelasi(r) = NULL;
}
adr_relasi createElmRelasi(list_relasi r){
    adr_relasi p = new elm_relasi;
    nextDosen(p) = NULL;
    nextMhs(p) = NULL;
    nextRelasi(p) = NULL;

    return p;
}

    // insert first
void insertDosen(list_dosen &d, adr_dosen p){
    nextDosen(p) = firstDosen(d);
    firstDosen(d) = p;
    p = NULL;
}
void insertMhs(list_mhs &m, adr_mhs p){
    nextMhs(p) = firstMhs(m);
    firstMhs(m) = p;
    p = NULL;
}
    // Fungsi Pencarian
adr_dosen searchDosen(list_dosen &d, infotype_dosen dosen){
    adr_dosen p = firstDosen(d);
    while(p != NULL){
        if(infoDosen(p).nama_dosen == dosen.nama_dosen){
            return p;
        }
        p = nextDosen(p);
    }
    return NULL;
}
adr_mhs searchMhs(list_mhs m, infotype_mahasiswa mhs){
    adr_mhs p = firstMhs(m);
    while(p != NULL){
        if(infoMhs(p).nama_mhs == mhs.nama_mhs){
            return p;
        }
        p = nextMhs(p);
    }
    return NULL;
}

    //delete first SLL
void deleteDosen(list_dosen &d, infotype_dosen dosen, list_relasi &r){
    adr_dosen p = searchDosen(d, dosen);
    adr_relasi q = firstRelasi(r);
    if (p != NULL){
        while(q != NULL){
            if(nextDosen(q) == p){
                nextDosen(q) = NULL;
                nextMhs(q) = NULL;
                deleteRelasi(r, q);
            }
            q = nextRelasi(q);
        }
        if (p == firstDosen(d)){
            firstDosen(d) = nextDosen(p);
            nextDosen(p) = NULL;
        } else if(nextDosen(p) == NULL){
            adr_dosen x = firstDosen(d);
            while(nextDosen(x) != p){
                x = nextDosen(x);
            }
            nextDosen(x) = nextDosen(p);
            nextDosen(p) = NULL;
        }
        cout << "Data Dosen Berhasil dihapus!"<<endl;
    }
}
void deleteMhs(list_mhs &m, infotype_mahasiswa mhs, list_relasi &r){
    adr_mhs p = searchMhs(m, mhs);
    adr_relasi q = firstRelasi(r);

    if(p != NULL){
        while(q = NULL){
            if(nextMhs(q) == p){
                nextMhs(q) == NULL;
                nextDosen(q) == NULL;
                deleteRelasi(r, q);
            }
            q = nextRelasi(q);
        }
        if(p == firstMhs(m)){
            firstMhs(m) = nextMhs(p);
            nextMhs(p) = NULL;
        } else if(nextMhs(p) == NULL){
            adr_mhs x = firstMhs(m);
            while(nextMhs(x) != p){
                x = nextMhs(x);
            }
            nextMhs(x) = nextMhs(p);
            nextMhs(p) = NULL;
        }
        cout << "Data Dosen Berhasil dihapus!"<<endl;
    }
    cout << "Data tidak ditemukan" << endl;
}

    //menghapus relasi
void deleteRelasi(list_relasi &r, adr_relasi p){
    if(p == firstRelasi(r)){
        firstRelasi(r) = nextRelasi(p);
    } else{
        adr_relasi q = firstRelasi(r);
        while(nextRelasi(q) != p){
            //ketika next dr Relasi sama dengan P maka,
            q = nextRelasi(q); // q di assign dengan nextRelasi sehingga akan lanjut ke element selanjutnya
        }
        nextRelasi(q) = nextRelasi(p);
    }
}

void showAll(list_dosen d, list_mhs m){
    adr_dosen p = firstDosen(d);
    cout << "== Data Dosen =="<<endl;
    if(p != NULL){
        while(p != NULL){
            cout << infoDosen(p).nama_dosen << ", " << infoDosen(p).kepakaran << ", " << infoDosen(p).juml_bimbingan << endl;
            p = nextDosen(p);
        }
    } else{
        cout << "Data Kosong" <<endl;
    }

    cout << endl;

    adr_mhs q = firstMhs(m);
    cout << "== Data Mahasiswa ==" <<endl;
    if(q != NULL){
        while(q != NULL){
            cout << infoMhs(q).nama_mhs << ", " << infoMhs(q).NIM << ", "<< infoMhs(q).topikTA <<infoMhs(q).SKS_Lulus << endl;
            q = nextMhs(q);
        }
        cout << endl;
    } else{
        cout << "Data Kosong" << endl;
    }
}

void showDosen(list_dosen d){
    adr_dosen p = firstDosen(d);
    cout << "-- Data Dosen -- "<<endl;
    if(p != NULL){
        while(p != NULL){
            cout << "Nama Dosen: "<<infoDosen(p).nama_dosen<<endl;
            cout << "Kepakaran: " << infoDosen(p).kepakaran<<endl;
            cout << "Jumlah Bimbingan: "<< infoDosen(p).juml_bimbingan<<endl;

            p = nextDosen(p);
            cout << endl;
        }
    }
}
    //update
void updateBimbingan(list_dosen &d, infotype_dosen dosen){
    adr_dosen p = searchDosenUpdate(d, dosen);
    if(p != NULL && infoDosen(p).nama_dosen == dosen.nama_dosen && infoDosen(p).juml_bimbingan == dosen.juml_bimbingan){
        cout << "Masukan Jumlah Bimbingan yang ingin diperbarui: ";
        cin >> infoDosen(p).juml_bimbingan;
        cout << "Data Update Bimbingan Mahasiswa" << endl;
        cout << "UPDATE JUMLAH BIMBINGAN BERHASIL! " << endl;
    } else if (p != NULL && infoDosen(p).nama_dosen != dosen.nama_dosen && infoDosen(p).juml_bimbingan == dosen.juml_bimbingan){
        cout << "----------  Data Update Bimbingan Mahasiswa  ----------" << endl;
        cout << " GAGAL DI UPDATE KARENA NAMA DOSEN TIDAK DITEMUKAN! " << endl;
    } else if (p != NULL && infoDosen(p).nama_dosen == dosen.nama_dosen && infoDosen(p).juml_bimbingan != dosen.juml_bimbingan){
        cout << "----------  Data Update Bimbingan Mahasiswa  ----------" << endl;
        cout << " GAGAL DI UPDATE KARENA JUMLAH BIMBINGAN TIDAK DITEMUKAN! " << endl;
    }  else {
        cout << "----------  Data Update Bimbingan Mahasiswa  ----------" << endl;
        cout << "DATA YANG DI UPDATE MASIH KOSONG! " << endl;
    }
}
adr_dosen searchDosenUpdate(list_dosen d, infotype_dosen dosen){
    adr_dosen p = firstDosen(d);
    while(p != NULL){
        if(infoDosen(p).nama_dosen == dosen.nama_dosen && infoDosen(p).juml_bimbingan == dosen.juml_bimbingan){
            return p;
        }
        p = nextDosen(p);
    }
    return NULL;
}

    //kuota
void kuota(list_dosen kuotaDosen){
    adr_dosen p;
    adr_mhs q;
    if(firstDosen(kuotaDosen) == NULL){
        cout << "List Kosong"<<endl;
    } else{
        p = firstDosen(kuotaDosen);
        cout << "Dosen yang memiliki ketersediaan Kuota: ";
        while(p != NULL){
            if(infoDosen(p).juml_bimbingan <= 10){
                cout << infoDosen(p).nama_dosen << " ";
            }
            p = nextDosen(p);
        }
    }
    cout << endl;
}
int TA(list_dosen dosen){
    adr_dosen p;
    adr_mhs q;
    int total = 0;

    if (firstDosen(dosen) == NULL){
        cout<<"List Kosong"<<endl;
    } else {
        p = firstDosen(dosen);
        while(p != NULL){
            if (infoDosen(p).juml_bimbingan <= 10){
                total = total + infoDosen(p).juml_bimbingan;
            }
            p = nextDosen(p);
        }
    }
    return total;
}

int menu(){
    cout << "===== Main Menu =====" <<endl;
    cout << "1. Tambah Data Dosen"<<endl;
    cout << "2. Tambah Data Mahasiswa"<<endl;
    cout << "3. Hapus Data Dosen"<<endl;
    cout << "4. Hapus Data Mahasiswa"<<endl;
    cout << "5. Mengupdate jumlah bimbingan mahasiswa di setiap dosen jika ada penambahan atau pengurangan mahasiswa bimbingan"<<endl;
    cout << "6. Menampilkan data semua dosen pembimbing beserta jumlah mahasiswa bimbingannya"<<endl;
    cout << "7. Tampilkan seluruh dosen pembimbing (Beserta mahasiswa bimbingannya)"<<endl;
    cout << "8. Mencari Nama dosen tertentu dengan kuota masih tersedia"<<endl;
    cout << "9. Menghitung seluruh jumlah mahasiswa yang mengambil TA" <<endl;
    cout << "10. Keluar Program"<<endl <<endl;

    cout << "Masukkan angka pilihan anda: ";
    int input = 0;
    cin >> input;

    return input;
}


