#include "bmptrans.h"
#include <cstdio>
#include <math.h>
#include "fft1Drec.h"
#include <windows.h>
#include <time.h>
#include <iostream>
#include <complex>
#include "CImg.h"
using namespace cimg_library;

int bmptrans::picfft() {

	CImg<unsigned char> image("E:/Без имени-1.bmp");
	

	CImgDisplay main_disp1(image, "Click a point");
	main_disp1.wait();
	int height = image.height();
	int width = image.width();

	CImg<unsigned char> visu(width, height, 1);

	int picsize = height * width;
	
	unsigned int* temp_img = new unsigned int[picsize];

	int one;
	double done;
	unsigned int start_time = clock();
	for (int i = 0; i < height * width; i++) {
		temp_img[i] = image[i];
	}

	double* realValHeight = new double[height];
	std::complex<double> cur_height[512];
	std::complex<double> cur_width[512];

	std::complex<double>* temp_complex_img = new std::complex<double>[picsize];
	std::complex<double>* tpp = new std::complex<double>[picsize];


	//fourier on height dimention
	for (int www = 0; www < width; www++) {
		for (int i = 0; i < height; i++) {
			one = www + i;
			done = (double)one;
			done = pow(-1, done); // set the center of spectrum in middle of image

			realValHeight[i] = (double)temp_img[www * height + i];
			realValHeight[i] = done * realValHeight[i];
		}

		fft(realValHeight, cur_height, height);
		tpp = cur_height;
		for (int i = 0; i < height; i++) {
			temp_complex_img[www * height + i] = tpp[i];
		}

	}

	//fourier on width dimention
	for (int hhh = 0; hhh < height; hhh++) {
		for (int i = 0; i < width; i++) {
			one = hhh + i;
			done = (double)one;
			done = pow(-1, done);

			cur_width[i] = temp_complex_img[i * width + hhh];
			//realValHeight[i] = done * realValHeight[i];
		}
		fft_rec(cur_width, width);
		tpp = cur_width;
		for (int i = 0; i < width; i++) {
			temp_img[i * width + hhh] = pow((tpp[i].real() * tpp[i].real() + tpp[i].imag() * tpp[i].imag()), 0.5);
		}
	}


	for (int i = 0; i < height * width; i++) {
		visu[i] = (log(temp_img[i]) - 2) * 255 / 30;
	}

	/*unsigned char temp = temp_img[0];
	for (int i = 0; i < height * width; i++) {
		if (temp < temp_img[i]) {
			temp = temp_img[i];
		}
	}*/
	unsigned int end_time = clock(); // end time
	double seconds = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("The time: %f seconds\n", seconds);

	CImgDisplay main_disp(visu, "Click a point");
	while (!main_disp.is_closed()) {
		main_disp.wait();
	}
	
	visu.save_bmp("E:/image.bmp");
	
	

	
	return 0;

}