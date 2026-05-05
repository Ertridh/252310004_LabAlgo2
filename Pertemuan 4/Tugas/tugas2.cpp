#include <iostream>
using namespace std;

class contoh {
	private:
		int nilai;
	public:
		// Membuat constructor
		contoh(int n) {
			nilai = n;
		}
		
		// Membuat getter
		int getNum() {
			return nilai;
		}
};

int main() {
	contoh obj(10); // memanggil constructor
	cout << "Nilai yang diinput: " << obj.getNum() << endl;
}
