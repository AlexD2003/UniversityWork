#include "complex_number.h"
#include <sstream>
#include <iomanip>
#include <sstream>
#include <iostream>
using namespace std;
#define M_PI  3.1415926535f 
 
DisplayType Complex::DISPLAY_TYPE = DisplayType::RECTANGULAR_FORM;

Complex::Complex() : real{ 0 }, imag{ 0 } {}
Complex::Complex(float r, float i) : real{ r }, imag{ i } {}

void Complex::setDisplayType(DisplayType dt) {
    DISPLAY_TYPE = dt;
}

DisplayType Complex::getDisplayType() {
    return DISPLAY_TYPE;
}
void Complex::setImag(float i) {
    imag = i;
}
void Complex::setReal(float r) {
    real = r;
}
float Complex::getImag() const{
    return imag;
}
float Complex::getReal() const {
    return real;
}

Complex Complex::add(const Complex& c) {
    float r = real + c.real;
    float i = imag + c.imag;
    return Complex(r, i);
}
Complex Complex::subtract(const Complex& c) {
    float r = real - c.real;
    float i = imag - c.imag;
    return Complex(r, i);
}
Complex Complex::multiply(const Complex& c) const {
    float real_part = real * c.real - imag * c.imag;
    float imag_part = real * c.imag + imag * c.real;
    return Complex(real_part, imag_part);
}
void Complex::multiply(float c) {
    real *= c;
    imag *= c;
}
bool Complex::equals(const Complex& c) const {
    bool checkReal = false, checkImag = false;
    if (real == c.real)
        checkReal = true;
    if (imag == c.imag)
        checkImag = true;
    if (checkReal == true && checkImag == true) {
        return true;
    }
    else
        return false;
}
Complex Complex::conjugate() {
    float imag2 = imag*-1;
    return Complex(real, imag2);
}
float Complex::phase() const {
    return atan2f(imag, real);
}
float Complex::magnitude() const {
    return sqrt(pow(real, 2) + pow(imag, 2));
}
Complex Complex::operator+(const Complex& other) {
    return Complex(real + other.real, imag + other.imag);
}
Complex Complex::operator-(const Complex& other) {
    return Complex(real - other.real, imag - other.imag);
}
Complex operator*(const Complex& c1, const Complex& c2) {
    float real = c1.real * c2.real - c1.imag * c2.imag;
    float imag = c1.real * c2.imag + c1.imag * c2.real;
    return Complex(real, imag);
}
void Complex::toPolar(float* r, float* theta) const {
    *r = magnitude();
    *theta = phase();
}
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    return is;
}

std::string Complex::toString() const {
    return "i";
}