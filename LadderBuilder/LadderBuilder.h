#pragma once

#include <vector>
#include <string>
#include <cctype>

using namespace std;

// Перечисление результатов проверки входных данных на правильность
enum errors
{
    noInputData,
    unacceptableSymbolsPresent,
    invalidCubeAmount
};

// Функция для нахождения всех возможных лесенок, которые можно построить из указанного количества кубиков, с учетом количества кубиков в предыдущем уровне
void findLadders(vector<int>& currentLadder, int remainingNumber, int previousNumber, vector<vector<int>>& ladders);

// Функция для нахождения всех возможных лесенок, которые можно построить из указанного количества кубиков
vector<vector<int>> findAllLadders(int N);

// Функция, проверяющая входные данные на правильность
bool validateInput(string inputCheck, errors& error);

// Функция, записывающая результат работы программы в указанный выходной файл
void exportResult(vector<vector<int>>& ladders, int N, string outputFileName);