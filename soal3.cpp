#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
private:
    int numberVertex;
    vector<vector<int>> adjMatrix;
    char namaVertex[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

    void dfsUntil(int currentVertex, vector<bool>& visited) {
        visited[currentVertex] = true;
        cout << namaVertex[currentVertex] << " ";

        for (int i = 0; i < numberVertex; i++) {
            if (adjMatrix[currentVertex][i] != 0 && !visited[i]) {
                dfsUntil(i, visited);
            }
        }
    }

    void cetakRute(vector<int>& parent, int tujuan) {
        if (parent[tujuan] == -1) {
            cout << namaVertex[tujuan];
            return;
        }
        cetakRute(parent, parent[tujuan]);
        cout << " -> " << namaVertex[tujuan];
    }

public:
    Graph(int banyakTitik) {
        numberVertex = banyakTitik;
        adjMatrix.resize(numberVertex, vector<int>(numberVertex, 0));
    }

    void addEdge(int i, int j, int weight) {
        if (i >= 0 && i < numberVertex && j >= 0 && j < numberVertex) {
            adjMatrix[i][j] = weight;
            adjMatrix[j][i] = weight;
        } else {
            cout << "Index invalid" << endl;
        }
    }

    void printAdjMatrix() {
        cout << "Adjacency Matrix:" << endl;
        cout << "  A B C D E F" << endl;
        for (int i = 0; i < numberVertex; i++) {
            cout << namaVertex[i] << " ";
            for (int j = 0; j < numberVertex; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void bfs(int startVertex) {
        vector<bool> visited(numberVertex, false);
        queue<int> titikVisit;

        visited[startVertex] = true;
        titikVisit.push(startVertex);

        cout << "Hasil penelusuran BFS dari " << namaVertex[startVertex] << ": ";
        while (!titikVisit.empty()) {
            int currentVertex = titikVisit.front();
            titikVisit.pop();
            cout << namaVertex[currentVertex] << " ";

            for (int i = 0; i < numberVertex; i++) {
                if (adjMatrix[currentVertex][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    titikVisit.push(i);
                }
            }
        }
        cout << endl;
    }

    void dfs(int startVertex) {
        vector<bool> visited(numberVertex, false);
        cout << "Hasil penelusuran DFS dari " << namaVertex[startVertex] << ": ";
        dfsUntil(startVertex, visited);
        cout << endl;
    }

    void dijkstra(int source, int destination) {
        vector<int> distance(numberVertex, INT_MAX);
        vector<bool> visited(numberVertex, false);
        vector<int> parent(numberVertex, -1);

        distance[source] = 0;

        for (int i = 0; i < numberVertex; i++) {
            int u = -1;

            for (int j = 0; j < numberVertex; j++) {
                if (!visited[j] && (u == -1 || distance[j] < distance[u])) {
                    u = j;
                }
            }

            if (u == -1 || distance[u] == INT_MAX)
                break;

            visited[u] = true;

            for (int v = 0; v < numberVertex; v++) {
                if (adjMatrix[u][v] != 0 && !visited[v]) {
                    int newDistance = distance[u] + adjMatrix[u][v];
                    if (newDistance < distance[v]) {
                        distance[v] = newDistance;
                        parent[v] = u;
                    }
                }
            }
        }

        cout << "\n=== HASIL DIJKSTRA (" << namaVertex[source] << " ke " << namaVertex[destination] << ") ===" << endl;
        if (distance[destination] == INT_MAX) {
            cout << "Rute tidak terjangkau." << endl;
        } else {
            cout << "Rute terpendek : ";
            cetakRute(parent, destination);
            cout << endl;
            cout << "Total jarak    : " << distance[destination] << endl;
        }
    }
};

int konversiVertex(char v) {
    v = toupper(v);
    if (v >= 'A' && v <= 'F') {
        return v - 'A';
    }
    return -1;
}

int main() {
    system("cls");
    Graph graphh(6);

    graphh.addEdge(0, 1, 4); 
    graphh.addEdge(0, 2, 2); 
    graphh.addEdge(1, 2, 1); 
    graphh.addEdge(1, 3, 5); 
    graphh.addEdge(1, 4, 3); 
    graphh.addEdge(2, 3, 8); 
    graphh.addEdge(2, 4, 6); 
    graphh.addEdge(3, 4, 2); 
    graphh.addEdge(3, 5, 4); 
    graphh.addEdge(4, 5, 3); 

    cout << "=== SISTEM PENCARIAN RUTE DI LINGKUNGAN KAMPUS ===" << endl;
    graphh.printAdjMatrix();
    cout << endl;

    char awalChar, tujuanChar;
    cout << "Masukkan vertex awal (A-F)   : ";
    cin >> awalChar;
    cout << "Masukkan vertex tujuan (A-F) : ";
    cin >> tujuanChar;

    int awal = konversiVertex(awalChar);
    int tujuan = konversiVertex(tujuanChar);

    if (awal == -1 || tujuan == -1) {
        cout << "Input vertex tidak valid! Gunakan huruf A sampai F." << endl;
        return 0;
    }

    cout << endl;
    graphh.bfs(awal);
    graphh.dfs(awal);
    graphh.dijkstra(awal, tujuan);

    return 0;
}