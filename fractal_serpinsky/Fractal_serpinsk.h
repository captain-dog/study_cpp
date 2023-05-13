#pragma once
#include "Point.h"
#include "Field.h"
#include <iostream>

class Fractal_serpinsk
{
public:
	Fractal_serpinsk(Point* pA, Point* pB, Point* pC, Point* p_current, Field* field);

	void run();
	
private:
	Field* field;
	Point* pA; // ������ ����� ������ ������������
	Point* pB;
	Point* pC;
	Point* p_current; // ����� ��������� �����
	int step = 2; // � ��� ���������� ��� ����� ����������� � �����-�� �����
	enum class Direction
	{
		toA,
		toB,
		toC,
	};

	Direction dir;
	void pick_rand_dir();
	Direction pick_random_direction() {
		int state = rand() % 3;
		if (state == 0)
		{
			return Direction::toA;
		}
		else if (state == 1) {
			return Direction::toB;
		}
		else if (state == 2) {
			return Direction::toC;
		}
		return Direction::toA;
	}

	void calc_next_coord();

	void goA();

	void goB();

	void goC();
};

