#pragma once

#include <vector>
#include <string>
#include <cctype>

using namespace std;

// ������������ ����������� �������� ������� ������ �� ������������
enum errors
{
    noInputData,
    unacceptableSymbolsPresent,
    invalidCubeAmount
};

// ������� ��� ���������� ���� ��������� �������, ������� ����� ��������� �� ���������� ���������� �������, � ������ ���������� ������� � ���������� ������
void findLadders(vector<int>& currentLadder, int remainingNumber, int previousNumber, vector<vector<int>>& ladders);

// ������� ��� ���������� ���� ��������� �������, ������� ����� ��������� �� ���������� ���������� �������
vector<vector<int>> findAllLadders(int N);

// �������, ����������� ������� ������ �� ������������
bool validateInput(string inputCheck, errors& error);

// �������, ������������ ��������� ������ ��������� � ��������� �������� ����
void exportResult(vector<vector<int>>& ladders, int N, string outputFileName);