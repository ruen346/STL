#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
#include "MemoryMonster.h"
#include "save.h"

int main()
{
	// �ٸ���.txt�� ��� �ܾ multiset�� �о��.

	ifstream in("�ٸ���.txt");

	multiset<string> words{ istream_iterator<string> { in } ,istream_iterator<string> {} };
	cout << words.size();

	multimap<int, string, greater<int>> mm;

	for (auto i = words.begin(); i != words.end(); i = words.upper_bound(*i))
		mm.emplace(words.count(*i), *i);


	// ������ ���� ���� �ܾ���� 20���� ����� ����
	auto p = mm.begin();;
	for (int i = 0; i < 20; ++i, ++p)
		cout << p->second << " ---> " << p->first << endl;

	save("�ҽ�.cpp");
}