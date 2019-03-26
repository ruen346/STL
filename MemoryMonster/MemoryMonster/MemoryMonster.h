#pragma once
//---------------------------------------------------------
// MemoryMonster.h
//
// 메모리를소모하는 MemotyMonster 클래스가 있다
// 정수를 인자로 받아 그 숫자만큼 세이브 한다.
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