#include <iostream>
using namespace std;

class Karyawan {
	private:
		string nama;
		int umur;
		string jabatan;
	
	public:
		void setNama(string n) {
			nama = n;
		}
		
		string getNama() {
			return nama;
		}
		
		void setUmur(int u) {
			umur = u;
		}
		
		int getUmur() {
			return umur;
		}
		
		void setJabatan(string j) {
			jabatan = j;
		}
		
		string getJabatan() {
			return jabatan;
		}
};

int main() {
	Karyawan kar;
	kar.setNama("Bebi Ahmad Janlinov");
	kar.setUmur(20);
	kar.setJabatan("CEO");
	cout << kar.getNama() << endl;
	cout << kar.getUmur() << endl;
	cout << kar.getJabatan();
	return 0;
}
