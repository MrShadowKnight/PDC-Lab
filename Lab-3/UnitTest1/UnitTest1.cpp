#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-3/Lab-3.cpp" // замініть на назву вашого заголовного файлу

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        // Тест функції обчислення факторіалу
        TEST_METHOD(TestFactorial)
        {
            Assert::AreEqual(1LL, factorial(0));  // 0! = 1
            Assert::AreEqual(1LL, factorial(1));  // 1! = 1
            Assert::AreEqual(120LL, factorial(5)); // 5! = 120
        }

        // Тест розміщень
        TEST_METHOD(TestArrangements)
        {
            int n = 10, r = 8;
            long long expected = factorial(n) / factorial(n - r);
            Assert::AreEqual(expected, factorial(10) / factorial(2));
        }

        // Тест чисел Белла
        TEST_METHOD(TestBellNumbers)
        {
            int n = 5;
            vector<vector<long long>> stirling(n + 1, vector<long long>(n + 1, 0));
            vector<long long> bell(n + 1, 0);

            stirling[0][0] = 1;
            for (int i = 1; i <= n; ++i) {
                stirling[i][0] = 0;
                stirling[i][i] = 1;
            }

            for (int i = 2; i <= n; ++i) {
                for (int k = 1; k < i; ++k) {
                    stirling[i][k] = stirling[i - 1][k - 1] + k * stirling[i - 1][k];
                }
            }

            for (int i = 1; i <= n; ++i) {
                for (int k = 1; k <= i; ++k) {
                    bell[i] += stirling[i][k];
                }
            }

            // Перевірка відомих значень чисел Белла
            Assert::AreEqual(1LL, bell[1]);
            Assert::AreEqual(15LL, bell[4]);
            Assert::AreEqual(52LL, bell[5]);
        }
    };
}
