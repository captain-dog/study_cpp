#include "algos.h"

using namespace std;

void print_field(vector<vector<int>>& field) {
	// ������� �� ����� �������� ������� ��������  � ���� �������
	// vector<vector<int>>& vec - ������, ������� ����� ����������
	for (auto row : field) {
		for (auto cel : row)
		{
			cout << cel << "\t";
		}
		cout << endl;
	}
}

void init_field(vector<vector<int>>& vec) {
	// �������������� ���������� 1 ��� ����� ������� ������� � ������ ������

	// ������������� ������� ��� �������� 1
	for (int i = 1; i < vec.size(); i++)
	{
		vec[i][1] = 1;
	}

	// ������������� ������ ��� �������� 1
	for (int j = 1; j < vec[0].size(); j++)
	{
		vec[1][j] = 1;
	}

}

void generate_combinations(vector<vector<int>>& field, vector<vector<bool>>& forbidden) {
	// ������� ������������ ���������� ��������� �������� �������� ������
	// vector<vector<int>>& vec - ����, ��� �������� ����� ������������� �������. ���������� ����� ��� ���� ���������������� ������, ��������
	// vector<vector<bool>>& forbidden - ���� ����������� ��� ���� ������
	// � ���� ������� ���������, ��� ��� ����� ���� ������ ������ �� 1 ��� 2 ������, ����� �� 1 � �� ��������� ���� ������ �� 1

	for (int i = 2; i < field.size(); i++)
	{
		for (int j = 2; j < field[i].size(); j++)
		{
			if (not forbidden[i][j]) { // ���� � ������� ������ ����� ��������, �� ����������� ���������� ��������� � �� �������:
				field[i][j] = // ���������� ����� ��������� �������� ������� � ������� ������ ��� ����� ��������� �������� ������� � ������ �� ����������� ������
							// Fij = F(i-1)j+Fi(j-1)
					(forbidden[i - 1][j] ? 0 : field[i - 1][j]) + // ���� � ������� ���� ����� �������, �� ������������ ���������� �������� � � �������
					(forbidden[i][j - 1] ? 0 : field[i][j - 1]) + // �� �� ���� ��� ������ �����
					(forbidden[i - 1][j - 1] ? 0 : field[i - 1][j - 1]) + // �� ��������� ����� ����
					(forbidden[i][j - 2] ? 0 : field[i][j - 2]); // �� ����������� ����� �� ���.
			}
			else {
				field[i][j] = 0; // ���� � ��� ������ ������ ������� �� �������, �� ���������� ��������� �������� � �� ������� 0
			}
		}
	}
}

bool search_substring(string& s, string& sub_s) {
	// ���� �� ���������q ������� �� ����������� ����, ���� �� � ������ ���������
	// string s - ������, � ������� ������ ��������� sub_s
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
		* ������� ��������� ��� ������ � ������� ���������� �����������:
		* ������ ����-������� ���� a*b
		* b b b
		* a
		* a
		* 
		* ���������� ���������� ����������� ����� ����� ��������.
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
