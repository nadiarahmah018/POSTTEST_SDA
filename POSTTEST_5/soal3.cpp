// Soal 3
#include <iostream>
using namespace std;
// Struktur Node untuk Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert untuk membangun tree
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// fungsi untuk mencari nilai terbesar dalam sebuah BST.
// pointer ke node root dari tree
int findMaxValue(Node* root) {
    if (root == nullptr) {  // jika root nullptr, tree kosong
        return -1; // mengembalikan -1
    }
    Node* current = root; // mulai dari node paling atas/root
    while (current->right != nullptr) {  // selama maasih ada anak kanan
        current = current->right; // terus telusuri ke kanan
    }
    return current->data; // node paling kanan adalah nilai terbesar
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl; // Harusnya output: 80
    return 0;
}