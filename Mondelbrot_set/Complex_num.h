#pragma once
class Complex_num
{
public:
	Complex_num(double r = 0, double i = 0);
	~Complex_num();

	Complex_num& operator = (const Complex_num& other);

	Complex_num operator + (const Complex_num& other);
	Complex_num operator - (const Complex_num& other);
	Complex_num operator * (const Complex_num& other);

	bool operator == (const Complex_num& other);
	bool operator != (const Complex_num& other);




	double r, i;

private:

};

