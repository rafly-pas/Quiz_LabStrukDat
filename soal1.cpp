#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nim;
    string nama;
    int nilai;
    Node* next;
};

void insertionSort(int* data, int n) {
    for (int i = 1; i < n; i++) {
        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

Node* linearSearch(Node* head, string targetNIM) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->nim == targetNIM) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

int binarySearch(int* data, int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (data[mid] == target) {
            return mid;
        } else if (target < data[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    system("cls");
    int n;
    cout << "=== SISTEM PENGELOLAAN NILAI MAHASISWA ===" << endl;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    if (n <= 0) {
        cout << "Jumlah mahasiswa tidak valid!" << endl;
        return 0;
    }

    int* daftarNilai = new int[n];

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        Node* baru = new Node();
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "NIM   : "; cin >> baru->nim;
        cin.ignore();
        cout << "Nama  : "; getline(cin, baru->nama);
        cout << "Nilai : "; cin >> baru->nilai;
        baru->next = nullptr;

        if (head == nullptr) {
            head = tail = baru;
        } else {
            tail->next = baru;
            tail = baru;
        }

        daftarNilai[i] = baru->nilai;
    }

    cout << "\n=== DATA MAHASISWA ===" << endl;
    Node* temp = head;
    while (temp != nullptr) {
        cout << "NIM: " << temp->nim << " | Nama: " << temp->nama << " | Nilai: " << temp->nilai << endl;
        temp = temp->next;
    }

    insertionSort(daftarNilai, n);
    cout << "\n=== HASIL PENGURUTAN NILAI (INSERTION SORT) ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << daftarNilai[i];
        if (i < n - 1) cout << ", ";
    }
    cout << endl;

    string cariNIM;
    cout << "\nMasukkan NIM yang dicari (Linear Search): ";
    cin >> cariNIM;
    Node* hasilNIM = linearSearch(head, cariNIM);
    if (hasilNIM != nullptr) {
        cout << "Mahasiswa ditemukan -> NIM: " << hasilNIM->nim
             << " | Nama: " << hasilNIM->nama
             << " | Nilai: " << hasilNIM->nilai << endl;
    } else {
        cout << "Mahasiswa dengan NIM " << cariNIM << " tidak ditemukan." << endl;
    }

    int cariNilai;
    cout << "\nMasukkan nilai yang dicari (Binary Search): ";
    cin >> cariNilai;
    int hasilNilai = binarySearch(daftarNilai, n, cariNilai);
    if (hasilNilai != -1) {
        cout << "Nilai " << cariNilai << " ditemukan pada indeks ke-" << hasilNilai << endl;
    } else {
        cout << "Nilai " << cariNilai << " tidak ditemukan." << endl;
    }

    delete[] daftarNilai;
    while (head != nullptr) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
    }

    return 0;
}