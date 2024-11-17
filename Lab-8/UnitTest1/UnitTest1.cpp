#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-8/Lab-8.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDFS
{
	TEST_CLASS(UnitTestDFS)
	{
	public:

		TEST_METHOD(TestInitializeGraph)
		{
			initializeGraph();
			for (int i = 0; i < MAX_VERTICES; ++i) {
				Assert::AreEqual(0, edgeCount[i]);
				Assert::IsFalse(visited[i]);
				Assert::AreEqual(0, dfsNumber[i]);
			}
		}

		TEST_METHOD(TestAddEdge)
		{
			initializeGraph();

			addEdge(0, 1);
			addEdge(1, 2);

			Assert::AreEqual(1, edgeCount[0]);
			Assert::AreEqual(2, edgeCount[1]);
			Assert::AreEqual(1, edgeCount[2]);

			Assert::AreEqual(1, adjList[0][0]);
			Assert::AreEqual(0, adjList[1][0]);
			Assert::AreEqual(2, adjList[1][1]);
			Assert::AreEqual(1, adjList[2][0]);
		}

		TEST_METHOD(TestLoadGraphFromFile)
		{
			initializeGraph();

			// Створення тимчасового файлу для тестування
			string testFilename = "test_graph.txt";
			ofstream file(testFilename);
			file << "0 1\n1 2\n2 3\n";
			file.close();

			loadGraphFromFile(testFilename);

			Assert::AreEqual(1, edgeCount[0]);
			Assert::AreEqual(2, edgeCount[1]);
			Assert::AreEqual(2, edgeCount[2]);
			Assert::AreEqual(1, edgeCount[3]);

			Assert::AreEqual(1, adjList[0][0]);
			Assert::AreEqual(0, adjList[1][0]);
			Assert::AreEqual(2, adjList[1][1]);
			Assert::AreEqual(1, adjList[2][0]);
			Assert::AreEqual(3, adjList[2][1]);

			// Видалення тимчасового файлу після тестування
			remove(testFilename.c_str());
		}

		TEST_METHOD(TestDFS)
		{
			initializeGraph();

			// Створення графу
			addEdge(0, 1);
			addEdge(1, 2);
			addEdge(2, 3);

			// Очікуваний порядок відвідування
			int expectedDFSNumber[MAX_VERTICES] = { 1, 2, 3, 4 };

			// Виконання DFS
			DFS(0);

			for (int i = 0; i < 4; ++i) {
				Assert::AreEqual(expectedDFSNumber[i], dfsNumber[i]);
				Assert::IsTrue(visited[i]);
			}

			// Перевірка, що всі неіснуючі вершини залишилися невідвіданими
			for (int i = 4; i < MAX_VERTICES; ++i) {
				Assert::IsFalse(visited[i]);
			}
		}
	};
}