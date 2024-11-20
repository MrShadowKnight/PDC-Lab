#include <iostream>
#include <algorithm>

using namespace std;

void lexicographicPermutations(int n) {
    int* permutation = new int[n];
    for (int i = 0; i < n; ++i) {
        permutation[i] = i + 1;
    }

    cout << "permutation = {";
    for (int i = 0; i < n; ++i) {
        cout << permutation[i] << (i < n - 1 ? ", " : "");
    }
    cout << "}" << endl;

    while (next_permutation(permutation, permutation + n)) {
        cout << "permutation = {";
        for (int i = 0; i < n; ++i) {
            cout << permutation[i] << (i < n - 1 ? ", " : "");
        }
        cout << "}" << endl;
    }

    delete[] permutation;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    lexicographicPermutations(n);
    return 0;
}