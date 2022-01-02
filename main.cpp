#include "multi.h"

int main()
{
    infotype_dosen dosen;
    infotype_mahasiswa mhs;
    list_dosen d;
    list_mhs m;
    list_relasi r;
    adr_mhs q;
    adr_dosen p;

    createlistDosen(d);
    createlistMhs(m);

    int pilihan = 0;
    int n;

    pilihan = menu();
    while(pilihan != 10){
        switch(pilihan){
        case 1:
            cout << "Masukkan Jumlah data dosen yang di inginkan: ";
            cin >> n;
            for(int i = 1; i <= n; i++){
                cout << "Masukkan data ke " << i << endl;

                cout << "Masukkan nama dosen: "; cin >> dosen.nama_dosen;
                cout << "Masukkan Kepakaran:"; cin >> dosen.kepakaran;
                cout << "Masukkan Jumlah Bimbingan: "; cin>> dosen.juml_bimbingan;
                p = createElmDosen(dosen);
                insertDosen(d, p);
            }
            break;
        case 2:
            cout << "Masukkan jumlah mahasiswa yang ingin dimasukkan: "; cin >> n;
            for(int i = 1; i <= n; i++){
                cout << "Masukkan data ke " << i << endl;
                cout << "Masukkan Nama Mahasiswa: "; cin >> mhs.nama_mhs;
                cout << "Masukkan NIM: "; cin >> mhs.NIM;
                cout << "Masukkan topik TA: "; cin>>mhs.topikTA;
                cout << "Masukkan SKS: "; cin >> mhs.SKS_Lulus;

                q = createElmMhs(mhs);
                insertMhs(m, q);
            }
            break;
        case 3:
            cout << "Masukkan Nama Dosen yang akan dihapus: "; cin>> dosen.nama_dosen;
            cout << "Data dosen yang akan dihapus"<<endl;
            deleteDosen(d,dosen, r);
            break;
        case 4:
            cout << "Masukkan Nama Mahasiswa yang akan dihapus: "; cin>>mhs.nama_mhs;
            cout << "Data Mahasiswa yang akan dihapus"<<endl;
            deleteMhs(m, mhs, r);
            break;
        case 5:
            cout << "Masukkan Nama Dosen: ";
            cin >> dosen.nama_dosen;
            cout << "Masukan Jumlah Bimbingan yang lama: ";
            cin >> dosen.juml_bimbingan;
            updateBimbingan(d, dosen);
            break;
        case 6:
            showDosen(d);
            break;

        case 7:
            showAll(d, m);
            break;
        case 8:
            kuota(d);
            break;

        case 9:
            TA(d);
            break;

        case 10:
            cout << "Keluar program!" <<endl;
            break;
        }
        pilihan = menu();
    }
    cout << "Program Selesai" << endl;
    return 0;
}
