#include <iostream>
#include <fstream>
#include "LadderBuilder.h"

using namespace std;

void findLadders(vector<int>& currentLadder, int remainingNumber, int previousNumber, vector<vector<int>>& ladders) {
    // Если оставшееся количество кубиков равно 0
    if (remainingNumber == 0) {
        // Сохранить текущую лесенку в общий контейнер
        ladders.push_back(currentLadder);
    }
    // Иначе
    else {
        // Для всех кубиков от 1 до наименьшего из двух чисел: оставшегося числа кубиков и количества кубиков, использованного в предыдущей итерации функции - 1
        for (int i = 1; i <= min(remainingNumber, previousNumber - 1); i++) {
            // Записать в конец вектора, хранящего текущую лесенку, текущее используемое количество кубиков
            currentLadder.push_back(i);
            // Рекурсивно вызвать функцию findLadders
            findLadders(currentLadder, remainingNumber - i, i, ladders);
            // Удалить последний элемент вектора, хранящего текущую лесенку
            currentLadder.pop_back();
        }
    }
}

vector<vector<int>> findAllLadders(int N)
{
    vector<int> currentLadder;
    vector<vector<int>> ladders;

    // Построить все лесенки из указанного количества кубиков, считая, что на предыдущем уровне должно быть кубиков на 1 больше, чем указанное количество
    findLadders(currentLadder, N, N + 1, ladders);

    return ladders;
}

bool validateInput(string inputCheck, errors& error)
{
    // Если длина строки < 1
    if (inputCheck.length() < 1) {
        // Считать, что входные данные отсутствуют
        error = noInputData;
        return false;
    }
    // Иначе если длина строки >= 1 
    else if (inputCheck.length() >= 1) {
        // Проверить строку на наличие символов, не являющихся цифрами
        bool inputValid = true;
        for (int i = 0; i < inputCheck.length(); i++) {
            if (!isdigit(inputCheck.at(i))) {
                inputValid = false;
            }
        }
        // Если строка содержит символы, не являющиеся цифрой 
        if (inputValid == false) {
            // Считать, что введены недопустимые символы
            error = unacceptableSymbolsPresent;
            return false;
        }
    }
    // Преобразовать строку в число
    int N = atoi(inputCheck.c_str());
    // Если полученное число < 1 или > 100 
    if (N < 1 || N > 100) {
        // Считать, что введено неверное число кубиков
        error = invalidCubeAmount;
        return false;
    }

    return true;
}

void exportResult(vector<vector<int>>& ladders, int N, string outputFileName)
{
    ofstream output(outputFileName.c_str());
    // Вывести все лесенки в виде суммы количества кубиков на каждом уровне и в виде их графического представления
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
    // Вывести общее число найденных лесенок
    output << endl << ladders.size();
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru");
    string inputFile = argv[1];
    string outputFile = argv[2];

    ifstream input(inputFile.c_str());
    // Если входной файл не открывается
    if (!input.is_open()) {
        cout << "Неверно указан файл для входных данных. Возможно указанного расположения не существует или нет прав на чтение" << endl;
        return 0;
    }

    string inputCheck;
    int N;
    errors error;
    vector<vector<int>> ladders;
    // Считать входной файл
    getline(input, inputCheck);
    // Если обнаружены ошибки во входных данных
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
    // Иначе
    else {
        // Найти и вывести в выходной файл все лесенки, которые можно построить из данного количества кубиков
        N = atoi(inputCheck.c_str());
        ladders = findAllLadders(N);
        exportResult(ladders, N, outputFile);
    }

    return 0;
}