#include "Fractal_serpinsk.h"
Fractal_serpinsk::Fractal_serpinsk(Point* pA, Point* pB, Point* pC, Point* p_current, Field* field){
	this->pA = pA;
	this->pB = pB;
	this->pC = pC;
	this->p_current = p_current;
	this->field = field;
	dir = pick_random_direction();
}

void Fractal_serpinsk::pick_rand_dir()
{
	dir = pick_random_direction();
}

void Fractal_serpinsk::run()
{
	/*
	* Функция реализует построение фрактала
	*/
	for (int i = 0; i < 100000; i++)
	{
		pick_rand_dir();
		calc_next_coord();
		field->set_point(p_current);
	}
	field->print_field();
}

void Fractal_serpinsk::calc_next_coord()
{
	/*
	* Эта функция расчитывает следующую координату точки current_p
	*/
	if (dir == Direction::toA) {
		goA();
	}
	else if (dir == Direction::toB) {
		goB();
	}
	else if (dir == Direction::toC) {
		goC();
	}
}

void Fractal_serpinsk::goA()
{
	p_current->set_x((pA->get_x() + p_current->get_x()) / step);
	p_current->set_y((pA->get_y() + p_current->get_y()) / step);
}

void Fractal_serpinsk::goB()
{
	p_current->set_x((pB->get_x() + p_current->get_x()) / step);
	p_current->set_y((pB->get_y() + p_current->get_y()) / step);
}

void Fractal_serpinsk::goC()
{
	p_current->set_x((pC->get_x() + p_current->get_x()) / step);
	p_current->set_y((pC->get_y() + p_current->get_y()) / step);
}
