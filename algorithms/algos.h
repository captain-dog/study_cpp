#pragma once
#include <vector>
#include <string>
#include <iostream>

/*
	пример запуска этого алгоритма из мейна:

	vector<vector<int>> field;
	vector<int> subfield;

	vector<vector<bool>> forbidden_positions;
	vector<bool> subforb_pos;

	int m, // строки
		n; // столбцы
	m = n = 10;

	subfield.resize(m, 0);
	subforb_pos.resize(m, false);

	field.resize(n, subfield);
	forbidden_positions.resize(n, subforb_pos);

	init_field(field);

	generate_combinations(field, forbidden_positions);

	print_field(field);

*/

// еси что все беды из-за отсутствия std:: 
void print_field(std::vector<std::vector<int>>& field);

void init_field(std::vector<std::vector<int>>& vec);

void generate_combinations(std::vector<std::vector<int>>& field, std::vector<std::vector<bool>>& forbidden);

bool search_substring(std::string& s, std::string& sub_s);

int levenstein_dist(std::string& stringA, std::string& stringB);

int pr_func(std::string& stringA, std::string& prefix);