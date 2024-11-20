#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-12/Lab-12.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDijkstra
{
	TEST_CLASS(UnitTestDijkstra)
	{
	public:

		TEST_METHOD(TestDijkstraShortestPath)
		{
			// Ініціалізація графа для тесту
			int n = 5; // Кількість вершин
			for (int i = 0; i < MAX_VERTICES; i++) {
				graph[i].clear();
			}

			// Додаємо ребра
			graph[0].push_back({ 1, 10 });
			graph[0].push_back({ 3, 30 });
			graph[0].push_back({ 4, 100 });
			graph[1].push_back({ 2, 50 });
			graph[2].push_back({ 4, 10 });
			graph[3].push_back({ 2, 20 });
			graph[3].push_back({ 4, 60 });

			int dist[MAX_VERTICES];
			int prev[MAX_VERTICES];

			// Запускаємо Дейкстру з вершини 1 (індекс 0)
			dijkstra(0, n, dist, prev);

			// Перевіряємо відстані
			Assert::AreEqual(0, dist[0]);  
			Assert::AreEqual(10, dist[1]);  
			Assert::AreEqual(50, dist[2]);  
			Assert::AreEqual(30, dist[3]);  
			Assert::AreEqual(60, dist[4]); 

			// Перевіряємо попередні вершини
			Assert::AreEqual(-1, prev[0]); 
			Assert::AreEqual(0, prev[1]);  
			Assert::AreEqual(3, prev[2]);  
			Assert::AreEqual(0, prev[3]); 
			Assert::AreEqual(2, prev[4]); 
		}

		TEST_METHOD(TestDijkstraNoPath)
		{
			// Ініціалізація графа для тесту
			int n = 3;
			for (int i = 0; i < MAX_VERTICES; i++) {
				graph[i].clear();
			}

			// Додаємо ребра
			graph[0].push_back({ 1, 5 });

			int dist[MAX_VERTICES];
			int prev[MAX_VERTICES];

			// Запускаємо Дейкстру з вершини 1 (індекс 0)
			dijkstra(0, n, dist, prev);

			// Перевіряємо відстані
			Assert::AreEqual(0, dist[0]);    
			Assert::AreEqual(5, dist[1]);     
			Assert::AreEqual(INF, dist[2]);  

			// Перевіряємо попередні вершини
			Assert::AreEqual(-1, prev[0]);   
			Assert::AreEqual(0, prev[1]);     
			Assert::AreEqual(-1, prev[2]);  
		}
	};
}
