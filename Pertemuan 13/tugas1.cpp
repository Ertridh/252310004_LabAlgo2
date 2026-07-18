#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Item {
    int key;
    string nama;
    bool terisi;
    bool dihapus;
};

Item hashTable[SIZE];

// Fungsi hash (Division Method)
int hashFunction(int key) {
    return key % SIZE;
}

// Inisialisasi tabel
void initTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i].terisi = false;
        hashTable[i].dihapus = false;
    }
}

// Insert Item
void insertItem(int key, string nama) {

    int index = hashFunction(key);
    int awal = index;

    while (hashTable[index].terisi && !hashTable[index].dihapus) {
        index = (index + 1) % SIZE;

        if (index == awal) {
            cout << "\nHash Table Penuh!\n";
            return;
        }
    }

    hashTable[index].key = key;
    hashTable[index].nama = nama;
    hashTable[index].terisi = true;
    hashTable[index].dihapus = false;

    cout << "\nItem berhasil ditambahkan pada index "
         << index << endl;
}

// Cari Item
void searchItem(int key) {

    int index = hashFunction(key);
    int awal = index;

    while (hashTable[index].terisi || hashTable[index].dihapus) {

        if (hashTable[index].terisi &&
            hashTable[index].key == key) {

            cout << "\nItem ditemukan\n";
            cout << "Key   : " << hashTable[index].key << endl;
            cout << "Nama  : " << hashTable[index].nama << endl;
            cout << "Index : " << index << endl;

            return;
        }

        index = (index + 1) % SIZE;

        if (index == awal)
            break;
    }

    cout << "\nItem tidak ditemukan.\n";
}

// Hapus Item
void deleteItem(int key) {

    int index = hashFunction(key);
    int awal = index;

    while (hashTable[index].terisi || hashTable[index].dihapus) {

        if (hashTable[index].terisi &&
            hashTable[index].key == key) {

            hashTable[index].terisi = false;
            hashTable[index].dihapus = true;

            cout << "\nItem berhasil dihapus.\n";
            return;
        }

        index = (index + 1) % SIZE;

        if (index == awal)
            break;
    }

    cout << "\nItem tidak ditemukan.\n";
}

// Display
void display() {

    cout << "\n=========== HASH TABLE ===========\n";

    for (int i = 0; i < SIZE; i++) {

        cout << "[" << i << "] ";

        if (hashTable[i].terisi)
            cout << hashTable[i].key
                 << " - "
                 << hashTable[i].nama;

        else
            cout << "-";

        cout << endl;
    }
}

int main() {

    initTable();

    int pilih;
    int key;
    string nama;

    do {

        cout << "\n================================";
        cout << "\n INVENTORY MANAGEMENT HASH TABLE";
        cout << "\n================================";
        cout << "\n1. Insert Item";
        cout << "\n2. Hapus Item";
        cout << "\n3. Cari Item";
        cout << "\n4. Lihat Semua Item";
        cout << "\n0. Keluar";
        cout << "\n================================";
        cout << "\nPilihan : ";
        cin >> pilih;

        switch (pilih) {

        case 1:

            cout << "Masukkan Key Item : ";
            cin >> key;

            cin.ignore();

            cout << "Masukkan Nama Item : ";
            getline(cin, nama);

            insertItem(key, nama);

            break;

        case 2:

            cout << "Masukkan Key : ";
            cin >> key;

            deleteItem(key);

            break;

        case 3:

            cout << "Masukkan Key : ";
            cin >> key;

            searchItem(key);

            break;

        case 4:

            display();

            break;

        case 0:

            cout << "\nProgram selesai.\n";

            break;

        default:

            cout << "\nPilihan tidak tersedia.\n";
        }

    } while (pilih != 0);

    return 0;
}
