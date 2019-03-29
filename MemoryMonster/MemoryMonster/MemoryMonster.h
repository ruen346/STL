#pragma once
//---------------------------------------------------------
// MemoryMonster.h
//
// �޸𸮸��Ҹ��ϴ� MemotyMonster Ŭ������ �ִ�
// ������ ���ڷ� �޾� �� ���ڸ�ŭ ���̺� �Ѵ�.
//---------------------------------------------------------
#include <random>
using namespace std;



class MemoryMonster {
private:
	int num{ 0 };
	char *p{ nullptr };

public:
	int getNum() const; //Ȯ���� �޸� ������ �˷��ش�
	char* getData() const; // Ȯ���� �޸��� ��ġ�� �˸���

	void reset(int n); // ���� �޸𸮸� ������ n�� ��ŭ �� �޸𸮸� Ȯ���Ѵ�

	MemoryMonster() = default;

	MemoryMonster(int n);

	~MemoryMonster();

	MemoryMonster(const MemoryMonster& other);

	MemoryMonster& operator=(const MemoryMonster& other);

	MemoryMonster(MemoryMonster&&other);

	MemoryMonster& operator=(MemoryMonster&& other);

	friend ostream& operator<<(ostream&, const MemoryMonster&);
};