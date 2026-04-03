#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> daftarBuku;

void inputBuku();
void showBuku();
void sortBuku();

int main() {
	int a;
	
	do {
		cout << "--------------------------------" << "\n";
		cout << "\n=== Program Penyimpanan Buku ===" << "\n";
		cout << "\n1. Input Buku" << "\n";
		cout << "2. Tampilkan Buku" << "\n";
		cout << "3. Sorting Buku" << "\n";
		cout << "4. Keluar" << "\n";
		cout << "\nPilih fitur yang ingin dilakukan (1/2/3/4): ";
		cin >> a;
		
		if (a == 1) {
			inputBuku();
		} else if (a == 2) {
			showBuku();
		} else if (a == 3) {
			sortBuku();
		} else {
			cout << "\nSelamat Tinggal!";
		}
	}
	while (a < 4);
}

void inputBuku() {
	string namaBuku;
	int jmlBuku;
	
	cout << "\nBerapa jumlah buku yang ingin dimasukkan?" << "\n";
	cout << "Jumlah Buku: ";
	cin >> jmlBuku;
	for (int i = 0; i < jmlBuku; i++) {
		cout << "Buku ke-" << i+1 << ": ";
		getline(cin >> ws, namaBuku);
		daftarBuku.push_back(namaBuku);
	}
	cout << "\nBuku telah berhasil di input!" << "\n" << "\n";
}

void showBuku() {
	cout << "\nTerdapat " << daftarBuku.size() << " judul buku" << "\n" << "\n";
	for (int i = 0; i < daftarBuku.size(); i++) {
  		cout << i+1 << ". " << daftarBuku[i] << "\n";
	}
}

void sortBuku() {
	for (int i = 0; i < daftarBuku.size() - 1; i++) {
		for (int j = 0; j < daftarBuku.size() - 1 - i; j++) {
			if (daftarBuku[j] > daftarBuku[j+1]) {
				string temp = daftarBuku[j];
				daftarBuku[j] = daftarBuku[j+1];
				daftarBuku[j+1] = temp; 
			}
		}
	}
	cout << "\nBuku telah disorting" << "\n" << "\n";
}






