#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-2/Lab-2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTruthTable
{
    TEST_CLASS(UnitTestTruthTable)
    {
    public:

        // Функція для тестування обчислення p → q
        TEST_METHOD(TestImplies)
        {
            // Тестуємо операцію p → q
            Assert::IsTrue(implies(false, false)); 
            Assert::IsTrue(implies(false, true));
            Assert::IsTrue(implies(true, true));   
            Assert::IsFalse(implies(true, false)); 
        }
    };
}
