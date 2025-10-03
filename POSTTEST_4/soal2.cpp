#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};
//menambahkan fungsi push dan pop 
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

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    for (char c : expr) {  // utk setiap karakter dlm string expr
        if (c == '(' || c == '{' || c == '[') { //jika karakter adalah kurung buka
            push(stackTop, c); //simpan ke stack
        } else if (c == ')' || c == '}' || c == ']') {  //jika karakter adalah kurung tutup
            if (stackTop == nullptr) {  //cek apakah stack  kosong
                return false; 
            }
            char top = pop(stackTop); //ambil top stack
            if ((c == ')' && top != '(') || //cek kecocokan pasangan kurung
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false; //jika ga cocok
            }
        }
    }
    bool isBalanced = (stackTop == nullptr); //stack kosong -> true
    while (stackTop != nullptr) { //stack ga kosong
        pop(stackTop); //bersihkan stack
    }
    return isBalanced;
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    // Expected output: Seimbang
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}