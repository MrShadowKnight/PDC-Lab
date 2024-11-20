#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-15/Lab-15.cpp"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestNQueens
{
	TEST_CLASS(UnitTestNQueens)
	{
	public:
		TEST_METHOD(TestPrintSolution)
		{
			int n = 4;
			position[0] = 1; // Встановлюємо рішення
			position[1] = 3;
			position[2] = 0;
			position[3] = 2;

			// Захоплення вихідних даних
			ostringstream outputBuffer;
			streambuf* oldCoutBuffer = cout.rdbuf(outputBuffer.rdbuf());

			printSolution(n);

			cout.rdbuf(oldCoutBuffer); // Відновлення початкового буфера

			// Очікуваний вивід
			string expectedOutput =
				". Q . . \n"
				". . . Q \n"
				"Q . . . \n"
				". . Q . \n\n";

			Assert::AreEqual(expectedOutput, outputBuffer.str());
		}

		TEST_METHOD(TestSolveNQueens)
		{
			int n = 4;

			// Захоплення вихідних даних
			ostringstream outputBuffer;
			streambuf* oldCoutBuffer = cout.rdbuf(outputBuffer.rdbuf());

			solveNQueens(0, n);

			cout.rdbuf(oldCoutBuffer); // Відновлення початкового буфера

			// Очікуваний вивід для n=4 (всі можливі рішення)
			string expectedOutput =
				". Q . . \n"
				". . . Q \n"
				"Q . . . \n"
				". . Q . \n\n"

				". . Q . \n"
				"Q . . . \n"
				". . . Q \n"
				". Q . . \n\n";

			Assert::AreEqual(expectedOutput, outputBuffer.str());
		}
	};
}
