#ifndef FFT_h
#define FFT_h

#include <cmath>
#include <complex>

extern void fft(double* x_in,
	std::complex<double>* x_out,
	int N);
void fft_rec(std::complex<double>* x, int N);

const double PI = 3.141592653589793238463;
#endif
