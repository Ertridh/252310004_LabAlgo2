#include <iostream>
using namespace std;

#define MAX 5

class Stack {

private:
    int data[MAX];
    int top;

public:

    // Constructor
    Stack() {
        top = -1;
    }

    // Mengecek stack kosong
    bool isEmpty() {
        return top == -1;
    }

    // Mengecek stack penuh
    bool isFull() {
        return top == MAX - 1;
    }

    // Push
    void push(int nilai) {

        if (isFull()) {
            cout << "Stack penuh!\n";
            return;
        }

        top++;
        data[top] = nilai;
    }

    // Pop
    void pop() {

        if (isEmpty()) {
            cout << "Stack kosong!\n";
            return;
        }

        cout << "Data yang dihapus : "
             << data[top] << endl;

        top--;
    }

    // Peek
    void peek() {

        if (isEmpty()) {
            cout << "Stack kosong.\n";
            return;
        }

        cout << "Data paling atas : "
             << data[top] << endl;
    }

    // Size
    int size() {
        return top + 1;
    }

    // Display
    void display() {

        if (isEmpty()) {
            cout << "Stack kosong.\n";
            return;
        }

        cout << "\nIsi Stack\n";
        cout << "---------\n";

        for (int i = top; i >= 0; i--) {
            cout << data[i] << endl;
        }
    }
};

int main() {

    Stack s;

    // Sesuai ilustrasi
    s.push(621);
    s.push(999);
    s.push(201);
    s.push(94);
    s.push(124);

    s.display();

    cout << "\nJumlah data : "
         << s.size() << endl;

    s.peek();

    cout << "\nMelakukan POP...\n";
    s.pop();

    cout << "\nIsi Stack setelah Pop\n";
    s.display();

    return 0;
}
