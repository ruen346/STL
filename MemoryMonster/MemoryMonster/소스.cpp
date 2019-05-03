#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
#include "MemoryMonster.h"
#include "save.h"

int main()
{
	// 앨리스.txt의 모든 단어를 multiset에 읽어라.

	ifstream in("앨리스.txt");

	multiset<string> words{ istream_iterator<string> { in } ,istream_iterator<string> {} };
	cout << words.size();

	multimap<int, string, greater<int>> mm;

	for (auto i = words.begin(); i != words.end(); i = words.upper_bound(*i))
		mm.emplace(words.count(*i), *i);


	// 갯수가 가장 많은 단어부터 20개를 출력해 보라
	auto p = mm.begin();;
	for (int i = 0; i < 20; ++i, ++p)
		cout << p->second << " ---> " << p->first << endl;

	save("소스.cpp");
}