// Soal 2
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
// fungsi utk mencari nilai terkecil dalam sebuah BST
// pointer ke node root dari tree
int findMinValue(Node* root) {
    if (root == nullptr) { // jika root nullptr, tree kosong
        return -1; // kembalikan -1 
    }
    Node* current = root; // mulai dari node paling atas/root
    while (current->left != nullptr) { // selama masih ada anak kiri
        current = current->left; // terus telusuri ke kiri
    }
    return current->data; // node paling kiri adalah nilai terkecil
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl; // Harusnya output: 20
    return 0;
}