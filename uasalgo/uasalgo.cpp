#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_MAHASISWA = 100;
int NIM[MAX_MAHASISWA];
string nama[MAX_MAHASISWA];
string jurusan[MAX_MAHASISWA];
int tahunMasuk[MAX_MAHASISWA];
int jumlahMahasiswa = 0;

void tambahMahasiswa() {
    if (jumlahMahasiswa < MAX_MAHASISWA) {
        cout << "========== TAMBAH MAHASISWA ==========" << endl;
        cout << "NIM : ";
        cin >> NIM[jumlahMahasiswa];
        cin.ignore();
        cout << "Nama : ";
        getline(cin, nama[jumlahMahasiswa]);
        cout << "Jurusan : ";
        getline(cin, jurusan[jumlahMahasiswa]);
        cout << "Tahun Masuk: ";
        cin >> tahunMasuk[jumlahMahasiswa];
        cin.ignore();
        jumlahMahasiswa++;
        cout << "Mahasiswa berhasil ditambahkan!" << endl;
    }
    else {
        cout << "Kapasitas maksimum mahasiswa telah tercapai." << endl;
    }
}

void tampilkanSemuaMahasiswa() {
    if (jumlahMahasiswa == 0) {
        cout << "Belum ada data mahasiswa yang tersimpan." << endl;
    }
    else {
        cout << "========== SEMUA DATA MAHASISWA ==========" << endl;
        for (int i = 0; i < jumlahMahasiswa; i++) {
            cout << "NIM     : " << NIM[i] << endl;
            cout << "Nama    : " << nama[i] << endl;
            cout << "Jurusan : " << jurusan[i] << endl;
            cout << "Tahun Masuk: " << tahunMasuk[i] << endl;
            cout << endl;
        }
    }
}

void cariMahasiswaByNIM() {
    int nimCari;
    bool ditemukan = false;

    cout << "========== CARI MAHASISWA BERDASARKAN NIM ==========" << endl;
    cout << "Masukkan NIM yang ingin dicari: ";
    cin >> nimCari;

    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (NIM[i] == nimCari) {
            cout << "Mahasiswa ditemukan!" << endl;
            cout << "NIM     : " << NIM[i] << endl;
            cout << "Nama    : " << nama[i] << endl;
            cout << "Jurusan : " << jurusan[i] << endl;
            cout << "Tahun Masuk: " << tahunMasuk[i] << endl;
            cout << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Mahasiswa dengan NIM " << nimCari << " tidak ditemukan." << endl;
    }
}

void sortByTahunMasuk() {
    cout << "========== DATA MAHASISWA BERDASARKAN TAHUN MASUK ==========" << endl;
    if (jumlahMahasiswa == 0) {
        cout << "Belum ada data mahasiswa yang tersimpan." << endl;
    }
    else {
        // Menggunakan algoritma sorting (Bubble Sort) untuk mengurutkan berdasarkan tahun masuk
        for (int i = 0; i < jumlahMahasiswa - 1; i++) {
            for (int j = 0; j < jumlahMahasiswa - i - 1; j++) {
                if (tahunMasuk[j] > tahunMasuk[j + 1]) {
                    swap(NIM[j], NIM[j + 1]);
                    swap(nama[j], nama[j + 1]);
                    swap(jurusan[j], jurusan[j + 1]);
                    swap(tahunMasuk[j], tahunMasuk[j + 1]);
                }
            }
        }

        // Menampilkan data mahasiswa yang telah diurutkan
        for (int i = 0; i < jumlahMahasiswa; i++) {
            cout << "NIM     : " << NIM[i] << endl;
            cout << "Nama    : " << nama[i] << endl;
            cout << "Jurusan : " << jurusan[i] << endl;
            cout << "Tahun Masuk: " << tahunMasuk[i] << endl;
            cout << endl;
        }
    }
}

int main() {
    int pilihan;
    do {
        cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Tampilkan Semua Mahasiswa" << endl;
        cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
        cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            tambahMahasiswa();
            break;
        case 2:
            tampilkanSemuaMahasiswa();
            break;
        case 3:
            cariMahasiswaByNIM();
            break;
        case 4:
            sortByTahunMasuk();
            break;
        case 5:
            cout << "Terima kasih! Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

        cout << endl;
    } while (pilihan != 5);

    return 0;
}

//Jawaban:
//2. Algoritma yang digunakan adalah bubblesort untuk mengurutkan data Mahasiswa berdasarkan NIM dan Tahun Masuk, dan Algoritma linear search

//3. Perbedaan stack dan queue -> Stack = menyimpan data secara ditumpuk, Queue = menyimpan data di satu ujung dan menghapus ujung antrian lainnya

//4. Penerapan Function call S, Mempertahankan daftar undo untuk aplikasi, saat mengontrol operasi dalam sebuah sistem operasi, saat menggunakan prinsip LIFO

//5. a. 4 
// b. 