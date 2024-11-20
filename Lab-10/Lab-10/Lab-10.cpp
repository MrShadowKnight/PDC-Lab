#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

const int INF = 1000000000;

void readGraph(const char* filename, int& n, int& m, int**& weightMatrix) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Помилка відкриття файлу для читання.\n";
        return;
    }

    inputFile >> n >> m;

    weightMatrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        weightMatrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            weightMatrix[i][j] = INF;
        }
    }

    for (int i = 0; i < m; ++i) {
        int v, u, w;
        inputFile >> v >> u >> w;
        weightMatrix[v - 1][u - 1] = w;
    }

    inputFile.close();
}

void printWeightMatrix(int** weightMatrix, int n, const char* outputFile) {
    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Помилка відкриття файлу для запису.\n";
        return;
    }

    cout << "Матриця ваг:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (weightMatrix[i][j] == INF) {
                cout << "INF ";
                outFile << "INF ";
            }
            else {
                cout << weightMatrix[i][j] << " ";
                outFile << weightMatrix[i][j] << " ";
            }
        }
        cout << "\n";
        outFile << "\n";
    }

    outFile.close();
}

void deleteMatrix(int** weightMatrix, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] weightMatrix[i];
    }
    delete[] weightMatrix;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n, m;
    int** weightMatrix = nullptr;
    const char* inputFilename = "in.txt";
    const char* outputFilename = "out.txt";

    readGraph(inputFilename, n, m, weightMatrix);
    printWeightMatrix(weightMatrix, n, outputFilename);
    deleteMatrix(weightMatrix, n);

    return 0;
}
