#include <iostream>
#include <string>
using namespace std;

int main() {

    string judul[] = {
        "Algoritma",
        "Basis Data",
        "Jaringan Komputer",
        "Pemrograman C++",
        "Sistem Operasi",
        "Struktur Data",
        "Web Programming"
    };

    int rak[] = {
        101,
        102,
        103,
        104,
        105,
        106,
        107
    };

    int jumlah = sizeof(judul) / sizeof(judul[0]);

    string cari;

    cout << "=========== DAFTAR BUKU ===========\n";
    for(int i=0;i<jumlah;i++){
        cout << judul[i] << endl;
    }

    cout << "\nMasukkan judul buku yang dicari : ";
    getline(cin, cari);

    int kiri = 0;
    int kanan = jumlah - 1;
    bool ditemukan = false;

    while(kiri <= kanan){

        int tengah = (kiri + kanan) / 2;

        if(judul[tengah] == cari){

            cout << "\nBuku ditemukan!" << endl;
            cout << "Judul Buku : " << judul[tengah] << endl;
            cout << "Letak Rak  : " << rak[tengah] << endl;

            ditemukan = true;
            break;
        }

        else if(cari > judul[tengah]){
            kiri = tengah + 1;
        }

        else{
            kanan = tengah - 1;
        }
    }

    if(!ditemukan){
        cout << "\nMaaf, buku tidak ditemukan." << endl;
    }

    return 0;
}
