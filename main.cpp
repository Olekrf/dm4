#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int V = 7;
    const int INF = 1000000;
    char names[V] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    int dist[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }

    dist[0][1] = 17;
    dist[0][3] = 15;
    dist[1][2] = 10;
    dist[1][4] = 26;
    dist[2][4] = 16;
    dist[3][1] = 8;
    dist[3][5] = 6;
    dist[4][3] = 11;
    dist[4][6] = 7;
    dist[5][4] = 14;
    dist[6][5] = 19;


    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }


    cout << "Матриця найкоротших відстаней:\n   ";
    for (int i = 0; i < V; i++) {
        cout << setw(5) << names[i];
    }
    cout << "\n   -------------------------------------\n";

    for (int i = 0; i < V; i++) {
        cout << " " << names[i] << " |";
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << setw(5) << "INF";
            } else {
                cout << setw(5) << dist[i][j];
            }
        }
        cout << "\n";
    }

    cout << "\nНайкоротша віддаль від a до g: " << dist[0][6] << "\n";

    return 0;
}