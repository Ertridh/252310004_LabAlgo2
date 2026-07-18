#include <iostream>
using namespace std;

struct Node {

    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList {

private:

    Node *head;
    Node *tail;

public:

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Menambah node di belakang
    void insertBack(int nilai) {

        Node *baru = new Node;

        baru->data = nilai;
        baru->next = NULL;
        baru->prev = NULL;

        if (head == NULL) {

            head = tail = baru;
        }
        else {

            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }

    // Menampilkan dari Head ke Tail
    void displayForward() {

        Node *bantu = head;

        cout << "HEAD -> ";

        while (bantu != NULL) {

            cout << bantu->data;

            if (bantu->next != NULL)
                cout << " <-> ";

            bantu = bantu->next;
        }

        cout << " <- TAIL";
    }

    // Menampilkan dari Tail ke Head
    void displayBackward() {

        Node *bantu = tail;

        cout << "TAIL -> ";

        while (bantu != NULL) {

            cout << bantu->data;

            if (bantu->prev != NULL)
                cout << " <-> ";

            bantu = bantu->prev;
        }

        cout << " <- HEAD";
    }

};

int main() {

    DoublyLinkedList list;

    // Sesuai gambar
    list.insertBack(24);
    list.insertBack(10);
    list.insertBack(33);
    list.insertBack(33);

    cout << "Traversal Maju\n";
    list.displayForward();

    cout << "\n\nTraversal Mundur\n";
    list.displayBackward();

    return 0;
}
