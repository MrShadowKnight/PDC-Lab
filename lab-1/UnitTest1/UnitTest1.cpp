#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-1/lab-1.cpp"
#include <bitset>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestImplication)
		{
			// Тестування функції імплікації
			Assert::AreEqual(true, implication(true, true));   // 1 -> 1 = true
			Assert::AreEqual(true, implication(false, true));  // 0 -> 1 = true
			Assert::AreEqual(false, implication(true, false)); // 1 -> 0 = false
			Assert::AreEqual(true, implication(false, false)); // 0 -> 0 = true
		}

		TEST_METHOD(TestEquivalence)
		{
			// Тестування функції еквівалентності
			Assert::AreEqual(true, equivalence(true, true));   // 1 <-> 1 = true
			Assert::AreEqual(true, equivalence(false, false)); // 0 <-> 0 = true
			Assert::AreEqual(false, equivalence(true, false)); // 1 <-> 0 = false
			Assert::AreEqual(false, equivalence(false, true)); // 0 <-> 1 = false
		}

		TEST_METHOD(TestBitwiseOperations)
		{
			// Тестування порозрядних операцій
			bitset<8> a("01001100");
			bitset<8> b("10011110");

			// Перевіряємо операції OR, AND, XOR
			Assert::AreEqual(bitset<8>("11011110"), a | b); // OR
			Assert::AreEqual(bitset<8>("00001100"), a & b); // AND
			Assert::AreEqual(bitset<8>("11010010"), a ^ b); // XOR
		}
	};
}
