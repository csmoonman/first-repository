#include"complex0.h"
#include<iostream>
complex0::complex0()
{
	real = imag = 0.0;
}

complex0::complex0(double n1, double n2)
{
	real = n1;
	imag = n2;
}

complex0::~complex0()
{}

complex0 complex0::operator+(const complex0& b) const
{
	return complex0(real + b.real, imag + b.imag);
}

complex0 complex0::operator-(const complex0& b) const
{
	return complex0(real - b.real, imag - b.imag);
}

complex0 complex0::operator~() const
{
	return complex0(real, -imag);
}

complex0 complex0::operator*(const complex0& b) const
{
	return complex0(real * b.real - imag * b.imag, real * b.imag + imag * b.real);
}

complex0 complex0::operator*(double n) const
{
	return complex0(n * real, n * imag);
}

complex0 operator*(double n, const complex0& a)
{
	return a * n;
}

std::ostream& operator<<(std::ostream& os, const complex0& c)
{
	os << "(" << c.real << "," << c.imag << "i)\n";
	return os;
}

std::istream& operator>>(std::istream& is, complex0& c)
{
	double r, i;
	std::cout << "Enter real part: ";
	(is >> r).get();
	std::cout << "Enter imaginary part: ";
	(is >> i).get();
	c.complex0::complex0(r, i);

	return is;
}