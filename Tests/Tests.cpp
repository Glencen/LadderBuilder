#include "pch.h"
#include "CppUnitTest.h"
#include "..\LadderBuilder\LadderBuilder.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Test_findAllLadders)
	{
	public:

		TEST_METHOD(minimumCubes)
		{
			int N = 1;
			vector<vector<int>> ladders = findAllLadders(N);

			int expectedLadderAmount = 1;
			int actualLadderAmount = ladders.size();

			Assert::AreEqual(expectedLadderAmount, actualLadderAmount);
		}

		TEST_METHOD(maximumCubes)
		{
			int N = 100;
			vector<vector<int>> ladders = findAllLadders(N);

			int expectedLadderAmount = 444793;
			int actualLadderAmount = ladders.size();

			Assert::AreEqual(expectedLadderAmount, actualLadderAmount);
		}

		TEST_METHOD(twelveCubes)
		{
			int N = 12;
			vector<vector<int>> ladders = findAllLadders(N);

			int expectedLadderAmount = 15;
			int actualLadderAmount = ladders.size();

			Assert::AreEqual(expectedLadderAmount, actualLadderAmount);
		}

		TEST_METHOD(twentyCubes)
		{
			int N = 20;
			vector<vector<int>> ladders = findAllLadders(N);

			int expectedLadderAmount = 64;
			int actualLadderAmount = ladders.size();

			Assert::AreEqual(expectedLadderAmount, actualLadderAmount);
		}
	};
}
