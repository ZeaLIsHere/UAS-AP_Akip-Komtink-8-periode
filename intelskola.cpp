#include <iostream>
#include <vector>
#include "cipher.h"

using namespace std;

int main() {
    string input;
    string operasi;
    int x;

    cout << "Masukkan pesan : ";
    getline(cin, input);

    cout << "Masukkan operasi (1=Enkripsi/2=Dekripsi): ";
    cin >> operasi;

    cout << "Masukkan nilai pergeseran (x) : ";
    cin >> x;

    vector<char> pesan(input.begin(), input.end());

    if (operasi == "Enkripsi" || operasi == "enkripsi" || operasi == "1" ) {
        enkripsiPesan(pesan, x);
        cout << "Pesan Terenkripsi : ";
    for (int i = 0; i < pesan.size(); ++i) {
        cout << pesan[i];
    }
    cout << endl;
    } else if (operasi == "Dekripsi" || operasi == "dekripsi" || operasi == "2") {
        dekripsiPesan(pesan, x);
        cout << "Pesan Terdekripsi : ";
    for (int i = 0; i < pesan.size(); ++i) {
        cout << pesan[i];
    }
    cout << endl;
    } else {
        cout << "Operasi tidak dikenali.\n";
        return 1;
    }
    return 0;
}