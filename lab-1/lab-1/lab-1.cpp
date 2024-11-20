#include <iostream>
#include <bitset>

using namespace std;

// Функція для імплікації
bool implication(bool p, bool q) {
    return !p || q;
}

// Функція для еквівалентності
bool equivalence(bool p, bool q) {
    return p == q;
}

int main() {
    // --- Завдання 1 ---
    bool p, q;
    cout << "Task 1" << endl;
    cout << "Enter the value for p (0 or 1): ";
    cin >> p;
    cout << "Enter the value for q (0 or 1): ";
    cin >> q;

    cout << "Conjunction (p AND q): " << (p && q) << endl;
    cout << "Disjunction (p OR q): " << (p || q) << endl;
    cout << "Exclusive OR (p XOR q): " << (p != q) << endl;
    cout << "Implication (p -> q): " << implication(p, q) << endl;
    cout << "Equivalence (p <-> q): " << equivalence(p, q) << endl;

    // --- Завдання 2 ---
    cout << "\nTask 2" << endl;
    string a = "01001100";
    string b = "10011110";

    bitset<8> bitset_a(a);
    bitset<8> bitset_b(b);

    cout << "Bit string a: " << bitset_a << endl;
    cout << "Bit string b: " << bitset_b << endl;

    cout << "OR  (a | b): " << (bitset_a | bitset_b) << endl;
    cout << "AND (a & b): " << (bitset_a & bitset_b) << endl;
    cout << "XOR (a ^ b): " << (bitset_a ^ bitset_b) << endl;

    return 0;
}
