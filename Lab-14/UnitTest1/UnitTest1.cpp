#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-14/Lab-14.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestGraphProperties
{
	TEST_CLASS(UnitTestGraphProperties)
	{
	public:

		TEST_METHOD(TestIsAsymmetric)
		{
			// Ініціалізуємо граф для перевірки асиметрії
			n = 3;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					graph[i][j] = 0;
				}
			}
			graph[0][1] = 1; 
			graph[1][0] = 1; 
			graph[1][2] = 1; 

			Assert::IsFalse(isAsymmetric());

			graph[1][0] = 0;

			Assert::IsTrue(isAsymmetric());
		}

		TEST_METHOD(TestIsTransitive)
		{
			// Ініціалізуємо граф для перевірки транзитивності
			n = 3;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					graph[i][j] = 0;
				}
			}
			graph[0][1] = 1;
			graph[1][2] = 1;

			Assert::IsFalse(isTransitive());

			// Додаємо відношення від 0 до 2
			graph[0][2] = 1;

			// Тест перевіряє, що граф тепер є транзитивним
			Assert::IsTrue(isTransitive());
		}
	};
}
