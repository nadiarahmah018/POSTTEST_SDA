#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};
 
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0'; // Return null character jika stack kosong
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    // Push semua karakter ke stack
    for (char c : s) { // untuk setiap karakter c dalam string s
        push(stackTop, c); // simpan karakter ke dalam stack
    }

    // Pop semua karakter dari stack untuk mendapatkan string terbalik    
    while (stackTop != nullptr) { //selama stack ga kosong
        reversed += pop(stackTop); //ambil karakter top, tambahin ke string hasil
    }
    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; // Output: ataD rukurts
    return 0;
}