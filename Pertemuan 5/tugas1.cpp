#include <iostream>     // Library untuk operasi input dan output
using namespace std;

// Deklarasi class bernama contoh
class contoh {

private:
    int nilai;          // Variabel anggota (atribut) yang bersifat private

public:

    // Constructor
    // Constructor akan dipanggil secara otomatis saat objek dibuat
    contoh(int n) {
        nilai = n;      // Mengisi variabel nilai dengan parameter n
    }

    // Method untuk mengambil nilai dari variabel private
    int getNum() {
        return nilai;   // Mengembalikan nilai yang tersimpan
    }
};

int main() {

    // Membuat objek bernama obj dan langsung mengirim nilai 10
    // Constructor contoh(int n) akan dipanggil otomatis
    contoh obj(10);

    // Menampilkan nilai yang disimpan pada objek
    cout << "Nilai yang diinput: " << obj.getNum() << endl;

    return 0;
}
