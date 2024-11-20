#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-11/Lab-11.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestFloydWarshall
{
	TEST_CLASS(UnitTestFloydWarshall)
	{
	public:

		TEST_METHOD(TestFloydWarshallNoPath)
		{
			// Ініціалізація графа для тесту
			int n = 3; // Кількість вершин
			int dist[MAX_N][MAX_N];
			int next[MAX_N][MAX_N];

			// Ініціалізація матриць
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					dist[i][j] = (i == j) ? 0 : INF;
					next[i][j] = (i == j) ? i : -1;
				}
			}

			// Додаємо ребра
			dist[0][1] = 7; next[0][1] = 1;

			// Викликаємо алгоритм Флойда-Воршелла
			floydWarshall(n, dist, next);

			// Перевірка: немає шляху від 1 до 3 (індекси 0 до 2)
			Assert::AreEqual(INF, dist[0][2]);
			Assert::AreEqual(-1, next[0][2]);
		}
	};
}
