#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct penerbangan {
    string kodePenerbangan;
    string tujuan;
    string status;
};

struct Node{
    penerbangan data;
    Node* next;
};

string nama, nim;
int kodeUnik = 0;
Node* head = nullptr;
Node* tail = nullptr;

string buatKode(){
    string kode3 = nim.substr(nim.size()-3);
    if (kodeUnik == 0){
        kodeUnik++;
        return "JT-" + kode3;
    }else{
        kodeUnik++;
        return "JT-" + kode3 + "-" + to_string(kodeUnik -1);
    }
}
void tambahJadwal(Node *&head, Node *&tail, const string &tujuan, const string &status)
{
    Node *newNode = new Node();
    newNode->data.kodePenerbangan = buatKode();
    newNode->data.tujuan = tujuan;
    newNode->data.status = status;
    newNode->next = nullptr;

    if (tail != nullptr)
    {
        tail->next = newNode;
    }
    else 
    {
        head = newNode;
    }
    tail = newNode;
    cout << "Jadwal penerbangan berhasil ditambahkan.\n";
    
}

void sisipkanJadwal(Node *&head, Node *&tail, const string &tujuan, const string &status, int posisi)
{
    Node *newNode = new Node();
    newNode->data.kodePenerbangan = buatKode();
    newNode->data.tujuan = tujuan;
    newNode->data.status = status;
    newNode->next = nullptr;

    if (posisi == 0) 
    {
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) 
        {
            tail = newNode;
        }
        cout << "Jadwal penerbangan berhasil disisipkan di posisi " << posisi << ".\n";
        return;
    }

    Node *current = head;
    for (int i = 0; i < posisi - 1 && current != nullptr; i++)
    {
        current = current->next;
    }

    if (current == nullptr) 
    {
        cout << "Posisi tidak valid. Jadwal penerbangan ditambahkan di akhir daftar.\n";
        if (tail != nullptr)
        {
            tail->next = newNode;
        }
        else 
        {
            head = newNode;
        }
        tail = newNode;
    }
    else 
    {
        newNode->next = current->next;
        current->next = newNode;
        if (newNode->next == nullptr) 
        {
            tail = newNode;
        }
        cout << "Jadwal penerbangan berhasil disisipkan di posisi " << posisi << ".\n";
    }

}

int PosisiSisip() {
    char lastDigit = nim[nim.size()-1]; 
    int angka = lastDigit - '0';        
    return angka + 1;                   
}

void hapusJadwalAwal(Node *&head, Node *&tail)
{
    if (head == nullptr) 
    {
        cout << "Tidak ada jadwal penerbangan untuk dihapus.\n";
        return;
    }

    Node *temp = head;
    head = head->next;
    if (head == nullptr) 
    {
        tail = nullptr;
    }
    delete temp;
    cout << "Jadwal penerbangan paling awal berhasil dihapus.\n";
}

void hapusJadwalTerakhir(Node *&head, Node *&tail) {
    if (head == nullptr) {  
        cout << "Tidak ada jadwal penerbangan untuk dihapus.\n";
        return;
    }

    if (head->next == nullptr) {  
        delete head;
        head = tail = nullptr;
        cout << "Jadwal penerbangan terakhir berhasil dihapus.\n";
        return;
    }

    Node *current = head;
    while (current->next != tail) { 
        current = current->next;
    }

    delete tail;
    tail = current;
    tail->next = nullptr;
    cout << "Jadwal penerbangan terakhir berhasil dihapus.\n";
}


void updateStatus(Node *head, const string &kodePenerbangan) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal penerbangan.\n";
        return;
    }

    Node *current = head;
    while (current != nullptr) {
        if (current->data.kodePenerbangan == kodePenerbangan) {
            cout << "Ditemukan: " << current->data.kodePenerbangan 
                 << " | " << current->data.tujuan 
                 << " | Status lama: " << current->data.status << "\n";

            string statusBaru;
            cout << "Masukkan status baru: ";
            cin.ignore();  
            getline(cin, statusBaru);

            current->data.status = statusBaru;
            cout << "Status berhasil diperbarui.\n";
            return;
        }
        current = current->next;
    }
    cout << "Kode penerbangan tidak ditemukan.\n";
}

void tampilkanJadwal(Node *head) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal penerbangan.\n";
        return;
    }

    cout << "\n---------------------------------------------\n";
    cout << "*             JADWAL PENERBANGAN           *\n";
    cout << "---------------------------------------------\n";
    cout << "* " << left << setw(12) << "Kode"
         << "| " << setw(18) << "Tujuan"
         << "| " << setw(18) << "Status" << " *\n";
    cout << "---------------------------------------------\n";

    Node *current = head;
    while (current != nullptr) {
        cout << "* " << left << setw(12) << current->data.kodePenerbangan
             << "| " << setw(18) << current->data.tujuan
             << "| " << setw(18) << current->data.status << " *\n";
        current = current->next;
    }

    cout << "---------------------------------------------\n\n";
}



void menu(){
    int pilihan;
    do{
        cout << "\n********** FLIGHT RUNWAY SYSTEM **********\n";
        cout << " User : " << nama << " | NIM : " << nim << "\n";
        cout << "******************************************\n";
        cout << " 1) Tambah Jadwal Penerbangan\n";
        cout << " 2) Sisipkan Jadwal Penerbangan\n";
        cout << " 3) Hapus Jadwal Paling Awal\n";
        cout << " 4) Hapus Jadwal Paling Akhir\n";
        cout << " 5) Update Status Penerbangan\n";
        cout << " 6) Tampilkan Semua Jadwal\n";
        cout << " 0) Keluar\n";
        cout << "******************************************\n";
        cout << " Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            string tujuan, status;
            cout << "Masukkan tujuan: ";
            getline(cin, tujuan);
            cout << "Masukkan status: ";
            getline(cin, status);
            tambahJadwal(head, tail, tujuan, status);
        } 
        else if (pilihan == 2) {
            string tujuan, status;
            cout << "Masukkan tujuan: ";
            getline(cin, tujuan);
            cout << "Masukkan status: ";
            getline(cin, status);
            int posisi = PosisiSisip();
            sisipkanJadwal(head, tail, tujuan, status, posisi);
        } 
        else if (pilihan == 3) {
            hapusJadwalAwal(head, tail);
        }

        else if (pilihan == 4) {
            hapusJadwalTerakhir(head, tail);
        }
        else if (pilihan == 5) {
            string kode;
            cout << "Masukkan kode penerbangan: ";
            cin >> kode;
            updateStatus(head, kode);
        } 
        else if (pilihan == 6) {
            tampilkanJadwal(head);
        } 
        else if (pilihan == 0) {
            cout << "Keluar dari program.\n";
        } 
        else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);
}
int main(){
    cout << "Masukkan Nama Anda: ";
    getline (cin, nama);
    cout << "Masukkan NIM Anda: "; 
    getline (cin, nim);
    menu();

    return 0;
}
