#include "MemoryMonster.h"
#include <random>
#include <string>
#include <iostream>

std::default_random_engine dre;
std::uniform_int_distribution<>uid('a', 'z');

MemoryMonster::MemoryMonster(int n) : num{ n }//������
{
	p = new char[num];

	for (int i = 0; i < num; ++i)
		p[i] = uid(dre);
	//std::cout << "������(int) - " << this << ", �Ҵ� �޸� - " << (void*)p << std::endl; 
	//�������� �������� void*��� ĳ�����������. char*�� �Ǿ��־ ��������

}

MemoryMonster::~MemoryMonster()
{
	//std::cout << "�Ҹ��� - " << this << ", �Ҵ� �޸� - " << (void*)p << std::endl; 
	//�������� �������� void*��� ĳ�����������. char*�� �Ǿ��־ ��������

	if (p != nullptr)
		delete[] p;
}

MemoryMonster& MemoryMonster::operator=(const MemoryMonster& other) {

	//std::cout << "�����Ҵ�" << std::endl;
	if (this == &other)
		return *this;

	delete[] p;
	p = new char[num];
	memcpy(p, other.p, num);
	return *this;
}

MemoryMonster::MemoryMonster(const MemoryMonster& other) : num(other.num)//��������
{
	p = new char[num];
	memcpy(p, other.p, num);
	//std::cout << "��������� - " << this << ", ���� " << &other << ", �Ҵ� �޸� - " << (void*)p << std::endl; 
	//�������� �������� void*��� ĳ�����������. char*�� �Ǿ��־ ��������

}

MemoryMonster::MemoryMonster(MemoryMonster&&other) : num{ other.num }//�̵� ������
{
	p = other.p;
	other.p = nullptr;
	other.num = 0;
	//std::cout << "�̵� ������ - " << this << ", ���� " << &other << ", �Ҵ� �޸� - " << (void*)p << std::endl; 
	//�������� �������� void*��� ĳ�����������. char*�� �Ǿ��־ ��������

}

void MemoryMonster::reset(int n) {
	//�̹� Ȯ���� �޸𸮸� ������
	if (p != nullptr)
		delete[] p;
	//�޸𸮸� n�� ���� ��´�
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
	//std::cout << "�̵��Ҵ�" << std::endl;
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