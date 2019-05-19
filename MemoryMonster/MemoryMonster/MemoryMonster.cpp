#include "MemoryMonster.h"
#include <random>
#include <string>
#include <iostream>

std::default_random_engine dre;
std::uniform_int_distribution<>uid('a', 'z');

MemoryMonster::MemoryMonster(int n) : num{ n }//생성자
{
	p = new char[num];

	for (int i = 0; i < num; ++i)
		p[i] = uid(dre);
	//std::cout << "생성자(int) - " << this << ", 할당 메모리 - " << (void*)p << std::endl; 
	//번지수를 적으려면 void*라고 캐스팅해줘야해. char*로 되어있어서 내용적음

}

MemoryMonster::~MemoryMonster()
{
	//std::cout << "소멸자 - " << this << ", 할당 메모리 - " << (void*)p << std::endl; 
	//번지수를 적으려면 void*라고 캐스팅해줘야해. char*로 되어있어서 내용적음

	if (p != nullptr)
		delete[] p;
}

MemoryMonster& MemoryMonster::operator=(const MemoryMonster& other) {

	//std::cout << "복사할당" << std::endl;
	if (this == &other)
		return *this;

	delete[] p;
	p = new char[num];
	memcpy(p, other.p, num);
	return *this;
}

MemoryMonster::MemoryMonster(const MemoryMonster& other) : num(other.num)//깊은복사
{
	p = new char[num];
	memcpy(p, other.p, num);
	//std::cout << "복사생성자 - " << this << ", 원본 " << &other << ", 할당 메모리 - " << (void*)p << std::endl; 
	//번지수를 적으려면 void*라고 캐스팅해줘야해. char*로 되어있어서 내용적음

}

MemoryMonster::MemoryMonster(MemoryMonster&&other) : num{ other.num }//이동 생성자
{
	p = other.p;
	other.p = nullptr;
	other.num = 0;
	//std::cout << "이동 생성자 - " << this << ", 원본 " << &other << ", 할당 메모리 - " << (void*)p << std::endl; 
	//번지수를 적으려면 void*라고 캐스팅해줘야해. char*로 되어있어서 내용적음

}

void MemoryMonster::reset(int n) {
	//이미 확보한 메모리를 버린다
	if (p != nullptr)
		delete[] p;
	//메모리를 n개 새로 잡는다
	num = n;
	p = new char[num];
	for (int i = 0; i < num; ++i)
		p[i] = uid(dre);

}

int MemoryMonster::getNum() const {
	return num;
}

char* MemoryMonster::getData() const {
	return p;
}

MemoryMonster& MemoryMonster::operator=(MemoryMonster&& other) {
	//std::cout << "이동할당" << std::endl;
	delete[] p;
	num = other.num;
	p = other.p;
	other.p = nullptr;
	other.num = 0;

	return other;
}

std::ostream& operator<<(std::ostream& os, const MemoryMonster& mm)
{
	for (int i = 0; i < mm.num; ++i)
		os << mm.p[i];
	return os;
}

bool MemoryMonster::operator == (const MemoryMonster& rhs) const
{
	if (std::string(p) == std::string(rhs.p))
		return true;
	return false;
}

bool MemoryMonster::operator<(const MemoryMonster& rhs) const
{
	if (num == rhs.num)
		return true;
	return false;
}

Iter MemoryMonster::begin()
{
	return Iter(p);
}

Iter MemoryMonster::end()
{
	return Iter(p + num);
}