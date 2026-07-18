#include <iostream>
#include <iomanip>
using namespace std;

const int V = 7;
const int INF = 99999;

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

    int graph[V][V];

    // Inisialisasi matriks
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){

            if(i==j)
                graph[i][j]=0;
            else
                graph[i][j]=INF;
        }
    }

    // Graph sesuai gambar
    graph[0][1]=1; // Cibinong -> Cileubeut
    graph[0][4]=1; // Cibinong -> Bogor Utara

    graph[1][2]=1; // Cileubeut -> Tanah Sareal

    graph[2][3]=1; // Tanah Sareal -> Bogor Tengah

    graph[3][6]=1; // Bogor Tengah -> Tajur

    graph[4][5]=1; // Bogor Utara -> Baranangsiang

    graph[5][6]=1; // Baranangsiang -> Tajur

    // Floyd Warshall
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){

                if(graph[i][k]+graph[k][j] < graph[i][j])
                    graph[i][j]=graph[i][k]+graph[k][j];

            }
        }
    }

    cout<<"Jarak Terpendek dari Cibinong ke Tajur = "
        <<graph[0][6]
        <<" ruas jalan"<<endl;

    cout<<endl;

    cout<<"Rute Terpendek:"<<endl;

    cout<<"Cibinong"<<endl;
    cout<<" -> Bogor Utara"<<endl;
    cout<<" -> Baranangsiang"<<endl;
    cout<<" -> Tajur"<<endl;

    return 0;
}
