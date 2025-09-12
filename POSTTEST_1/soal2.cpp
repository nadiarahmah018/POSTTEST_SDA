#include <iostream>
using namespace std;

int main() {
    int matriks[3][3] = {
        {6, 13, 12},
        {11, 18, 4},
        {17, 9, 15}
    };

    int jumlah = 0;
    for (int i = 0; i < 3; i++) {
        if (i % 2 == 0) { 
            for (int j = 0; j < 3; j++) {
                jumlah += matriks[i][j];
            }
        }
    }

    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Jumlah elemen pada baris genap = " << jumlah << endl;

    return 0;
}
