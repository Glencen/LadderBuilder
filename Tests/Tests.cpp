#include "pch.h"
#include "CppUnitTest.h"
#include "..\LadderBuilder\LadderBuilder.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	/*! 
	*	- Модульные тесты для функции findAllLadders
	*	-# Минимальное количество кубиков
	*	-# Максимальное количество кубиков
	*	-# Количество кубиков - 12
	*	-# Количество кубиков - 20
	*/
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
	/*! 
	*	- Модульные тесты для функции findLadders
	* 	-# На предыдущем уровне 1 кубик, остался 1
	* 	-# На предыдущем уровне 2 кубика, остался 1
	* 	-# На предыдущем уровне 8 кубиков, осталось 8
	* 	-# На предыдущем уровне 21 кубик, осталось 20
	* 	-# На предыдущем уровне 30 кубиков, осталось 20
	* 	-# На предыдущем уровне 5 кубиков, осталось 7
	* 	-# На предыдущем уровне 4 кубиков, осталось 8
	* 	-# На предыдущем уровне 5 кубиков, осталось 8
	* 	-# На предыдущем уровне 3 кубика, осталось 7
	* 	-# На предыдущем уровне 101 кубик, осталось 100
	*/
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
	/*!
	*	- Модульные тесты для функции validateInput
	*  	-# Пустая строка
	*  	-# Число
	*  	-# Несколько чисел
	*  	-# Цифры и знаки пунктуации
	*  	-# Буквы
	*  	-# Цифры и буквы
	*  	-# Цифры, буквы и знаки
	*  	-# Ноль
	*  	-# Отрицательное число
	*  	-# Число больше 100
	*/
	TEST_CLASS(Test_validateInput)
	{
	public:

		TEST_METHOD(emptyString)
		{
			string inputCheck = "";
			errors error;

			bool expectedValidationResult = false;
			bool actualValidationResult = validateInput(inputCheck, error);
			errors expectedError = noInputData;
			int dataValid = 0;

			if (expectedValidationResult == actualValidationResult && error == expectedError)
				dataValid = 1;

			Assert::AreEqual(1, dataValid);
		}

		TEST_METHOD(number)
		{
			string inputCheck = "56";
			errors error;

			bool expectedValidationResult = true;
			bool actualValidationResult = validateInput(inputCheck, error);

			Assert::AreEqual(expectedValidationResult, actualValidationResult);
		}

		TEST_METHOD(multipleNumbers)
		{
			string inputCheck = "12 46 8";
			errors error;

			bool expectedValidationResult = false;
			bool actualValidationResult = validateInput(inputCheck, error);
			errors expectedError = unacceptableSymbolsPresent;
			int dataValid = 0;

			if (expectedValidationResult == actualValidationResult && error == expectedError)
				dataValid = 1;

			Assert::AreEqual(1, dataValid);
		}

		TEST_METHOD(numbersAndPunctuationSymbols)
		{
			string inputCheck = "1,2.3_4";
			errors error;

			bool expectedValidationResult = false;
			bool actualValidationResult = validateInput(inputCheck, error);
			errors expectedError = unacceptableSymbolsPresent;
			int dataValid = 0;

			if (expectedValidationResult == actualValidationResult && error == expectedError)
				dataValid = 1;

			Assert::AreEqual(1, dataValid);
		}

		TEST_METHOD(letters)
		{
			string inputCheck = "avgsds";
			errors error;

			bool expectedValidationResult = false;
			bool actualValidationResult = validateInput(inputCheck, error);
			errors expectedError = unacceptableSymbolsPresent;
			int dataValid = 0;

			if (expectedValidationResult == actualValidationResult && error == expectedError)
				dataValid = 1;

			Assert::AreEqual(1, dataValid);
		}

		TEST_METHOD(numbersAndLetters)
		{
			string inputCheck = "13asfdas";
			errors error;

			bool expectedValidationResult = false;
			bool actualValidationResult = validateInput(inputCheck, error);
			errors expectedError = unacceptableSymbolsPresent;
			int dataValid = 0;

			if (expectedValidationResult == actualValidationResult && error == expectedError)
				dataValid = 1;

			Assert::AreEqual(1, dataValid);
		}

		TEST_METHOD(numbersLettersAndSymbols)
		{
			string inputCheck = "45_)Fd,g13";
			errors error;

			bool expectedValidationResult = false;
			bool actualValidationResult = validateInput(inputCheck, error);
			errors expectedError = unacceptableSymbolsPresent;
			int dataValid = 0;

			if (expectedValidationResult == actualValidationResult && error == expectedError)
				dataValid = 1;

			Assert::AreEqual(1, dataValid);
		}

		TEST_METHOD(zero)
		{
			string inputCheck = "0";
			errors error;

			bool expectedValidationResult = false;
			bool actualValidationResult = validateInput(inputCheck, error);
			errors expectedError = invalidCubeAmount;
			int dataValid = 0;

			if (expectedValidationResult == actualValidationResult && error == expectedError)
				dataValid = 1;

			Assert::AreEqual(1, dataValid);
		}

		TEST_METHOD(negativeNumber)
		{
			string inputCheck = "-124";
			errors error;

			bool expectedValidationResult = false;
			bool actualValidationResult = validateInput(inputCheck, error);
			errors expectedError = unacceptableSymbolsPresent;
			int dataValid = 0;

			if (expectedValidationResult == actualValidationResult && error == expectedError)
				dataValid = 1;

			Assert::AreEqual(1, dataValid);
		}

		TEST_METHOD(numberGreaterThanHundred)
		{
			string inputCheck = "124434";
			errors error;

			bool expectedValidationResult = false;
			bool actualValidationResult = validateInput(inputCheck, error);
			errors expectedError = invalidCubeAmount;
			int dataValid = 0;

			if (expectedValidationResult == actualValidationResult && error == expectedError)
				dataValid = 1;

			Assert::AreEqual(1, dataValid);
		}
	};
}
