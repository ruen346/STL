#include "MemoryMonster.h"

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
	//std::cout << "소멸자 - " << this << endl;
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

void MemoryMonster::reset(int n) 
{
	// 이미 확보한 메모리는 해제한다
	if (p != nullptr)
		delete[] p;

	num = n;
	p = new char[num];

	for (int i = 0; i < num; ++i)
		p[i] = uid(dre);
}

int MemoryMonster::getNum() const 
{
	return num;
}

char* MemoryMonster::getData() const 
{
	return p;
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