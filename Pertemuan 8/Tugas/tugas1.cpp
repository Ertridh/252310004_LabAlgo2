#include <iostream>
#include <string>
using namespace std;

#define MAX 5

class Queue {
private:
    string antrean[MAX];
    int front;
    int rear;

public:
    // Constructor
    Queue() {
        front = -1;
        rear = -1;
    }

    // Mengecek apakah antrean kosong
    bool isEmpty() {
        return (front == -1);
    }

    // Mengecek apakah antrean penuh
    bool isFull() {
        return (rear == MAX - 1);
    }

    // Menambahkan pengunjung ke antrean
    void enqueue(string nama) {

        if (isFull()) {
            cout << "\nAntrean penuh! Pengunjung tidak dapat ditambahkan.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }

        antrean[rear] = nama;

        cout << "\nPengunjung \"" << nama
             << "\" berhasil mengambil nomor antrean." << endl;
    }

    // Memanggil antrean pertama
    void dequeue() {

        if (isEmpty()) {
            cout << "\nAntrean masih kosong.\n";
            return;
        }

        cout << "\nMemanggil Pengunjung : "
             << antrean[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Melihat antrean paling depan
    void peek() {

        if (isEmpty()) {
            cout << "\nAntrean kosong.\n";
        } else {
            cout << "\nPengunjung berikutnya : "
                 << antrean[front] << endl;
        }
    }

    // Menghitung jumlah antrean
    int size() {

        if (isEmpty())
            return 0;

        return rear - front + 1;
    }

    // Menampilkan seluruh antrean
    void display() {

        if (isEmpty()) {
            cout << "\nBelum ada antrean.\n";
            return;
        }

        cout << "\n===== DAFTAR ANTREAN =====\n";

        for (int i = front; i <= rear; i++) {
            cout << i - front + 1
                 << ". " << antrean[i] << endl;
        }
    }
};

int main() {

    Queue loket;

    int pilihan;
    string nama;

    do {

        cout << "\n========================================";
        cout << "\n SISTEM ANTREAN DIGITAL LAYANAN PUBLIK";
        cout << "\n========================================";
        cout << "\n1. Ambil Nomor Antrean (Enqueue)";
        cout << "\n2. Panggil Antrean (Dequeue)";
        cout << "\n3. Lihat Antrean Terdepan (Peek)";
        cout << "\n4. Cek Antrean Kosong (isEmpty)";
        cout << "\n5. Cek Antrean Penuh (isFull)";
        cout << "\n6. Jumlah Antrean (Size)";
        cout << "\n7. Tampilkan Seluruh Antrean";
        cout << "\n0. Keluar";
        cout << "\n========================================";
        cout << "\nPilihan : ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {

        case 1:
            cout << "Masukkan Nama Pengunjung : ";
            getline(cin, nama);
            loket.enqueue(nama);
            break;

        case 2:
            loket.dequeue();
            break;

        case 3:
            loket.peek();
            break;

        case 4:
            if (loket.isEmpty())
                cout << "\nAntrean sedang kosong.\n";
            else
                cout << "\nMasih ada antrean.\n";
            break;

        case 5:
            if (loket.isFull())
                cout << "\nAntrean sudah penuh.\n";
            else
                cout << "\nAntrean masih tersedia.\n";
            break;

        case 6:
            cout << "\nJumlah antrean saat ini : "
                 << loket.size() << " orang.\n";
            break;

        case 7:
            loket.display();
            break;

        case 0:
            cout << "\nTerima kasih.\n";
            break;

        default:
            cout << "\nPilihan tidak tersedia.\n";
        }

    } while (pilihan != 0);

    return 0;
}
