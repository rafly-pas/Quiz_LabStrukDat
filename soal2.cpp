#include <iostream>
#include <string>
using namespace std;

struct NodeQueue {
    string namaMahasiswa;
    int idBuku;
    NodeQueue* next;
};

struct NodeStack {
    string namaMahasiswa;
    int idBuku;
    NodeStack* next;
};

struct NodeBST {
    int data;
    NodeBST* kiri;
    NodeBST* kanan;
};

void enqueue(NodeQueue*& front, NodeQueue*& rear, string nama, int idBuku) {
    NodeQueue* nodeBaru = new NodeQueue();
    nodeBaru->namaMahasiswa = nama;
    nodeBaru->idBuku = idBuku;
    nodeBaru->next = nullptr;

    if (front == nullptr) {
        front = rear = nodeBaru;
    } else {
        rear->next = nodeBaru;
        rear = nodeBaru;
    }
    cout << "Antrean ditambahkan: " << nama << " (ID Buku: " << idBuku << ")" << endl;
}

void dequeue(NodeQueue*& front, NodeQueue*& rear) {
    if (front == nullptr) {
        cout << "Antrean kosong!" << endl;
        return;
    }
    NodeQueue* hapus = front;
    cout << "Dequeue (Proses Pinjam): " << front->namaMahasiswa << " meminjam ID Buku " << front->idBuku << endl;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete hapus;
}

void tampilQueue(NodeQueue* front) {
    if (front == nullptr) {
        cout << "Antrean peminjaman kosong." << endl;
        return;
    }
    NodeQueue* temp = front;
    cout << "Isi Antrean (Front -> Rear): " << endl;
    while (temp != nullptr) {
        cout << "- " << temp->namaMahasiswa << " (ID Buku: " << temp->idBuku << ")" << endl;
        temp = temp->next;
    }
}

void pushStack(NodeStack*& top, string nama, int idBuku) {
    NodeStack* nodeBaru = new NodeStack();
    nodeBaru->namaMahasiswa = nama;
    nodeBaru->idBuku = idBuku;
    nodeBaru->next = top;
    top = nodeBaru;
    cout << "Buku ID " << idBuku << " dikembalikan oleh " << nama << " (masuk riwayat Stack)." << endl;
}

void tampilStack(NodeStack* top) {
    if (top == nullptr) {
        cout << "Riwayat pengembalian kosong." << endl;
        return;
    }
    NodeStack* temp = top;
    cout << "Riwayat Pengembalian Buku (Top / Terbaru -> Terlama): " << endl;
    while (temp != nullptr) {
        cout << "- ID Buku: " << temp->idBuku << " | Oleh: " << temp->namaMahasiswa << endl;
        temp = temp->next;
    }
}

NodeBST* tambah(NodeBST* root, int data) {
    if (root == NULL) {
        root = new NodeBST();
        root->data = data;
        root->kiri = NULL;
        root->kanan = NULL;
        return root;
    }

    if (data < root->data) {
        root->kiri = tambah(root->kiri, data);
    } else if (data > root->data) {
        root->kanan = tambah(root->kanan, data);
    }
    return root;
}

bool cariBST(NodeBST* root, int target) {
    if (root == NULL) return false;
    if (root->data == target) return true;
    if (target < root->data) return cariBST(root->kiri, target);
    return cariBST(root->kanan, target);
}

void preOrder(NodeBST* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(NodeBST* root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

void postOrder(NodeBST* root) {
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

int main() {
    system("cls");
    NodeQueue* front = nullptr;
    NodeQueue* rear = nullptr;
    NodeStack* top = nullptr;
    NodeBST* root = NULL;

    int daftarID[] = {50, 30, 70, 20, 40, 60, 80};
    for (int id : daftarID) {
        root = tambah(root, id);
    }

    int pilihan;
    do {
        cout << "\n=== SISTEM ANTREAN & PENGELOLAAN BUKU PERPUSTAKAAN ===" << endl;
        cout << "1. Tambah Antrean Peminjaman (Enqueue)" << endl;
        cout << "2. Proses Antrean Peminjaman (Dequeue)" << endl;
        cout << "3. Kembalikan Buku (Push ke Riwayat Stack)" << endl;
        cout << "4. Tambah ID Buku ke BST" << endl;
        cout << "5. Cari ID Buku di BST" << endl;
        cout << "6. Tampilkan Antrean, Riwayat Pengembalian, & Traversal BST" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string nama;
            int id;
            cin.ignore();
            cout << "Nama Mahasiswa: "; getline(cin, nama);
            cout << "ID Buku       : "; cin >> id;
            enqueue(front, rear, nama, id);
        } else if (pilihan == 2) {
            dequeue(front, rear);
        } else if (pilihan == 3) {
            string nama;
            int id;
            cin.ignore();
            cout << "Nama Mahasiswa: "; getline(cin, nama);
            cout << "ID Buku       : "; cin >> id;
            pushStack(top, nama, id);
        } else if (pilihan == 4) {
            int id;
            cout << "Masukkan ID Buku baru: "; cin >> id;
            root = tambah(root, id);
            cout << "ID Buku " << id << " berhasil dimasukkan ke BST." << endl;
        } else if (pilihan == 5) {
            int target;
            cout << "Masukkan ID Buku yang dicari: "; cin >> target;
            if (cariBST(root, target)) {
                cout << "ID Buku " << target << " DITEMUKAN di dalam BST." << endl;
            } else {
                cout << "ID Buku " << target << " TIDAK DITEMUKAN di dalam BST." << endl;
            }
        } else if (pilihan == 6) {
            cout << "\n--- Proses Antrean (Queue) ---" << endl;
            tampilQueue(front);

            cout << "\n--- Riwayat Pengembalian (Stack) ---" << endl;
            tampilStack(top);

            cout << "\n--- Isi BST (Traversal) ---" << endl;
            cout << "Pre-Order  : "; preOrder(root); cout << endl;
            cout << "In-Order   : "; inOrder(root); cout << endl;
            cout << "Post-Order : "; postOrder(root); cout << endl;
        }
    } while (pilihan != 0);

    return 0;
}