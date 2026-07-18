#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node *left;
    Node *right;
};

// Membuat node baru
Node* buatNode(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

// Traversal Preorder
void preorder(Node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Traversal Inorder
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Traversal Postorder
void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {

    // Membuat Tree sesuai gambar

    Node *root = buatNode(7);

    root->left = buatNode(14);
    root->right = buatNode(83);

    root->left->left = buatNode(91);
    root->left->right = buatNode(102);

    root->left->right->left = buatNode(31);
    root->left->right->right = buatNode(87);

    root->left->right->left->left = buatNode(93);

    root->left->right->left->left->left = buatNode(24);
    root->left->right->left->left->right = buatNode(76);

    root->right->left = buatNode(192);
    root->right->right = buatNode(932);

    root->right->right->right = buatNode(153);

    root->right->right->right->left = buatNode(772);
    root->right->right->right->right = buatNode(812);

    cout << "Traversal Preorder : ";
    preorder(root);

    cout << "\nTraversal Inorder  : ";
    inorder(root);

    cout << "\nTraversal Postorder: ";
    postorder(root);

    cout << endl;

    return 0;
}
