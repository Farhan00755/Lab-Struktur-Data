#include <iostream>              // Mengimpor library cpp
#include <vector>                // Mengimpor library vector
using namespace std;             // Menggunakan namespace std agar tidak perlu menulis std::

// Fungsi untuk menggabungkan dua bagian array yang sudah terurut
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;     // Panjang bagian kiri
    int n2 = right - mid;        // Panjang bagian kanan

    vector<int> L(n1), R(n2);    // Membuat array sementara untuk kiri dan kanan

    for (int i = 0; i < n1; i++) // Menyalin data ke array kiri
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) // Menyalin data ke array kanan
        R[j] = arr[mid + 1 + j];

    int i = 0;                   // Indeks untuk array kiri
    int j = 0;                   // Indeks untuk array kanan
    int k = left;                // Indeks untuk array utama

    // Menggabungkan kedua array sementara ke array utama secara terurut
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {      // Jika elemen kiri lebih kecil atau sama
            arr[k] = L[i];       // Masukkan elemen kiri ke array utama
            i++;                 // Pindah ke elemen berikutnya di kiri
        } else {
            arr[k] = R[j];       // Masukkan elemen kanan ke array utama
            j++;                 // Pindah ke elemen berikutnya di kanan
        }
        k++;                     // Pindah ke posisi berikutnya di array utama
    }

    // Jika masih ada sisa di array kiri, masukkan semuanya
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Jika masih ada sisa di array kanan, masukkan semuanya
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi utama merge sort (rekursif)
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)           // Basis rekursi: jika hanya satu elemen, selesai
        return;

    int mid = left + (right - left) / 2; // Cari titik tengah

    mergeSort(arr, left, mid);           // Urutkan bagian kiri
    mergeSort(arr, mid + 1, right);      // Urutkan bagian kanan

    merge(arr, left, mid, right);        // Gabungkan kedua bagian yang sudah terurut
}

// Fungsi untuk mencetak isi array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) { // Iterasi setiap elemen array
        cout << arr[i] << " ";             // Cetak elemen
    }
    cout << endl;                          // Pindah baris setelah selesai
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: "; // Minta jumlah elemen dari user
    cin >> n;                                // Input jumlah elemen

    vector<int> data(n);                     // Buat vector dengan n elemen
    cout << "Masukkan elemen-elemen data: "; // Minta user memasukkan elemen
    for (int i = 0; i < n; i++) {
        cin >> data[i];                      // Input setiap elemen
    }

    cout << "Array sebelum diurutkan: ";     // Tampilkan array sebelum diurutkan
    printArray(data);

    mergeSort(data, 0, n - 1);               // Urutkan array dengan merge sort

    cout << "Array setelah diurutkan: ";     // Tampilkan array setelah diurutkan
    printArray(data);

    return 0;
}