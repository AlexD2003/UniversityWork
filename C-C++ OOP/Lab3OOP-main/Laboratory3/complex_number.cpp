#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "complex_number.h"
#define AC_GREEN "\x1b[32m"
#define AC_BLUE "\x1b[34m"



Complex complex_create(float real, float imag) {
	Complex c;
	c.real = real;
	c.imag = imag;
	return c;
}
void complex_display(Complex c)
{
	printf("%d , %f", c.real, c.imag);
}

float get_real(Complex c) {
	return c.real;
}

float get_imag(Complex c) {
	return c.imag;
}

void set_real(Complex* c, float real) {
	c->real = real;
}

void set_imag(Complex* c, float imag) {
	c->imag = imag;
}

Complex complex_add(Complex c, Complex c1) {
	struct Complex cFin;
	cFin.real = c.real + c1.real;
	cFin.imag = c.imag + c1.imag;
	return cFin;
}
Complex complex_subtract(Complex c, Complex c1) {
	struct Complex cFin;
	cFin.real = c.real - c1.real;
	cFin.imag = c.imag - c1.imag;
	return cFin;
}
Complex complex_multiply(Complex c, Complex c1) {
	struct Complex cFin;
	cFin.real = c.real * c1.real - c.imag * c1.imag;
	cFin.imag = c.real * c1.imag + c.imag * c1.real;
	return cFin;
}

bool complex_equals(Complex c, Complex c1) {
	bool realcheck=false, imagcheck = false;
	if (c.real == c1.real) {
		realcheck = true;
	}
	if (c.imag == c1.imag) {
		imagcheck = true;
	}
	if (realcheck == true && imagcheck == true)
		return true;
	else
		return false;
}
Complex complex_conjugate(Complex c) {
	c.imag *= -1;
	return c;
}
void complex_scalar_mult(Complex* c, float s)
{
	c->real = c->real * s;
	c->imag = c->imag * s;
}
float complex_mag(Complex c) {
	return sqrt(pow(c.real, 2) + pow(c.imag, 2));
}
float complex_phase(Complex c) {
	return atan2f(c.imag, c.real);
}
void complex_to_polar(Complex c, float* r, float* theta) {
	*r = complex_mag(c);
	*theta = complex_phase(c);
}
void display_mandelbrot(int width, int height, int max_its)
{
	Complex z, c;
	const float x_start = -3.0f;
	const float x_fin = 1.0f;
	const float y_start = -1.0f;
	const float y_fin = 1.0f;

	double dx = (x_fin - x_start) / (width - 1);
	double dy = (y_fin - y_start) / (height - 1);

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			// TODO your code here
			// create complex number z = 0 + 0i
			z = complex_create(0, 0);
			// create complex number c =  x_start+ x*dx + (y_start+y*dy)i
			c = complex_create(x_start + x * dx, y_start + y * dy);
			int iteration = 0;
			// while |z| < 2 and we haven't reach max_its
			while (/* TODO your code here: |z| < 2&& */ complex_mag(z) < 2 && ++iteration < max_its) {
				// apply the rule:  z =  z*z + c
				z = complex_add(complex_multiply(z, z), c);
			}

			// TODO: your code here (modify the code to display the mandelbrot fractal
			if (iteration == max_its) {
				printf("%s* %s", AC_BLUE, AC_GREEN);
			}
			else {
				printf("%s- ", AC_GREEN);
			}

		}
		printf("\n");
	}
}

