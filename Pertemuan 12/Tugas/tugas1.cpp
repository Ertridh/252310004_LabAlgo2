#include <iostream>
#include <iomanip>
using namespace std;

const int V = 7;
const int INF = 99999;

// Nama node
string kota[V] = {
    "Cibinong",
    "Cileubeut",
    "Tanah Sareal",
    "Bogor Tengah",
    "Bogor Utara",
    "Baranangsiang",
    "Tajur"
};

int main() {

    int dist[V][V];
    int next[V][V];

    // Inisialisasi matriks
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){

            if(i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;

            next[i][j] = -1;
        }
    }

    // Membuat graph sesuai soal
    dist[0][1] = 1;
    next[0][1] = 1;

    dist[0][4] = 1;
    next[0][4] = 4;

    dist[1][2] = 1;
    next[1][2] = 2;

    dist[2][3] = 1;
    next[2][3] = 3;

    dist[3][6] = 1;
    next[3][6] = 6;

    dist[4][5] = 1;
    next[4][5] = 5;

    dist[5][6] = 1;
    next[5][6] = 6;

    // Floyd-Warshall
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){

                if(dist[i][k] != INF &&
                   dist[k][j] != INF &&
                   dist[i][k] + dist[k][j] < dist[i][j]){

                    dist[i][j] = dist[i][k] + dist[k][j];

                    // Simpan jalur
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    int start = 0;   // Cibinong
    int tujuan = 6;  // Tajur

    cout << "Shortest distance from "
         << kota[start]
         << " to "
         << kota[tujuan]
         << " = "
         << dist[start][tujuan]
         << endl;

    cout << "Path : ";

    if(next[start][tujuan] == -1){
        cout << "Tidak ada jalur.";
        return 0;
    }

    int u = start;

    cout << kota[u];

    while(u != tujuan){

        u = next[u][tujuan];

        cout << " -> " << kota[u];
    }

    cout << endl;

    return 0;
}
