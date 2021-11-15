#include "fft1Drec.h"


void fft(double* x_in,
	std::complex<double>* x_out,
	int N) {

	// Make copy of array and apply window
	for (int i = 0; i < N; i++) {
		try {
			std::complex<double> temp = std::complex<double>(x_in[i], 0);
			x_out[i] = temp;
			x_out[i] *= 1; // Window
		}
		catch(const char* msg){
			continue;
		}
	}

	// Start recursion
	fft_rec(x_out, N);
}

void fftOnComplex(std::complex<double>* x_out,
	int N) {

}

void fft_rec(std::complex<double>* x, int N) {
	
	const double PI = 3.141592653589793238463;
	// Check if it is splitted enough
	if (N <= 1) {
		return;
	}
	int length = N / 2;
	// Split even and odd
	std::complex<double> *odd = new std::complex<double>[N / 2];
	std::complex<double>* even = new std::complex<double>[N / 2];
	for (int i = 0; i < N / 2; i++) {
		even[i] = x[i * 2];
		odd[i] = x[i * 2 + 1];
	}

	// Split on tasks
	fft_rec(even, N / 2);
	fft_rec(odd, N / 2);


	// Calculate DFT
	for (int k = 0; k < N / 2; k++) {
		std::complex<double> t = exp(std::complex<double>(0, -2 * PI * k / N)) * odd[k];
		x[k] = (even[k] + t);
		x[N / 2 + k] = (even[k] - t);
	}
}