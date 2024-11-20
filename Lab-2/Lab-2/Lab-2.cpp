#include <iostream>
using namespace std;

// Функція для обчислення операції p → q (умовний перехід)
bool implies(bool p, bool q) {
    return !p || q;  // За визначенням умовного переходу
}

int main() {
    bool p, q, r;
    cout << "Таблиця істинності для (p → q) ^ (p → r)" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "p\tq\tr\tp → q\tp → r\t(p → q) ^ (p → r)" << endl;

    // Перебираємо всі можливі значення p, q, r (8 комбінацій)
    for (int i = 0; i < 2; ++i) {
        p = i;
        for (int j = 0; j < 2; ++j) {
            q = j;
            for (int k = 0; k < 2; ++k) {
                r = k;
                bool p_implies_q = implies(p, q);
                bool p_implies_r = implies(p, r);
                bool result = p_implies_q && p_implies_r;  // (p → q) ^ (p → r)

                // Виведення результатів
                cout << p << "\t" << q << "\t" << r << "\t"
                    << p_implies_q << "\t" << p_implies_r << "\t"
                    << result << endl;
            }
        }
    }


    return 0;
}
