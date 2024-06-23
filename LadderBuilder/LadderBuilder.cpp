#include <iostream>
#include <fstream>
#include "LadderBuilder.h"

using namespace std;

// Функция для нахождения всех возможных лесенок, которые можно построить из указанного количества кубиков, с учетом количества кубиков в предыдущем уровне
void findLadders(vector<int>& currentLadder, int remainingNumber, int previousNumber, vector<vector<int>>& ladders) {
    if (remainingNumber == 0) {
        ladders.push_back(currentLadder);
    }
    else {
        for (int i = 1; i <= min(remainingNumber, previousNumber - 1); i++) {
            currentLadder.push_back(i);
            findLadders(currentLadder, remainingNumber - i, i, ladders);
            currentLadder.pop_back();
        }
    }
}

// Функция для нахождения всех возможных лесенок, которые можно построить из указанного количества кубиков
vector<vector<int>> findAllLadders(int N)
{
    vector<int> currentLadder;
    vector<vector<int>> ladders;

    findLadders(currentLadder, N, N + 1, ladders);

    return ladders;
}

// Функция, проверяющая входные данные на правильность
bool validateInput(string inputCheck, errors& error)
{
    if (inputCheck.length() < 1) {
        error = noInputData;
        return false;
    }
    else if (inputCheck.length() >= 1) {
        bool inputValid = true;
        for (int i = 0; i < inputCheck.length(); i++) {
            if (!isdigit(inputCheck.at(i))) {
                inputValid = false;
            }
        }
        if (inputValid == false) {
            error = unacceptableSymbolsPresent;
            return false;
        }
    }

    int N = atoi(inputCheck.c_str());

    if (N < 1 || N > 100) {
        error = invalidCubeAmount;
        return false;
    }

    return true;
}

// Функция, записывающая результат работы программы в указанный выходной файл
void exportResult(vector<vector<int>>& ladders, int N, string outputFileName)
{
    ofstream output(outputFileName.c_str());

    for (int i = 0; i < ladders.size(); i++) {
        output << N << " = ";
        for (int j = 0; j < ladders[i].size() - 1; j++) {
            output << ladders[i][j] << " + ";
        }
        output << ladders[i].back() << endl << endl;

        for (int j = ladders[i].size() - 1; j >= 0; j--) {
            for (int k = 0; k < ladders[i][j]; k++) {
                output << "*";
            }
            output << endl;
        }
        output << endl << "-------------------------------------------------------------------------------------------" << endl << endl;
    }
    output << endl << ladders.size();
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru");
    string inputFile = argv[1];
    string outputFile = argv[2];

    ifstream input(inputFile.c_str());

    if (!input.is_open()) {
        cout << "Неверно указан файл для входных данных. Возможно указанного расположения не существует или нет прав на чтение" << endl;
        return 0;
    }

    string inputCheck;
    int N;
    errors error;
    vector<vector<int>> ladders;

    getline(input, inputCheck);

    if (validateInput(inputCheck, error) == false) {
        if (error == noInputData) {
            cout << "Отсутствуют входные данные" << endl;
        }
        else if (error == unacceptableSymbolsPresent) {
            cout << "Введены недопустимые символы. Входные данные должны содержать только запись числа" << endl;
        }
        else if (error == invalidCubeAmount) {
            cout << "Неверно указано количество кубиков. Количество должно быть в диапазоне от 1 до 100" << endl;
        }
    }
    else {
        N = atoi(inputCheck.c_str());
        ladders = findAllLadders(N);
        exportResult(ladders, N, outputFile);
    }

    return 0;
}