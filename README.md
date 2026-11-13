# Quiz_LabStrukDat

Nama: Rafly Syahputra
Nim : 251401122
Lab : 4 Stuktur Data

Deskripsi soal 1: Program ini dipakai buat mencatat data mahasiswa (NIM, nama, nilai), mengurutkan nilai mereka dari yang paling kecil sampai paling besar, serta mencari data mahasiswa berdasarkan NIM atau mencari posisi nilai tertentu.
Struktur Program:
1. struct Node: Wadah untuk menyimpan satu data mahasiswa (NIM, nama, nilai) beserta pointer next untuk menyambungkan ke data berikutnya (Single Linked List).
2. insertionSort(): Fungsi untuk mengurutkan kumpulan nilai di dalam Dynamic Array dari kecil ke besar.
3. linearSearch(): Fungsi untuk mengecek data mahasiswa satu per satu di Linked List sampai ketemu NIM yang dicari.
4. binarySearch(): Fungsi untuk mencari nilai tertentu di array yang sudah terurut dengan cara membagi dua area pencarian biar lebih cepat.
5. main(): Bagian utama tempat pengguna menginput jumlah serta biodata mahasiswa, lalu program otomatis menampilkan seluruh data, hasil urutan nilai, dan menjalankan fitur pencarian.
Cara menjalankan program:
1. Buka terminal/CMD, compile program dengan perintah: g++ soal1.cpp -o soal1
2. Jalankan programnya: ./soal1 (di Windows cukup ketik soal1).
3. Masukkan jumlah mahasiswa yang mau diinput, lalu ketikkan NIM, Nama, dan Nilainya satu per satu.
4. Program akan langsung menampilkan semua data dan urutan nilainya. Setelah itu, tinggal ketikkan NIM dan nilai yang ingin dicari saat diminta.

Deskripsi soal 2: Program ini mensimulasikan sistem perpustakaan sederhana. Ada sistem antrean untuk mahasiswa yang mau meminjam buku (siapa cepat dia dapat), tumpukan riwayat buku yang baru dikembalikan, serta penyimpanan katalog ID buku supaya gampang dicari.
Struktur Program: 
1. struct NodeQueue & fungsi enqueue() / dequeue(): Mengatur antrean peminjaman buku memakai konsep Queue (FIFO — yang duluan antre, dilayani duluan).
2. struct NodeStack & fungsi pushStack(): Mencatat riwayat pengembalian buku memakai konsep Stack (LIFO — buku yang paling terakhir dikembalikan muncul paling atas).
3. struct NodeBST & fungsi tambah(), cariBST(), preOrder(), inOrder(), postOrder(): Menyimpan ID buku ke dalam Binary Search Tree (BST) supaya pencarian ID buku cepat dan bisa ditampilkan dalam tiga urutan pembacaan (traversal).
4. main(): Menyediakan menu interaktif berulang (do-while) agar pengguna bisa memilih aksi tambah antrean, proses peminjaman, pengembalian buku, hingga melihat isi BST.
Cara menjalankan program:
1. Compile program: g++ soal2.cpp -o soal2
2. Jalankan program: ./soal2 (atau soal2 di Windows).
3. Pilih angka menu dari 1 sampai 6 sesuai kebutuhan (misalnya tekan 1 untuk daftar antrean pinjam, 2 untuk memproses peminjaman, 3 untuk mengembalikan buku, atau 6 untuk melihat semua laporan antrean, riwayat, dan urutan BST).
4. Ketik 0 jika sudah selesai.

Deskripsi soal 3: Program ini berfungsi seperti peta kampus mini yang punya 6 titik lokasi (A sampai F) lengkap dengan jarak antar-lokasinya. Program bisa menelusuri semua lokasi yang terhubung dan mencarikan jalur paling singkat dari titik awal ke titik tujuan.
Struktur program:
1. class Graph: Kelas utama yang menyimpan peta hubungan antar-lokasi menggunakan matriks 2 dimensi (Adjacency Matrix) beserta bobot jaraknya.
2. addEdge() & printAdjMatrix(): Mengisi jarak antar-dua lokasi sesuai tabel soal dan menampilkan tabel matriksnya ke layar.
3. bfs() & dfs(): Dua metode untuk menelusuri seluruh titik kampus (BFS menyebar melebar per level, sedangkan DFS menelusuri satu jalur sampai mentok dulu).
4. dijkstra() & cetakRute(): Algoritma utama untuk menghitung jarak terpendek dari titik awal ke tujuan pilihan pengguna sekaligus menampilkan urutan jalan yang harus dilewati.
5. main(): Menyiapkan data jalur kampus, meminta pengguna mengetik huruf titik awal dan tujuan (A–F), lalu mencetak rute terpendeknya.
Cara menjalankan program:
1. Compile program: g++ soal3.cpp -o soal3
2. Jalankan program: ./soal3 (atau soal3 di Windows).
3. Program akan menampilkan matriks jarak antar-lokasi terlebih dahulu.
4. Ketik satu huruf untuk lokasi awal (misalnya A) dan tekan Enter, lalu ketik huruf lokasi tujuan (misalnya F).
5. Hasil penelusuran BFS, DFS, serta jalur terpendek dan total jaraknya akan langsung muncul.

Deskripsi soal 4: Program ini menyimpan data NIM dan nama mahasiswa ke dalam tabel berukuran 20 slot menggunakan teknik Hash Table. Jika ada dua NIM yang mendapat nomor slot yang sama (collision), program otomatis mencarikan slot kosong lain menggunakan rumus Double Hashing.
Struktur program:
1. class HashTable: Menyimpan array pasangan data (NIM, Nama) berukuran 20 slot serta penanda status tiap slot (EMPTY, OCCUPIED, atau DELETED).
2. hash1() & hash2(): Dua rumus matematika untuk menentukan posisi indeks penyimpanan data dan langkah lompatan saat terjadi tabrakan (collision).
3. insert(), search(), remove(), & display(): Empat fungsi utama untuk menambah data mahasiswa baru, mencari nama berdasarkan NIM, menghapus data (menandai slot jadi DELETED), dan menampilkan seluruh isi tabel dari indeks 0 sampai 19.
4. main(): Meminta pengguna menginput data mahasiswa di awal (minimal 15 data), lalu membuka menu interaktif untuk menambah, mencari, menghapus, atau melihat isi tabel.
Cara menjalankan program:
1. Compile program: g++ soal4.cpp -o soal4
2. Jalankan program: ./soal4 (atau soal4 di Windows).
3. Masukkan jumlah data awal yang mau diinput (misalnya ketik 15), lalu masukkan NIM dan Nama masing-masing mahasiswa.
4. Setelah input awal selesai, pilih menu 1 untuk tambah data, 2 untuk cari NIM, 3 untuk hapus data, 4 untuk melihat seluruh isi 20 slot tabel, atau 0 untuk keluar.
