#include <iostream>
#include "MemoryMonster.h"
#include "save.h"
#include <map>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
using namespace std;

// Associative Container (연관 컨테이너)
//	map - dirctionay <key, value> 쌍이 원소
//	set - <key>가 원소
//
// Unordered Associative Contaiiner (순서없는 연관 컨테이너, Hash)
//	Unordered_map
//	Unordered_set

// 소스.cpp에 각 알파벳이 몇 번 사용되었나 출력하라

int main()
{
	map<char, int> cb;

	ifstream in("소스.cpp");
	for (auto i = istream_iterator<char>(in); i != istream_iterator<char>(); ++i)
	{
		if(isalpha(*i))
			cb[*i]++;
	}

	// 출력
	auto p = cb.cbegin();
	for (int i = 0; i < cb.size(); ++i)
		cout << "[" << p->first << "] ---> " << p->second << endl;

	save("소스.cpp");
}