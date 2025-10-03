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

    // Push setiap karakter dari string ke stack
    for (char c : s) {
        push(stackTop, c); 
    }

    // Pop setiap karakter dari stack untuk membalikkan string    
    while (stackTop != nullptr) {
        reversed += pop(stackTop); 
    }
    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; // Output: ataD rukurts
    return 0;
}