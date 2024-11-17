#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-7/Lab-7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCreateAdjacencyMatrix)
		{
			int n = 3, m = 3;
			int** edges = new int* [m];
			edges[0] = new int[2] {1, 2};
			edges[1] = new int[2] {2, 3};
			edges[2] = new int[2] {3, 1};

			int** adjacencyMatrix = createAdjacencyMatrix(n, m, edges);

			Assert::AreEqual(1, adjacencyMatrix[0][1]); // 1->2
			Assert::AreEqual(0, adjacencyMatrix[0][2]); // 1->3
			Assert::AreEqual(1, adjacencyMatrix[1][2]); // 2->3
			Assert::AreEqual(1, adjacencyMatrix[2][0]); // 3->1

			for (int i = 0; i < n; i++) {
				delete[] adjacencyMatrix[i];
			}
			delete[] adjacencyMatrix;

			for (int i = 0; i < m; ++i) {
				delete[] edges[i];
			}
			delete[] edges;
		}

		TEST_METHOD(TestCalculateDegrees)
		{
			int n = 3;
			int** adjacencyMatrix = new int* [n];
			for (int i = 0; i < n; ++i) {
				adjacencyMatrix[i] = new int[n]();
			}

			adjacencyMatrix[0][1] = 1; // 1->2
			adjacencyMatrix[1][2] = 1; // 2->3
			adjacencyMatrix[2][0] = 1; // 3->1

			int* inDegree = new int[n];
			int* outDegree = new int[n];

			calculateDegrees(adjacencyMatrix, n, inDegree, outDegree);

			Assert::AreEqual(1, inDegree[0]);
			Assert::AreEqual(1, outDegree[0]);
			Assert::AreEqual(1, inDegree[1]);
			Assert::AreEqual(1, outDegree[1]);
			Assert::AreEqual(1, inDegree[2]);
			Assert::AreEqual(1, outDegree[2]);

			delete[] inDegree;
			delete[] outDegree;

			for (int i = 0; i < n; ++i) {
				delete[] adjacencyMatrix[i];
			}
			delete[] adjacencyMatrix;
		}

		TEST_METHOD(TestIsHomogeneous)
		{
			int n = 3;
			int inDegree[3] = { 1, 1, 1 };
			int outDegree[3] = { 1, 1, 1 };

			Assert::IsTrue(isHomogeneous(inDegree, outDegree, n));

			int inDegreeNotHomogeneous[3] = { 1, 2, 1 };
			Assert::IsFalse(isHomogeneous(inDegreeNotHomogeneous, outDegree, n));
		}
	};
}
