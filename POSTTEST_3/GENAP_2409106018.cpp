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
    Node* prev;
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
    newNode->prev = tail;

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

    if (posisi == 0) 
    {
        newNode->next = head;
        newNode->prev = nullptr;
        head = newNode;
        if (head != nullptr) head->prev = newNode;
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

    if (current == nullptr) {
        newNode->next = nullptr;
        newNode->prev = tail;
        if (tail != nullptr)
        {
            tail->next = newNode;
        }
        else 
        {
            head = newNode;
        }
        tail = newNode;
        cout << "Posisi tidak valid. Jadwal penerbangan ditambahkan di akhir daftar.\n";
    }
    else 
    {
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != nullptr) current->next->prev = newNode;
        else tail = newNode;
        current->next = newNode;
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
    if (head != nullptr)
        head->prev = nullptr;
    else
        tail = nullptr;
    delete temp;
        cout << "Jadwal penerbangan paling awal berhasil dihapus.\n";
}

void hapusJadwalTerakhir(Node *&head, Node *&tail) {
    if ( tail == nullptr) {  
        cout << "Tidak ada jadwal penerbangan untuk dihapus.\n";
        return;
    }
    Node *temp = tail;
    tail = tail->prev;

    if (tail != nullptr)
        tail->next = nullptr;
    else {
        head = nullptr;
    delete temp;
        cout << "Jadwal penerbangan terakhir berhasil dihapus.\n";
        return;
    }

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

    cout << "********************************************************\n";
    cout << "*                  JADWAL PENERBANGAN                  *\n";
    cout << "********************************************************\n";

    cout << "* " << left << setw(12) << "Kode"
         << "| " << setw(18) << "Tujuan"
         << "| " << setw(18) << "Status" << " *\n";

    cout << "********************************************************\n";

    Node *current = head;
    while (current != nullptr) {
        cout << "* " << left << setw(12) << current->data.kodePenerbangan
             << "| " << setw(18) << current->data.tujuan
             << "| " << setw(18) << current->data.status << " *\n";
        current = current->next;
    }

    cout << "********************************************************\n\n";
}

void tampilkanJadwalBelakang(Node* tail) {
    if (tail == nullptr) {
        cout << "Tidak ada jadwal penerbangan.\n";
        return;
    }

    cout << "********************************************************\n";
    cout << "*           JADWAL PENERBANGAN(DARI BELAKANG)          *\n";
    cout << "********************************************************\n";

    cout << "* " << left << setw(12) << "Kode"
         << "| " << setw(18) << "Tujuan"
         << "| " << setw(18) << "Status" << " *\n";

    cout << "********************************************************\n";

    Node* current = tail;
    while (current != nullptr) {
        cout << "* " << left << setw(12) << current->data.kodePenerbangan
             << "| " << setw(18) << current->data.tujuan
             << "| " << setw(18) << current->data.status << " *\n";
        current = current->prev;
    }

    cout << "********************************************************\n\n";
}

void cariJadwal(Node* head, const string& keyword) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal penerbangan.\n";
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        if (current->data.kodePenerbangan == keyword || current->data.tujuan == keyword) {
            cout << "\nDetail Jadwal Ditemukan:\n";
            cout << "-----------------------------------\n";
            cout << "Kode   : " << current->data.kodePenerbangan << "\n";
            cout << "Tujuan : " << current->data.tujuan << "\n";
            cout << "Status : " << current->data.status << "\n";
            cout << "-----------------------------------\n";
            return;
        }
        current = current->next;
    }
    cout << "Data dengan kata kunci \"" << keyword << "\" tidak ditemukan.\n";
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
        cout << " 7) Tampilkan Semua Jadwal dari Belakang\n";
        cout << " 8) Cari Jadwal Berdasarkan Kode/Tujuan\n";
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

        else if (pilihan == 7) {
            tampilkanJadwalBelakang(tail);
        }
        else if (pilihan == 8) {
            string key;
            cout << "Masukkan kode penerbangan atau tujuan: ";
            getline(cin, key);
            cariJadwal(head, key);
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
