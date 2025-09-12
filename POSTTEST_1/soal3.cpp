#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {

    Mahasiswa mhs[4];

    cout << "Masukkan data 4 mahasiswa:\n";
    for (int i = 0; i < 4; i++) {
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "Nama : ";
        getline(cin, mhs[i].nama);
        cout << "NIM  : ";
        getline(cin, mhs[i].nim);
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cin.ignore(); 
    }

//mengurutkan IPK secara asccending
    for (int i = 0; i < 4-1; i++) {
        for (int j = i+1; j < 4; j++) {
            if (mhs[i].ipk > mhs[j].ipk) {
                Mahasiswa temp = mhs[i];
                mhs[i] = mhs[j];
                mhs[j] = temp;
            }
        }
    }

    cout << "\nData Mahasiswa setelah diurutkan (berdasarkan IPK ascending):\n";
    for (int i = 0; i < 4; i++) {
        cout << i+1 << ". Nama: " << mhs[i].nama 
             << ", NIM: " << mhs[i].nim 
             << ", IPK: " << mhs[i].ipk << endl;
    }

    return 0;
}
