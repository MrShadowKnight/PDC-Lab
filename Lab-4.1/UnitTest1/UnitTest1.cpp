#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-4/Lab-4.cpp"
#include <vector>
#include <algorithm>
#include <sstream> // Для збору результатів у потік

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

// Прототип функції з основної програми
void lexicographicPermutations(int n, vector<string>& result);

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:
        // Тест генерації перестановок
        TEST_METHOD(TestLexicographicPermutations)
        {
            int n = 3;
            vector<string> expected = {
                "{1, 2, 3}",
                "{1, 3, 2}",
                "{2, 1, 3}",
                "{2, 3, 1}",
                "{3, 1, 2}",
                "{3, 2, 1}"
            };

            vector<string> result;
            lexicographicPermutations(n, result);

            // Перевіряємо кількість перестановок
            Assert::AreEqual(expected.size(), result.size(), L"Кількість перестановок не відповідає очікуваній.");

            // Перевіряємо кожну перестановку
            for (size_t i = 0; i < expected.size(); ++i) {
                Assert::AreEqual(expected[i], result[i], L"Перестановка не збігається.");
            }
        }
    };
}

// Реалізація перевантаженої функції для збору результатів
void lexicographicPermutations(int n, vector<string>& result) {
    int* permutation = new int[n];
    for (int i = 0; i < n; ++i) {
        permutation[i] = i + 1;
    }

    // Функція для форматування перестановки
    auto formatPermutation = [&]() {
        ostringstream oss;
        oss << "{";
        for (int i = 0; i < n; ++i) {
            oss << permutation[i] << (i < n - 1 ? ", " : "");
        }
        oss << "}";
        return oss.str();
        };

    // Збереження початкової перестановки
    result.push_back(formatPermutation());

    // Генерація наступних перестановок
    while (next_permutation(permutation, permutation + n)) {
        result.push_back(formatPermutation());
    }

    delete[] permutation;
}
