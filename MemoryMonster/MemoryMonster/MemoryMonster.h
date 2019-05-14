#pragma once
//---------------------------------------------------------
// MemoryMonster.h
//
// 메모리를소모하는 MemotyMonster 클래스가 있다
// 정수를 인자로 받아 그 숫자만큼 세이브 한다.
//---------------------------------------------------------
#include <random>
using namespace std;
#include <iterator>

class MemoryMonster;

// 내가만든 MemoryMonster의 역반복자를
// 표준 반복자로 만들려면 반복자에 필요한 타입 5가지를 정의하여야 한다
// 표준 반복자를 상속받는 것이 편하다

class revIter : public std::iterator<std::random_access_iterator_tag, char>
{
	char* p;
public:
	revIter(char* p) : p{ p } {};
	revIter operator++()
	{
		--p;
		return *this;
	};
	revIter operator++(int)
	{
		revIter temp{ *this };
		--p;
		return temp;
	};

	revIter operator--()
	{
		++p;
		return *this;
	};
	revIter operator--(int)
	{
		revIter temp{ *this };
		++p;
		return temp;
	};

	bool operator!=(const revIter& other) const
	{
		return p != other.p;
	}

	bool operator==(const revIter& other) const
	{
		return p == other.p;
	}

	char operator*()
	{
		return *(p-1);
	}

	std::ptrdiff_t operator-(const revIter& other) const
	{
		return p - other.p;
	}
	
	char* operator+(std::ptrdiff_t n) const
	{
		return p + n;
	}

	char* operator-(std::ptrdiff_t n) const
	{
		return p - n;
	}

	bool operator<(const revIter& other) const
	{
		return *p < *(other.p);
	}
};


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

	bool operator == (const MemoryMonster& rhs) const;

	bool operator<(const MemoryMonster& rhs) const;

	// typedef char* iterator; 구식
	using iterator = char*; // 신식

	using reverse_iterator = revIter;
	using value_type = char;

	iterator begin();
	iterator end();

	reverse_iterator rbegin();
	reverse_iterator rend();
};