#pragma once
#include <string>
class complex
{
public:
	double real;
	double img;
	complex();
	complex(double real, double img);
	complex add(complex);
	complex subtract(complex);
	complex multi(complex);
};

