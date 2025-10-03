#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    // Kasus 1: List masih kosong
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }
    // Kasus 2: Data baru lebih kecil dari head (sisipkan di awal)
    
    if (data <= head_ref->data) { //cek data baru <= head 
        newNode->next = head_ref; //newNode next ke head
        newNode->prev = head_ref->prev; //newNode prev ke node akhir
        head_ref->prev->next = newNode; //node akhir ke newNode
        head_ref->prev = newNode;//head prev ke newNode
        head_ref = newNode; //update head ke newNode
        return;
    }
    // Kasus 3 : Cari posisi yang tepat (tengah/akhir)
    Node* current = head_ref;

    // geser ke depan sampai menemukan posisi yang tepat
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }

    // Sisipkan newNode setelah current
    newNode->next = current->next; //newNode next ke current next
    newNode->prev = current; //newnode prev ke current
    current->next->prev = newNode; //current next prev ke newNode
    current->next = newNode; //current next ke newNode
}    

void printList(Node *head_ref)
{
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main()
{
    Node *head = nullptr;

    // Test sorted insert
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    // Expected output: 10 20 30 40
    printList(head);

    return 0;
}