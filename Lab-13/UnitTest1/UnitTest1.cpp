#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-13/Lab-13.cpp"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestGraphColoring
{
	TEST_CLASS(UnitTestGraphColoring)
	{
	public:

		TEST_METHOD(TestGraphColoringSmallGraph)
		{
			// Тест для графа з 4 вершинами та 4 ребрами (простий граф)
			int n = 4;
			int m = 4;

			// Очистка графа
			for (int i = 0; i < MAX_VERTICES; i++) {
				for (int j = 0; j < MAX_VERTICES; j++) {
					graph[i][j] = 0;
				}
			}

			// Визначаємо ребра
			graph[0][1] = 1; graph[1][0] = 1;
			graph[1][2] = 1; graph[2][1] = 1;
			graph[2][3] = 1; graph[3][2] = 1;
			graph[3][0] = 1; graph[0][3] = 1;

			graphColoring(n);

			// Перевірка результатів
			int numColors = *max_element(color, color + n) + 1;

			// Для циклічного графа з 4 вершинами потрібно 2 кольори
			Assert::AreEqual(2, numColors);

			// Перевірка, що сусідні вершини мають різні кольори
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (graph[i][j] == 1) {
						Assert::AreNotEqual(color[i], color[j]);
					}
				}
			}
		}

		TEST_METHOD(TestGraphColoringCompleteGraph)
		{
			// Тест для повного графа з 3 вершинами
			int n = 3;
			int m = 3;

			// Очистка графа
			for (int i = 0; i < MAX_VERTICES; i++) {
				for (int j = 0; j < MAX_VERTICES; j++) {
					graph[i][j] = 0;
				}
			}

			// Повний граф
			graph[0][1] = 1; graph[1][0] = 1;
			graph[1][2] = 1; graph[2][1] = 1;
			graph[0][2] = 1; graph[2][0] = 1;

			graphColoring(n);

			// Перевірка результатів
			int numColors = *max_element(color, color + n) + 1;

			// Для повного графа з 3 вершинами потрібно 3 кольори
			Assert::AreEqual(3, numColors);

			// Перевірка, що сусідні вершини мають різні кольори
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (graph[i][j] == 1) {
						Assert::AreNotEqual(color[i], color[j]);
					}
				}
			}
		}
	};
}
