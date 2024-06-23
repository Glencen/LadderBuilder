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

	TEST_CLASS(Test_findLadders)
	{
	public:

		TEST_METHOD(oneOnPreviousLevelOneRemaining)
		{
			int remainingNumber = 1;
			int previousNumber = 1;
			vector<int> currentLadder;
			vector<vector<int>> ladders;

			findLadders(currentLadder, remainingNumber, previousNumber, ladders);

			int expectedLadderAmount = 0;
			int actualLadderAmount = ladders.size();

			Assert::AreEqual(expectedLadderAmount, actualLadderAmount);
		}

		TEST_METHOD(twoOnPreviousLevelOneRemaining)
		{
			int remainingNumber = 1;
			int previousNumber = 2;
			vector<int> currentLadder;
			vector<vector<int>> ladders;

			findLadders(currentLadder, remainingNumber, previousNumber, ladders);

			int expectedLadderAmount = 1;
			int actualLadderAmount = ladders.size();
			vector<vector<int>> expectedLadders = { {1} };

			Assert::AreEqual(expectedLadderAmount, actualLadderAmount);
			Assert::IsTrue(expectedLadders == ladders);
		}

		TEST_METHOD(eightOnPreviousLevelEightRemaining)
		{
			int remainingNumber = 8;
			int previousNumber = 8;
			vector<int> currentLadder;
			vector<vector<int>> ladders;

			findLadders(currentLadder, remainingNumber, previousNumber, ladders);

			int expectedLadderAmount = 5;
			int actualLadderAmount = ladders.size();
			vector<vector<int>> expectedLadders = { {4,3,1},{5,2,1},{5,3},{6,2},{7,1} };

			Assert::AreEqual(expectedLadderAmount, actualLadderAmount);
			Assert::IsTrue(expectedLadders == ladders);
		}

		TEST_METHOD(twentyOneOnPreviousLevelTwentyRemaining)
		{
			int remainingNumber = 20;
			int previousNumber = 21;
			vector<int> currentLadder;
			vector<vector<int>> ladders;

			findLadders(currentLadder, remainingNumber, previousNumber, ladders);

			int expectedLadderAmount = 64;
			int actualLadderAmount = ladders.size();

			Assert::AreEqual(expectedLadderAmount, actualLadderAmount);
		}

		TEST_METHOD(thirtyOnPreviousLevelTwentyRemaining)
		{
			int remainingNumber = 20;
			int previousNumber = 30;
			vector<int> currentLadder;
			vector<vector<int>> ladders;

			findLadders(currentLadder, remainingNumber, previousNumber, ladders);

			int expectedLadderAmount = 64;
			int actualLadderAmount = ladders.size();

			Assert::AreEqual(expectedLadderAmount, actualLadderAmount);
		}

		TEST_METHOD(fiveOnPreviousLevelSevenRemaining)
		{
			int remainingNumber = 7;
			int previousNumber = 5;
			vector<int> currentLadder;
			vector<vector<int>> ladders;

			findLadders(currentLadder, remainingNumber, previousNumber, ladders);

			int expectedLadderAmount = 2;
			int actualLadderAmount = ladders.size();
			vector<vector<int>> expectedLadders = { {4,2,1},{4,3} };

			Assert::AreEqual(expectedLadderAmount, actualLadderAmount);
			Assert::IsTrue(expectedLadders == ladders);
		}

		TEST_METHOD(fourOnPreviousLevelEightRemaining)
		{
			int remainingNumber = 8;
			int previousNumber = 4;
			vector<int> currentLadder;
			vector<vector<int>> ladders;

			findLadders(currentLadder, remainingNumber, previousNumber, ladders);

			int expectedLadderAmount = 0;
			int actualLadderAmount = ladders.size();

			Assert::AreEqual(expectedLadderAmount, actualLadderAmount);
		}

		TEST_METHOD(fiveOnPreviousLevelEightRemaining)
		{
			int remainingNumber = 8;
			int previousNumber = 5;
			vector<int> currentLadder;
			vector<vector<int>> ladders;

			findLadders(currentLadder, remainingNumber, previousNumber, ladders);

			int expectedLadderAmount = 1;
			int actualLadderAmount = ladders.size();
			vector<vector<int>> expectedLadders = { {4,3,1} };

			Assert::AreEqual(expectedLadderAmount, actualLadderAmount);
			Assert::IsTrue(expectedLadders == ladders);
		}

		TEST_METHOD(threeOnPreviousLevelSevenRemaining)
		{
			int remainingNumber = 7;
			int previousNumber = 3;
			vector<int> currentLadder;
			vector<vector<int>> ladders;

			findLadders(currentLadder, remainingNumber, previousNumber, ladders);

			int expectedLadderAmount = 0;
			int actualLadderAmount = ladders.size();

			Assert::AreEqual(expectedLadderAmount, actualLadderAmount);
		}

		TEST_METHOD(hunderedAndOneOnPreviousLevelHundredRemaining)
		{
			int remainingNumber = 100;
			int previousNumber = 101;
			vector<int> currentLadder;
			vector<vector<int>> ladders;

			findLadders(currentLadder, remainingNumber, previousNumber, ladders);

			int expectedLadderAmount = 444793;
			int actualLadderAmount = ladders.size();

			Assert::AreEqual(expectedLadderAmount, actualLadderAmount);
		}
	};
}
