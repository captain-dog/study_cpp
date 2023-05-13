#include "algos.h"

using namespace std;

void print_field(vector<vector<int>>& field) {
	// выводит на экран элементы вектора векторов  в виде таблицы
	// vector<vector<int>>& vec - вектор, который будет выводиться
	for (auto row : field) {
		for (auto cel : row)
		{
			cout << cel << "\t";
		}
		cout << endl;
	}
}

void init_field(vector<vector<int>>& vec) {
	// инициализирует значениями 1 для всего первого столбца и первой строки

	// инициализация столбца под индексом 1
	for (int i = 1; i < vec.size(); i++)
	{
		vec[i][1] = 1;
	}

	// инициализация строки под индексом 1
	for (int j = 1; j < vec[0].size(); j++)
	{
		vec[1][j] = 1;
	}

}

void generate_combinations(vector<vector<int>>& field, vector<vector<bool>>& forbidden) {
	// функция просчитывает количество возможных способов попастьв клетку
	// vector<vector<int>>& vec - поле, для которого будет производиться просчёт. Желательно чтобы оно было инициализировано нулями, например
	// vector<vector<bool>>& forbidden - поле запрещённых для хода клеток
	// В этой функции считается, что ход может быть сделан вправо на 1 или 2 ячейки, внизу на 1 и по диагонали вниз вправо на 1

	for (int i = 2; i < field.size(); i++)
	{
		for (int j = 2; j < field[i].size(); j++)
		{
			if (not forbidden[i][j]) { // если в текущую клетку можно походить, то просчитываю количество вариантов в неё попасть:
				field[i][j] = // Происходит сумма возможных способов попасть в текущую клетку как сумма возможных способов попасть в каждую из предыдущних клеток
							// Fij = F(i-1)j+Fi(j-1)
					(forbidden[i - 1][j] ? 0 : field[i - 1][j]) + // если в клетику выше можно попасть, то прибавляются количество способов в нё попасть
					(forbidden[i][j - 1] ? 0 : field[i][j - 1]) + // то же смое для клетки слева
					(forbidden[i - 1][j - 1] ? 0 : field[i - 1][j - 1]) + // по диагонали левее выше
					(forbidden[i][j - 2] ? 0 : field[i][j - 2]); // по горизонтали слева на две.
			}
			else {
				field[i][j] = 0; // если в эту клетку нельзя попасть по условию, то количество возможных способов в неё попасть 0
			}
		}
	}
}

bool search_substring(string& s, string& sub_s) {
	// одна из реализациq функции по определению того, есть ли в строке подстрока
	// string s - строка, в которой ищется подстрока sub_s
	bool flag;
	for (int i = 0; i < s.size() - sub_s.size(); i++)
	{
		flag = true;
		for (int j = 0; j < sub_s.size(); j++)
		{
			if (s.at(i + j) != sub_s.at(j)) {
				flag = false;
				break;
			}

		}
		if (flag) { return true; }
	}
	return false;
}

int levenstein_dist(string& stringA, string& stringB)
{
	{
		/*
		* 
		* функция принимает две строки и считает расстояние левенштайна:
		* создаёт поле-матрицу типа a*b
		* b b b
		* a
		* a
		* 
		* Возвращает расстояние левенштейна между двумя строками.
		*/

		//init field
		vector<vector<int>> lMatrix;
		lMatrix.resize(stringA.length() + 1);
		for (auto& row : lMatrix) row.resize(stringB.size() + 1, 0);

		// set base case
		for (int i = 0; i <= stringA.length(); i++) lMatrix[i][0] = i;
		for (int j = 0; j <= stringB.length(); j++) lMatrix[0][j] = j;

		// calculating
		for (int i = 1; i <= stringA.length(); i++)
			for (int j = 1; j <= stringB.length(); j++)
				lMatrix[i][j] = stringA[i - 1] == stringB[j - 1] ?
				lMatrix[i - 1][j - 1] : min(min(lMatrix[i - 1][j], lMatrix[i][j - 1]), lMatrix[i - 1][j - 1]) + 1;
		for (auto& row : lMatrix) {
			for (auto& el : row)cout << el;
			cout << endl;
		}
			
		// return result kek
		return lMatrix[stringA.length()][stringB.length()];
	}
}

int pr_func(string& stringA, string& prefix)
{
	int counter = 0;
	string summary = prefix + "#" + stringA;
	vector<int> costs(summary.size(), 0);


	for (int i = 1; i < summary.size(); ++i) {
		int j = costs[i - 1];

		while (j > 0 and summary[i] != summary[j])
			j = costs[j - 1];

		costs[i] = summary[i] == summary[j] ? j += 1 : 0;

		counter = costs[i] == prefix.size() ? ++counter : counter;
	}

	return counter;
}
