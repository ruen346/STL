#pragma once
//---------------------------------------------------------
// MemoryMonster.h
//
// �޸𸮸��Ҹ��ϴ� MemotyMonster Ŭ������ �ִ�
// ������ ���ڷ� �޾� �� ���ڸ�ŭ ���̺� �Ѵ�.
//---------------------------------------------------------
#include <random>
using namespace std;
#include <iterator>

class MemoryMonster;

// �������� MemoryMonster�� ���ݺ��ڸ�
// ǥ�� �ݺ��ڷ� ������� �ݺ��ڿ� �ʿ��� Ÿ�� 5������ �����Ͽ��� �Ѵ�
// ǥ�� �ݺ��ڸ� ��ӹ޴� ���� ���ϴ�

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

	bool operator == (const MemoryMonster& rhs) const;

	bool operator<(const MemoryMonster& rhs) const;

	// typedef char* iterator; ����
	using iterator = char*; // �Ž�

	using reverse_iterator = revIter;
	using value_type = char;

	iterator begin();
	iterator end();

	reverse_iterator rbegin();
	reverse_iterator rend();
};