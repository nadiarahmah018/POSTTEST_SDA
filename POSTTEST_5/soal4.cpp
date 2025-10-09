// Soal 4
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

void postOrderTraversal(Node* root) {
    if (root == nullptr) { // jika root nullptr, tree kosong
        return; // kembalikan 
    }
    postOrderTraversal(root->left); // kunjungi subtree kiri
    postOrderTraversal(root->right); // kunjungi subtree kanan
    cout << root->data << " "; // setelah kiri & kanan selesai, cetak node
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root); // Harusnya output: 20 40 30 60 80 70 50
    cout << endl;
    return 0;
}