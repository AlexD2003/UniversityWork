#pragma once
#include <string>
#include <istream>
#include <fstream>
#include <ostream>
enum class DisplayType {
	RECTANGULAR_FORM,
	POLAR_FORM
};

class Complex {
	static DisplayType DISPLAY_TYPE;

public:
	Complex();
	Complex(float r, float i);

	static void setDisplayType(DisplayType dt);
	static DisplayType getDisplayType();
	Complex add(const Complex& c);
	Complex subtract(const Complex& c);
	Complex multiply(const Complex& c) const;
	void multiply(float c);
	bool equals(const Complex& c) const;

	Complex conjugate();

	float phase() const;
	float magnitude() const;

	void setImag(float i);
	void setReal(float r);

	float getImag() const;
	float getReal() const;

	Complex operator+(const Complex& other);
	Complex operator-(const Complex& other);
	friend Complex operator*(const Complex& c1, const Complex& c2);

	void toPolar(float* r, float* theta) const;

	std::string toString() const;

	friend std::ostream& operator<<(std::ostream& is, const Complex& c);
	friend std::istream& operator>>(std::istream& is, Complex& c);
private:
	float real;
	float imag;

};




