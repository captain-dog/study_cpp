#include "Complex_num.h"

Complex_num::Complex_num(double r, double i)
{
	this->r = r;
	this->i = i;
}

Complex_num::~Complex_num()
{

}

Complex_num& Complex_num ::operator=(const Complex_num& other)
{
	this->r = other.r;
	this->i = other.i;

	return *this;
}

Complex_num Complex_num::operator+(const Complex_num& other)
{
	Complex_num temp(0, 0);
	temp.r = this->r + other.r;
	temp.i = this->i + other.i;

	return temp;
}

Complex_num Complex_num::operator-(const Complex_num& other)
{
	Complex_num temp(0, 0);
	temp.r = this->r + other.r;
	temp.i = this->i + other.i;
	return temp;
}

Complex_num Complex_num::operator*(const Complex_num& other)
{
	Complex_num temp(0, 0);
	temp.r = this->r * other.r - this->i * other.i;
	temp.i = this->r * other.i + other.r * this->i;
	return temp;
}

bool Complex_num::operator==(const Complex_num& other)
{
	return this->r == other.r and this->i == other.i;
}

bool Complex_num::operator!=(const Complex_num& other)
{
	return !(this->r == other.r and this->i == other.i);
}
