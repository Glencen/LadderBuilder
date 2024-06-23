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

int main() {
    setlocale(LC_ALL, "ru");
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input.is_open()) {
        cout << "Неверно указан файл для входных данных. Возможно указанного расположения не существует или нет прав на чтение" << endl;
        return 0;
    }

    string inputString;
    getline(input, inputString);
    int N = atoi(inputString.c_str());

    vector<int> currentLadder;
    vector<vector<int>> ladders;
    findLadders(currentLadder, N, N, ladders);

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

    output << N << " = " << N << endl << endl;

    for (int i = 0; i < N; i++) {
        output << "*";
    }
    output << endl << endl << "-------------------------------------------------------------------------------------------" << endl;
    output << endl << ladders.size() + 1;

    return 0;
}