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


	// anagram ���� �ܾ� ���� ���� �������� �����Ͽ� ���Ͽ� ����϶�
	auto i = v.begin();

	int idx;

	vector<list<string>>vl;
	vl.reserve(31000);

	while (true)
	{
		i = adjacent_find(i, v.end(), [](const PS& a, const PS& b)
		{
			return a.first == b.first;
		});

		if (i == v.end())
			break;

		auto j = find_if_not(i + 1, v.end(), [i](const PS& a)
		{
			return i->first == a.first;
		});

		// [i, j]�� �ֳʱ׷� ���̴�.
		list<string> t;

		for (auto k = i; k < j; ++k)
			 t.push_back(k->second);

		vl.push_back(t);

		i = j;
	}

	// cout << idx - 1 << "���� �ֳʱ׷� ���� ã�ҽ��ϴ�" << endl;

	sort(vl.begin(), vl.end(), [](const list<string>& a, const list<string>& b)
	{
		return a.size() > b.size();
	});

	ofstream out("�ֳʱ׷� ���̼���.txt");

	for (const list<string>& d : vl)
	{
		for (const string& s : d)
		{
			out << s << " ";
		}
		out << endl;
	}

	out << "���� ������ ���� ���� " << vl[0].size() << endl;


	/*
	while (true)
	{
		cout << "ã�� �ܾ� : "; string s; cin >> s;
		PS ps{ s };

		cout << ps.first << " --- " << ps.second << endl;

		if (binary_search(v.begin(), v.end(), ps, [](const PS& a, const PS& b) 
		{
			return a.first < b.first;
		}))
		{
			cout << "������ �ִ�" << endl;
		}
		else
		{
			cout << "������ ����" << endl;
		}
		cout << endl;
	}
	*/


	save("�ҽ�.cpp");
}

void readData()
{
	ifstream in("�ܾ��.txt");

	string s;
	while (in >> s)
		v.push_back(s);

	cout << "��� " << v.size() << "���� �ܾ �о����ϴ�" << endl << endl;
}