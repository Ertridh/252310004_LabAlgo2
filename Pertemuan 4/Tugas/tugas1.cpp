#include <iostream>
#include <string>
using namespace std;

class Kampus {
	private:
		string nama, kelas, npm;
	public:
		void set_nama(string nm) {
			nama = nm;
		}
		
		string get_nama() {
			return nama;
		}
		
		void set_kelas(string kls) {
			kelas = kls;
		}
		
		string get_kelas() {
			return kelas;
		}
		
		void set_npm(string nim) {
			npm = nim;
		}
		
		string get_npm() {
			return npm;
		}
};

int main() {
	
	Kampus Mahasiswa;
	
	string input;
	
	cout << "Masukkan nama: ";
	cin >> input;
	Mahasiswa.set_nama(input);
	
	cout << "Masukkan kelas: ";
	cin >> input;
	Mahasiswa.set_kelas(input);
	
	cout << "Masukkan NPM: ";
	cin >> input;
	Mahasiswa.set_npm(input);
	
	cout << "\nHasil:" << endl;
	cout << Mahasiswa.get_nama() << endl;
	cout << Mahasiswa.get_kelas() << endl;
	cout << Mahasiswa.get_npm();
}
