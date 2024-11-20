#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-10/Lab-10.cpp" 

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestGraph
{
	TEST_CLASS(UnitTestGraph)
	{
	public:

		TEST_METHOD(TestReadGraph)
		{
			int n, m;
			int** weightMatrix = nullptr;

			// Тестовий вхідний файл
			const char* testInput = "test_in.txt";
			ofstream testFile(testInput);
			testFile << "4 4\n"; 
			testFile << "1 2 5\n";
			testFile << "2 3 3\n"; 
			testFile << "3 4 2\n";
			testFile << "4 1 8\n"; 
			testFile.close();

			// Викликаємо функцію для читання графа
			readGraph(testInput, n, m, weightMatrix);

			// Перевірка кількості вершин та ребер
			Assert::AreEqual(4, n);
			Assert::AreEqual(4, m);

			// Перевірка матриці ваг
			Assert::AreEqual(0, weightMatrix[0][0]);
			Assert::AreEqual(5, weightMatrix[0][1]);
			Assert::AreEqual(INF, weightMatrix[0][2]);
			Assert::AreEqual(INF, weightMatrix[0][3]);

			Assert::AreEqual(INF, weightMatrix[1][0]);
			Assert::AreEqual(0, weightMatrix[1][1]);
			Assert::AreEqual(3, weightMatrix[1][2]);
			Assert::AreEqual(INF, weightMatrix[1][3]);

			Assert::AreEqual(INF, weightMatrix[2][0]);
			Assert::AreEqual(INF, weightMatrix[2][1]);
			Assert::AreEqual(0, weightMatrix[2][2]);
			Assert::AreEqual(2, weightMatrix[2][3]);

			Assert::AreEqual(8, weightMatrix[3][0]);
			Assert::AreEqual(INF, weightMatrix[3][1]);
			Assert::AreEqual(INF, weightMatrix[3][2]);
			Assert::AreEqual(0, weightMatrix[3][3]);

			// Звільняємо пам'ять
			deleteMatrix(weightMatrix, n);
		}

		TEST_METHOD(TestPrintWeightMatrix)
		{
			int n = 3;
			int** weightMatrix = new int* [n];
			for (int i = 0; i < n; ++i) {
				weightMatrix[i] = new int[n];
			}

			// Ініціалізація матриці
			weightMatrix[0][0] = 0; weightMatrix[0][1] = 5; weightMatrix[0][2] = INF;
			weightMatrix[1][0] = INF; weightMatrix[1][1] = 0; weightMatrix[1][2] = 3;
			weightMatrix[2][0] = 2; weightMatrix[2][1] = INF; weightMatrix[2][2] = 0;

			// Тестовий вихідний файл
			const char* testOutput = "test_out.txt";

			// Викликаємо функцію для друку матриці
			printWeightMatrix(weightMatrix, n, testOutput);

			// Перевірка вмісту вихідного файлу
			ifstream testFile(testOutput);
			string line;
			Assert::IsTrue(getline(testFile, line));
			Assert::AreEqual(string("0 5 INF "), line);
			Assert::IsTrue(getline(testFile, line));
			Assert::AreEqual(string("INF 0 3 "), line);
			Assert::IsTrue(getline(testFile, line));
			Assert::AreEqual(string("2 INF 0 "), line);

			// Звільняємо пам'ять
			deleteMatrix(weightMatrix, n);
		}
	};
}
