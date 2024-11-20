#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-9/Lab-9.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestGraph
{
    TEST_CLASS(UnitTestGraph)
    {
    public:

        TEST_METHOD(TestInitializeGraph)
        {
            initializeGraph();

            // Перевірка початкових значень
            for (int i = 0; i < MAX_VERTICES; ++i) {
                Assert::AreEqual(0, edgeCount[i]);
                Assert::IsFalse(visited[i]);
                Assert::AreEqual(0, bfsNumber[i]);
            }
        }

        TEST_METHOD(TestAddEdge)
        {
            initializeGraph();

            // Додаємо ребро
            addEdge(0, 1);
            addEdge(0, 2);

            // Перевіряємо правильність графу
            Assert::AreEqual(1, adjList[0][0]);
            Assert::AreEqual(2, adjList[0][1]);
            Assert::AreEqual(0, adjList[1][0]);
            Assert::AreEqual(0, adjList[2][0]);
            Assert::AreEqual(2, edgeCount[0]);
            Assert::AreEqual(1, edgeCount[1]);
            Assert::AreEqual(1, edgeCount[2]);
        }

        TEST_METHOD(TestLoadGraphFromFile)
        {
            initializeGraph();

            // Створення тестового файлу
            string testFilename = "test_graph.txt";
            ofstream testFile(testFilename);
            testFile << "0 1\n";
            testFile << "0 2\n";
            testFile << "1 3\n";
            testFile.close();

            // Завантаження графу
            loadGraphFromFile(testFilename);

            // Перевіряємо, чи граф завантажився правильно
            Assert::AreEqual(1, adjList[0][0]);
            Assert::AreEqual(2, adjList[0][1]);
            Assert::AreEqual(0, adjList[1][0]);
            Assert::AreEqual(3, adjList[1][1]);
            Assert::AreEqual(2, edgeCount[0]);
            Assert::AreEqual(2, edgeCount[1]);
        }

        TEST_METHOD(TestBFS)
        {
            initializeGraph();

            // Створення простого графа
            addEdge(0, 1);
            addEdge(0, 2);
            addEdge(1, 3);
            addEdge(2, 3);

            // Очікуваний порядок обходу
            int expectedOrder[MAX_VERTICES] = { 1, 2, 3, 4 };

            // Виконання BFS
            BFS(0);

            // Перевірка порядку обходу BFS
            Assert::AreEqual(1, bfsNumber[0]);
            Assert::AreEqual(2, bfsNumber[1]);
            Assert::AreEqual(3, bfsNumber[2]);
            Assert::AreEqual(4, bfsNumber[3]);
        }
    };
}
