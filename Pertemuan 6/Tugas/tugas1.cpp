#include <iostream>
#include <string>
using namespace std;

//========================
// CLASS INDUK
//========================
class Mahasiswa {

private: // Encapsulation
    string nama;
    string nim;
    string jurusan;
    float ipk;

public:

    // Constructor
    Mahasiswa(string n, string ni, string j, float i) {
        nama = n;
        nim = ni;
        jurusan = j;
        ipk = i;
    }

    // Setter (Encapsulation)
    void setIPK(float i) {
        ipk = i;
    }

    // Getter (Encapsulation)
    float getIPK() {
        return ipk;
    }

    string getNama() {
        return nama;
    }

    string getNIM() {
        return nim;
    }

    string getJurusan() {
        return jurusan;
    }

    // Method virtual (Polymorphism)
    virtual void tampilkanData() {
        cout << "\n===== DATA MAHASISWA =====" << endl;
        cout << "Nama     : " << nama << endl;
        cout << "NIM      : " << nim << endl;
        cout << "Jurusan  : " << jurusan << endl;
        cout << "IPK      : " << ipk << endl;
    }

    virtual void aktivitas() {
        cout << nama << " sedang mengikuti perkuliahan." << endl;
    }
};

//========================
// CLASS TURUNAN
//========================
class MahasiswaAktif : public Mahasiswa {

private:
    int semester;
    int sks;
    string organisasi;
    string status;

public:

    // Constructor
    MahasiswaAktif(string n, string ni, string j, float i,
                   int s, int sk, string o, string st)
        : Mahasiswa(n, ni, j, i)
    {
        semester = s;
        sks = sk;
        organisasi = o;
        status = st;
    }

    // Override Method (Polymorphism)
    void tampilkanData() override {

        Mahasiswa::tampilkanData();

        cout << "Semester : " << semester << endl;
        cout << "SKS      : " << sks << endl;
        cout << "Organisasi : " << organisasi << endl;
        cout << "Status   : " << status << endl;
    }

    // Override Method
    void aktivitas() override {
        cout << getNama()
             << " sedang kuliah dan aktif di organisasi "
             << organisasi << "." << endl;
    }
};

int main() {

    // Objek class induk
    Mahasiswa mhs1(
        "Budi",
        "231011001",
        "Teknologi Informasi",
        3.75);

    // Objek class turunan
    MahasiswaAktif mhs2(
        "Andi",
        "231011002",
        "Teknologi Informasi",
        3.90,
        4,
        22,
        "HIMATI",
        "Aktif");

    cout << "===== OBJEK 1 =====" << endl;
    mhs1.tampilkanData();
    mhs1.aktivitas();

    cout << "\n==============================\n";

    cout << "\n===== OBJEK 2 =====" << endl;
    mhs2.tampilkanData();
    mhs2.aktivitas();

    return 0;
}
