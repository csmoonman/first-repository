#include"Port.h"
#pragma warning(disable:4996)

Port::Port(const char* br, const char* st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	strncpy(style, st, 20);
	bottles = b;
}

Port::Port(const Port& p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strncpy(style, p.style, 20);
	bottles = p.bottles;
}

Port::~Port()
{
	delete[] brand;
}

Port& Port::operator=(const Port& p)
{
	if (&p == this)
		return *this;
	delete[] brand;
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strncpy(style, p.style, 20);
	bottles = p.bottles;

	return *this;
}

Port& Port::operator+=(int b)
{
	bottles += b;
	return*this;
}

Port& Port::operator-=(int b)
{
	if (bottles <= b)
		bottles = 0;
	else
		bottles -= b;

	return*this;
}

void Port::show() const
{
	std::cout << "brand: " << brand << std::endl;
	std::cout << "style: " << style << std::endl;
	std::cout << "bottlese: " << bottles << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

VintagePort::VintagePort() :Port("none", "vintage")
{
	nickname = new char[5];
	strcpy(nickname, "none");
	year = 0;
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y) :Port(br, "vintage", b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort& vp) :Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	if (this == &vp)
		return *this;

	Port::operator=(vp);
	delete[] nickname;
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;

	return *this;
}

void VintagePort::show() const
{
	Port::show();
	std::cout << "year: " << year << std::endl;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
	os << (Port)vp;
	os << ", " << vp.year;

	return os;
}