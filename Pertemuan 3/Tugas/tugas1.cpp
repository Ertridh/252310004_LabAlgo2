#include <iostream>
using namespace std;

int main() {
    int data[] = {0, 6, 12, 18, 24};
    int jumlah = sizeof(data) / sizeof(data[0]);

    int cari;
    bool ditemukan = false;

    cout << "Data yang tersedia : ";
    for (int i = 0; i < jumlah; i++) {
        cout << data[i] << " ";
    }

    cout << "\n\nMasukkan data yang dicari : ";
    cin >> cari;

    // Sequential Search
    for (int i = 0; i < jumlah; i++) {
        if (data[i] == cari) {
            ditemukan = true;
            cout << "\nBilangan ditemukan pada indeks ke-" << i << endl;
            break;
        }
    }

    if (!ditemukan) {
        cout << "\nBilangan tidak ditemukan." << endl;
    }

    return 0;
}
