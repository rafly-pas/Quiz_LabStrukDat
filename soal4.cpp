#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 20;

class HashTable {
private:
    vector<pair<long long, string>> table;
    vector<int> status;

    int hash1(long long key) {
        return key % 20;
    }

    int hash2(long long key) {
        return 19 - (key % 19);
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
        status.resize(TABLE_SIZE, 0);
    }

    void insert(long long key, string value) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;

        int deletedIndex = -1;
        int jumlahCollision = 0;

        while (true) {
            if (status[index] == 1 && table[index].first == key) {
                table[index].second = value;
                cout << "NIM " << key << " sudah ada, nama diperbarui di indeks [" << index << "]." << endl;
                return;
            }

            if (status[index] == 2 && deletedIndex == -1) {
                deletedIndex = index;
            }

            if (status[index] == 0) {
                if (deletedIndex != -1) {
                    index = deletedIndex;
                }
                table[index] = make_pair(key, value);
                status[index] = 1;
                cout << "Data berhasil disimpan di indeks [" << index << "]";
                if (jumlahCollision > 0) {
                    cout << " (terjadi " << jumlahCollision << "x collision)";
                }
                cout << "." << endl;
                return;
            }

            jumlahCollision++;
            index = (index + step) % TABLE_SIZE;

            if (index == initialIndex) {
                break;
            }
        }

        if (deletedIndex != -1) {
            table[deletedIndex] = make_pair(key, value);
            status[deletedIndex] = 1;
            cout << "Data berhasil disimpan di indeks bekas hapus [" << deletedIndex << "]." << endl;
        } else {
            cout << "Tabel penuh! Tidak dapat menyimpan data lagi." << endl;
        }
    }

    void search(long long key) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;

        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == key) {
                cout << "Data ditemukan di indeks [" << index << "] -> NIM: "
                     << table[index].first << " | Nama: " << table[index].second << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == initialIndex) {
                break;
            }
        }
        cout << "Data tidak ditemukan." << endl;
    }

    void remove(long long key) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;

        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == key) {
                status[index] = 2;
                cout << "Data NIM " << key << " (" << table[index].second << ") di indeks [" << index << "] berhasil dihapus." << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == initialIndex) {
                break;
            }
        }
        cout << "Data tidak ditemukan." << endl;
    }

    void display() {
        cout << "\n=== ISI HASH TABLE (SIZE = 20) ===" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " : ";

            if (status[i] == 1) {
                cout << table[i].first << " - " << table[i].second;
            } else if (status[i] == 2) {
                cout << "DELETED";
            } else {
                cout << "EMPTY";
            }

            cout << endl;
        }
    }
};

int main() {
    system("cls");
    HashTable ht;

    int jumlahAwal;
    cout << "=== SISTEM PENGELOLAAN DATA MAHASISWA (DOUBLE HASHING) ===" << endl;
    cout << "Masukkan jumlah data mahasiswa yang ingin diinput (minimal 15, maksimal 20): ";
    cin >> jumlahAwal;

    for (int i = 0; i < jumlahAwal; i++) {
        long long nim;
        string nama;
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Masukkan NIM  : ";
        cin >> nim;
        cin.ignore();
        cout << "Masukkan Nama : ";
        getline(cin, nama);

        ht.insert(nim, nama);
    }

    int pilihan;
    do {
        cout << "\n=== MENU HASH TABLE MAHASISWA ===" << endl;
        cout << "1. Insert (Tambah Data Mahasiswa)" << endl;
        cout << "2. Search (Cari Mahasiswa berdasarkan NIM)" << endl;
        cout << "3. Remove (Hapus Mahasiswa berdasarkan NIM)" << endl;
        cout << "4. Display (Tampilkan Isi Hash Table)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            long long nim;
            string nama;
            cout << "Masukkan NIM  : ";
            cin >> nim;
            cin.ignore();
            cout << "Masukkan Nama : ";
            getline(cin, nama);
            ht.insert(nim, nama);
        } else if (pilihan == 2) {
            long long nim;
            cout << "Masukkan NIM yang dicari: ";
            cin >> nim;
            ht.search(nim);
        } else if (pilihan == 3) {
            long long nim;
            cout << "Masukkan NIM yang akan dihapus: ";
            cin >> nim;
            ht.remove(nim);
        } else if (pilihan == 4) {
            ht.display();
        } else if (pilihan != 0) {
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}