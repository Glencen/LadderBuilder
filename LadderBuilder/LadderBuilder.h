#pragma once

#include <vector>
#include <string>
#include <cctype>

using namespace std;

/*!
   - ������������ ����������� �������� ������� ������ �� ������������
   -# 0 - ����������� ������� ������
   -# 1 - ������������ ������������ �������
   -# 2 - �������� ���������� �������
*/
enum errors
{
    noInputData,
    unacceptableSymbolsPresent,
    invalidCubeAmount
};

/*! 
   ������� ��� ���������� ���� ��������� �������, ������� ����� ��������� �� ���������� ���������� �������, � ������ ���������� ������� � ���������� ������
   \param[in,out] vector<int>& currentLadder - ������, �������� ���������� ������� �� ������ ������ ������� �������������� �������
   \param[in] int remainingNumber � ���������� ���������� �������
   \param[in] int previousNumber � ���������� �������, �������������� � ���������� �������� �������
   \param[in,out] vector<vector<int>>& ladders � ������, �������� ��� �������
*/
void findLadders(vector<int>& currentLadder, int remainingNumber, int previousNumber, vector<vector<int>>& ladders);

/*!
   ������� ��� ���������� ���� ��������� �������, ������� ����� ��������� �� ���������� ���������� �������
   \param[in] int N � ���������� �������
   \return ������ ���� �������
*/
vector<vector<int>> findAllLadders(int N);

/*!
   �������, ����������� ������� ������ �� ������������
   \param[in] string inputCheck � ������, ������� ����� ��������� �� ������������
   \param[in,out] errors& error - ������ ������� ������
   \return �������� true � ��� ������, false � ���� ������
*/
bool validateInput(string inputCheck, errors& error);

/*!
   �������, ������������ ��������� ������ ��������� � ��������� �������� ����
   \param[in] vector<vector<int>>& ladders � ������ ���� ��������� �������
   \param[in] int N � ���������� �������
   \param[in] string outputFileName - �������� ��������� �����
*/
void exportResult(vector<vector<int>>& ladders, int N, string outputFileName);