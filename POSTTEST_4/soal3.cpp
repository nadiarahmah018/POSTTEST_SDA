#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    if(front == nullptr) { //queue kosong
        // front dan rear ke newNode
        front = newNode; 
        rear = newNode;
    } else { //queue ga kosong
        //sambung rear-> next ke newNode lalu update rear
        rear->next = newNode;
        rear = newNode;
    }
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong
     //simpan data dari font node
    Node* temp = front;
    string data = temp->document; 
    front = front->next; //geser front ke front->next

    if (front == nullptr) { //jika front nullptr
        rear = nullptr; //set rear juga ke nullptr
    }

    delete temp; //hapus node lama
    return data;
}

void processAllDocuments(Node*& front, Node*& rear) {
    //loop hingga queue kosng dan
    while (front != nullptr) {
        string doc = dequeue(front, rear); //dequeue
        if (!doc.empty()) {
            cout << "Memproses: " << doc << endl; //print setiap dokumen
        }
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}