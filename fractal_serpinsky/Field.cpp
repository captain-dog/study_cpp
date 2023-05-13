#include "Field.h"
#include <iostream>

Field::Field(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;
	field = new bool* [rows];
	for (int i = 0; i < rows; i++)
	{
		field[i] = new bool[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			field[i][j] = false;
		}
	}
}

Field::~Field() {
	for (int i = 0; i < rows; i++)
	{
		delete[] field[i];
	}
	delete[] field;
}

void Field::print_field()
{
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (field[i][j] == 0) {
				std::cout << " ";
			}
			else {
				std::cout << "@";
			}

		}
		std::cout << std::endl;
	}
	
}

void Field::set_point(Point* p)
{
	if (p->get_x() > cols or p->get_y() > rows) { throw; }
	field[p->get_y()][p->get_x()] = 1;
}
