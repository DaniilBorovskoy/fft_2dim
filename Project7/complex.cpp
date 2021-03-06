#include "complex.h"

complex::complex() {

}

complex::complex(double real, double img){
	this->real = real;
	this->img = img;
}

complex complex::add(complex ddd) {
	complex rt;
	rt.real = real + ddd.real;
	rt.img = img + ddd.img;
	return rt;
}

complex complex::subtract(complex ddd) {
	complex rt;
	rt.real = real - ddd.real;
	rt.img = img - ddd.img;
	return rt;
}

complex complex::multi(complex ddd) {
	complex rt;
	rt.real = real * ddd.real - img * ddd.img;
	rt.img = img * ddd.real + ddd.img * real;
	return rt;
}
