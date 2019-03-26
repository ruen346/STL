#pragma once
//---------------------------------------------------------
// MemoryMonster.h
//
// �޸𸮸��Ҹ��ϴ� MemotyMonster Ŭ������ �ִ�
// ������ ���ڷ� �޾� �� ���ڸ�ŭ ���̺� �Ѵ�.
//---------------------------------------------------------
#include <random>
#include "save.h"
using namespace std;



class MemoryMonster {
private:
	int num{ 0 };
	char *p{ nullptr };

public:

	MemoryMonster() = default;

	MemoryMonster(int n);

	~MemoryMonster();

	MemoryMonster(const MemoryMonster& other);

	MemoryMonster& operator=(const MemoryMonster& other);

	MemoryMonster(MemoryMonster&&other);

	MemoryMonster& operator=(MemoryMonster&& other);

	void set(int n);

	int get() const;

	friend ostream& operator<<(ostream&, const MemoryMonster&);
};