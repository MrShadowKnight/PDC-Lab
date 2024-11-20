#include <iostream>
#include <vector>

using namespace std;

// Функція для обчислення факторіалу
long long factorial(int x) {
    long long result = 1;
    for (int i = 1; i <= x; ++i) {
        result *= i;
    }
    return result;
}

void calculateStirlingAndBell(int n) {
    vector<vector<long long>> stirling(n + 1, vector<long long>(n + 1, 0));
    vector<long long> bell(n + 1, 0);

    // Початкові значення
    stirling[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        stirling[i][0] = 0;
        stirling[i][i] = 1;
    }

    // Обчислення чисел Стірлінга
    for (int i = 2; i <= n; ++i) {
        for (int k = 1; k < i; ++k) {
            stirling[i][k] = stirling[i - 1][k - 1] + k * stirling[i - 1][k];
        }
    }

    // Обчислення чисел Белла
    for (int i = 1; i <= n; ++i) {
        for (int k = 1; k <= i; ++k) {
            bell[i] += stirling[i][k];
        }
    }

    // Виведення таблиці
    cout << "Таблиця чисел Стірлінга другого роду:" << endl;
    for (int i = 1; i <= n; ++i) {
        for (int k = 1; k <= i; ++k) {
            cout << stirling[i][k] << "\t";
        }
        cout << endl;
    }

    cout << "Числа Белла:" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << "B(" << i << ") = " << bell[i] << endl;
    }
}
// Основна функція
int main() {
    int n = 10, r = 8;
    long long arrangements = factorial(n) / factorial(n - r);

    cout << "Кількість розміщень без повторень з " << n << " елементів по " << r << ": " << arrangements << endl;
    int variant = 10;
    int v = variant + 5; // n = і + 5, де і - номер варіанту

    calculateStirlingAndBell(v);
    return 0;
}
