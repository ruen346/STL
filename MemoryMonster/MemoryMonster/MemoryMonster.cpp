#include "MemoryMonster.h"
using namespace std;

default_random_engine dre;
uniform_int_distribution<>uid('a', 'z');

MemoryMonster::MemoryMonster(int n) : num{ n }
{
	p = new char[num];

	for (int i = 0; i < num; ++i)
		p[i] = uid(dre);
}

MemoryMonster::~MemoryMonster()
{
	cout << "¼Ò¸êÀÚ - " << this << endl;
	if (p)
		delete[] p;
}

MemoryMonster& MemoryMonster::operator=(const MemoryMonster& other) {
	if (this == &other)
		return *this;

	delete[] p;
	p = new char[num];
	memcpy(p, other.p, num);
	return *this;
}

MemoryMonster::MemoryMonster(const MemoryMonster& other) : num(other.num)
{
	p = new char[num];
	memcpy(p, other.p, num);
}

MemoryMonster::MemoryMonster(MemoryMonster&&other) : num{ other.num }
{
	p = other.p;
	other.p = nullptr;
	other.num = 0;
}

void MemoryMonster::set(int n) {
	num = n;
	p = new char[num];

	for (int i = 0; i < num; ++i)
		p[i] = uid(dre);
}

int MemoryMonster::get() const {
	return num;
}


MemoryMonster& MemoryMonster::operator=(MemoryMonster&& other) {
	delete[] p;
	num = other.num;
	p = other.p;
	other.p = nullptr;
	other.num = 0;

	return other;
}

ostream& operator<<(ostream& os, const MemoryMonster& mm)
{
	for (int i = 0; i < mm.num; ++i)
		os << mm.p[i];
	return os;
}