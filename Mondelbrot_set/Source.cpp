#include "Complex_num.h"
#include"Field.h"
#include "Point.h"
#include "Mondelbert_set.h"
#include <iostream>


using namespace std;

int number_iters(Complex_num zc) {
	Complex_num z(0, 0);
	int limit_iters = 2000;
	int limit_values = 10000;
	int i = 0;
	for (; i < limit_iters; i++)
	{
		if (z.r > limit_values or z.i > limit_values) {
			return i;
		}
		z = (z * z) + zc;
	}
	return limit_iters;
}

void go_through_field(double scale, Field *field) {
	Point p(0, 0);
	int percent = 0;
	Complex_num temp(0, 0);
	int iters;
	for (int i = 0; i < field->get_rows(); i++)
	{
		if (percent % 2 == 0) {
			cout << "Proccess ... " << percent << "%" << endl;
		}
		
		for (int j = 0; j < field->get_cols(); j++)
		{
			temp.r = (j - (double(field->get_cols()) / 2)) *scale;
			temp.i = (i - double(field->get_rows()) / 2) * scale;
			iters = number_iters(temp);
			if (iters > 1500) {
				p.set_x(j);
				p.set_y(i);
			}
			else {

			}

			field->set_point(&p);
			percent = (i * 100) / field->get_cols();
		}
		
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	Complex_num zc(-1, 0); //��� �������, ������ �
	int rows = 40, 
		cols = 90;
	Field field(rows, cols);
	go_through_field(0.05, &field);
	field.print_field();

	return 0;

}