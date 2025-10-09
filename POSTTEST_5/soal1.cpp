// Soal 1
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
// fungsi ngitung jumlah node dlm tree
// pointer ke node root dari tree
int countNodes(Node* root) {
    if (root == nullptr) { // jika root nullptr, tree kosong
        return 0; // maka, kembalikan 0
    } // kalau ada node,
     // total = 1 (node saat ini) + jumlah node di subtree kiri + jumlah node di subtree kanan
    return 1 + countNodes(root->left) + countNodes(root->right); 

}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);

    cout << "Jumlah total node dalam tree adalah: " << countNodes(root) << endl; // Harusnya output: 4
    return 0;
}