#include <iostream>
#include "MemoryMonster.h"
#include "save.h"
#include <map>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
using namespace std;

// Associative Container (���� �����̳�)
//	map - dirctionay <key, value> ���� ����
//	set - <key>�� ����
//
// Unordered Associative Contaiiner (�������� ���� �����̳�, Hash)
//	Unordered_map
//	Unordered_set

// �ҽ�.cpp�� �� ���ĺ��� �� �� ���Ǿ��� ����϶�

int main()
{
	map<char, int> cb;

	ifstream in("�ҽ�.cpp");
	for (auto i = istream_iterator<char>(in); i != istream_iterator<char>(); ++i)
	{
		if(isalpha(*i))
			cb[*i]++;
	}

	// ���
	auto p = cb.cbegin();
	for (int i = 0; i < cb.size(); ++i)
		cout << "[" << p->first << "] ---> " << p->second << endl;

	save("�ҽ�.cpp");
}