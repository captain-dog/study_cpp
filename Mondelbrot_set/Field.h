#pragma once
#include "Point.h"

class Field {
public:
	Field(int rows, int cols);
	~Field();

	void print_field();

	void set_point(Point* p);

	int get_rows() { return rows; }
	int get_cols() { return cols; }

private:
	int rows, cols;
	bool** field;
};

