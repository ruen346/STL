#include "MemoryMonster.h"
#include <random>
#include <iostream>

std::default_random_engine dre;
std::uniform_int_distribution<>uid('a', 'z');

MemoryMonster::MemoryMonster(int n) : num{ n }//������
{
	p = new char[num];

	for (int i = 0; i < num; ++i)
		p[i] = uid(dre);
	std::cout << "������(int) - " << this << ", �Ҵ� �޸� - " << (void*)p << std::endl; 
	//�������� �������� void*��� ĳ�����������. char*�� �Ǿ��־ ��������

}

MemoryMonster::~MemoryMonster()
{
	std::cout << "�Ҹ��� - " << this << ", �Ҵ� �޸� - " << (void*)p << std::endl; 
	//�������� �������� void*��� ĳ�����������. char*�� �Ǿ��־ ��������

	if (p != nullptr)
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

MemoryMonster::MemoryMonster(const MemoryMonster& other) : num(other.num)//��������
{
	p = new char[num];
	memcpy(p, other.p, num);
	std::cout << "��������� - " << this << ", ���� " << &other << ", �Ҵ� �޸� - " << (void*)p << std::endl; 
	//�������� �������� void*��� ĳ�����������. char*�� �Ǿ��־ ��������

}

MemoryMonster::MemoryMonster(MemoryMonster&&other) : num{ other.num }//�̵� ������
{
	p = other.p;
	other.p = nullptr;
	other.num = 0;
	std::cout << "�̵� ������ - " << this << ", ���� " << &other << ", �Ҵ� �޸� - " << (void*)p << std::endl; 
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