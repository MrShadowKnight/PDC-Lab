#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_VERTICES = 100;
int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

void graphColoring(int n) {
    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }

    color[0] = 0;

    for (int u = 1; u < n; u++) {
        bool used[MAX_VERTICES] = { false };

        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1 && color[v] != -1) {
                used[color[v]] = true;
            }
        }

        int c;
        for (c = 0; c < n; c++) {
            if (!used[c]) {
                break;
            }
        }

        color[u] = c;
    }
}

int main() {
    ifstream inputFile("in.txt");

    if (!inputFile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    int n, m;
    inputFile >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        inputFile >> u >> v;
        u--; v--;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    inputFile.close();

    graphColoring(n);

    int numColors = *max_element(color, color + n) + 1;
    cout << "Minimum number of colors: " << numColors << endl;
    cout << "Vertex colors:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i + 1 << ": Color " << color[i] + 1 << endl;
    }

    return 0;
}