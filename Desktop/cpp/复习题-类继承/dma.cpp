#include"dma.h"
#pragma warning (disable: 4996)

ABC_DMA::ABC_DMA(const char* l, int r)
{
	label = new char[strlen(l) + 1];
	strcpy(label, l);
	rating = r;
}

ABC_DMA& ABC_DMA::operator=(const ABC_DMA& rd)
{
	if (this == &rd)
		return *this;
	delete[] label;
	label = new char[strlen(rd.label) + 1];
	strcpy(label, rd.label);
	rating = rd.rating;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const ABC_DMA& rd)
{
	os << rd.label << "  " << rd.rating;
	return os;
}

baseDMA::baseDMA(const char* l, int r) :ABC_DMA(l, r)
{}

baseDMA::baseDMA(const baseDMA& rs)
{
	ABC_DMA::operator=(rs);
}

baseDMA::~baseDMA()
{}

baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	if (this == &rs)
		return *this;
	ABC_DMA::operator=(rs);

	return *this;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
	os << (const ABC_DMA&)rs << std::endl;
	return os;
}

lacksDMA::lacksDMA(const char* c, const char* l, int r) :ABC_DMA(l, r)
{
	strncpy(color, c, COL_LEN);
}

lacksDMA::lacksDMA(const lacksDMA& rs)
{
	ABC_DMA::operator=(rs);
	strncpy(color, rs.color, COL_LEN);
}

std::ostream& operator<<(std::ostream& os, const lacksDMA& rs)
{
	os << (const ABC_DMA&)rs << "  " << rs.color << std::endl;
	return os;
}

hasDMA::hasDMA(const char* s, const char* l, int r) :ABC_DMA(l, r)
{
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const ABC_DMA& rd)
{
	ABC_DMA::operator=(rd);
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA& hs)
{
	ABC_DMA::operator=(hs);
	style = new char[strlen(hs.style) + 1];
	strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA& hasDMA::operator=(const hasDMA& rs)
{
	if (&rs == this)
		return *this;
	delete[] style;
	ABC_DMA::operator=(rs);
	style = new char[strlen(rs.style) + 1];
	strcpy(style, rs.style);

	return *this;
}
std::ostream& operator<<(std::ostream& os, const hasDMA& hs)
{
	os << (const ABC_DMA&)hs << "  " << hs.style << std::endl;
	return os;
}