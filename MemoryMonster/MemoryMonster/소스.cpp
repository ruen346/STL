#include <iostream>
#include "MemoryMonster.h"
#include "save.h"
#include <algorithm>
using namespace std;
#include <vector>
#include <numeric>
#include <iomanip>
#include <random>
#include <string>
#include <list>

// �а� �ڷ�ǿ��� �ܾ��.zip�� ����

// 1. ����ڰ� �Է��� �ܾ �ܾ�鿡 �ִ��� Ȯ���Ѵ�
// 2. �ִٸ� 
//		�Է��� �ܾ�� anagram ������ �ܾ ��� ã�� ȭ�鿡 ����Ѵ�
// 3. �ܾ��.txt�� �ִ� ��� �ܾ�� ���� anagram ������ ������ ����Ѵ�.
// 4. anagram ���� �� ���� �ִ��� ����Ѵ�.
// 5. ���� ������ ���� angram ���� �����ΰ�?

void readData();

struct PS : pair<string, string>
{
	PS(string s) : pair(s, s) 
	{
		sort(first.begin(), first.end());
	}
};

vector<PS> v;

int main()
{
	readData(); 
	sort(v.begin(), v.end(), [](const PS& a, const PS& b)
	{
		return a.first < b.first;
	});

	// ��� anagram ���� ã�� ���Ͽ� ����϶�.
	auto p = adjacent_find(v.begin(), v.end(), [](const PS& a, const PS& b)
	{
		return a.first == b.first;
	});

	for(int i = 0; i < 5; ++i, ++p)
		cout << p->first << " --- " << p->second << endl;

	// save("�ҽ�.cpp");
}

void readData()
{
	ifstream in("�ܾ��.txt");

	string s;
	while (in >> s)
		v.push_back(s);

	cout << "��� " << v.size() << "���� �ܾ �о����ϴ�" << endl << endl;
}