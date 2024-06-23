#pragma once

#include <vector>
#include <string>
#include <cctype>

using namespace std;

/*!
   - ѕеречисление результатов проверки входных данных на правильность
   -# 0 - отсутствуют входные данные
   -# 1 - присутствуют недопустимые символы
   -# 2 - неверное количество кубиков
*/
enum errors
{
    noInputData,
    unacceptableSymbolsPresent,
    invalidCubeAmount
};

/*! 
   ‘ункци€ дл€ нахождени€ всех возможных лесенок, которые можно построить из указанного количества кубиков, с учетом количества кубиков в предыдущем уровне
   \param[in,out] vector<int>& currentLadder - вектор, хран€щий количество кубиков на каждом уровне текущей рассчитываемой лесенки
   \param[in] int remainingNumber Ц оставшеес€ количество кубиков
   \param[in] int previousNumber Ц количество кубиков, использованное в предыдущей итерации функции
   \param[in,out] vector<vector<int>>& ladders Ц вектор, хран€щий все лесенки
*/
void findLadders(vector<int>& currentLadder, int remainingNumber, int previousNumber, vector<vector<int>>& ladders);

/*!
   ‘ункци€ дл€ нахождени€ всех возможных лесенок, которые можно построить из указанного количества кубиков
   \param[in] int N Ц количество кубиков
   \return вектор всех лесенок
*/
vector<vector<int>> findAllLadders(int N);

/*!
   ‘ункци€, провер€юща€ входные данные на правильность
   \param[in] string inputCheck Ц строка, которую нужно проверить на правильность
   \param[in,out] errors& error - ошибка входных данных
   \return значение true Ц нет ошибок, false Ц есть ошибки
*/
bool validateInput(string inputCheck, errors& error);

/*!
   ‘ункци€, записывающа€ результат работы программы в указанный выходной файл
   \param[in] vector<vector<int>>& ladders Ц вектор всех найденных лесенок
   \param[in] int N Ц количество кубиков
   \param[in] string outputFileName - название выходного файла
*/
void exportResult(vector<vector<int>>& ladders, int N, string outputFileName);