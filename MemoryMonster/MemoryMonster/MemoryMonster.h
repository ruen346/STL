#pragma once
//---------------------------------------------------------
// MemoryMonster.h
//
// 메모리를소모하는 MemotyMonster 클래스가 있다
// 정수를 인자로 받아 그 숫자만큼 세이브 한다.
//---------------------------------------------------------
#include <random>
using namespace std;



class MemoryMonster {
private:
	int num{ 0 };
	char *p{ nullptr };

public:
	int getNum() const; //확보한 메모리 갯수를 알려준다
	char* getData() const; // 확보한 메모리의 위치를 알린다

	void reset(int n); // 기존 메모리를 버리고 n개 만큼 새 메모리를 확보한다

	MemoryMonster() = default;

	MemoryMonster(int n);

	~MemoryMonster();

	MemoryMonster(const MemoryMonster& other);

	MemoryMonster& operator=(const MemoryMonster& other);

	MemoryMonster(MemoryMonster&&other);

	MemoryMonster& operator=(MemoryMonster&& other);

	friend ostream& operator<<(ostream&, const MemoryMonster&);
};