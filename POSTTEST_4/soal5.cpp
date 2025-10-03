#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void exchangeHeadAndTail(Node *&head_ref) {
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    Node* head = head_ref;
    Node* tail = head_ref->prev; //tail adalah prev dari head

    // Jika hanya 2 node, jadikan tail sebagai head baru
    if (head->next == tail && tail->next == head) {
        head_ref = tail;
        return;
    }

    //simpan neighbor
    Node* head_next = head->next; //node setelah head
    Node* tail_prev = tail->prev; //node sebelum tail

    // sambungkan taill ke head_next(tail pindah ke depan)
    tail->next = head_next; 
    head_next->prev = tail; 

    //sambungkan head ke tail_prev (head pindah ke belakang)
    head->prev = tail_prev;
    tail_prev->next = head;

    //hubungkan head dan tail secara langsung
    tail->prev = head;
    head->next = tail;

    //update head_ref ke tail
    head_ref = tail;
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

void insertEnd(Node *&head_ref, int data)
{
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main()
{
    Node *head = nullptr;

    // Buat list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    // Expected output: 5 2 3 4 1
    printList(head);

    return 0;
}