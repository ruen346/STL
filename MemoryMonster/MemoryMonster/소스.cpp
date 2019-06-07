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

// 학과 자료실에서 단어들.zip을 받자

// 1. 사용자가 입력한 단어가 단어들에 있는지 확인한다
// 2. 있다면 
//		입력한 단어와 anagram 관계인 단어를 모두 찾아 화면에 출력한다
// 3. 단어들.txt에 있는 모든 단어에서 서로 anagram 관계인 들어들을 출력한다.
// 4. anagram 쌍은 몇 개가 있는지 출력한다.
// 5. 가장 갯수가 많은 angram 쌍은 무엇인가?

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


	// anagram 쌍을 단어 갯수 내림 차순으로 정렬하여 파일에 기록하라
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

		// [i, j]는 애너그램 쌍이다.
		list<string> t;

		for (auto k = i; k < j; ++k)
			 t.push_back(k->second);

		vl.push_back(t);

		i = j;
	}

	// cout << idx - 1 << "개의 애너그램 쌍을 찾았습니다" << endl;

	sort(vl.begin(), vl.end(), [](const list<string>& a, const list<string>& b)
	{
		return a.size() > b.size();
	});

	ofstream out("애너그램 길이순서.txt");

	for (const list<string>& d : vl)
	{
		for (const string& s : d)
		{
			out << s << " ";
		}
		out << endl;
	}

	out << "제일 갯수가 많은 쌍은 " << vl[0].size() << endl;


	/*
	while (true)
	{
		cout << "찾을 단어 : "; string s; cin >> s;
		PS ps{ s };

		cout << ps.first << " --- " << ps.second << endl;

		if (binary_search(v.begin(), v.end(), ps, [](const PS& a, const PS& b) 
		{
			return a.first < b.first;
		}))
		{
			cout << "사전에 있다" << endl;
		}
		else
		{
			cout << "사전에 없다" << endl;
		}
		cout << endl;
	}
	*/


	save("소스.cpp");
}

void readData()
{
	ifstream in("단어들.txt");

	string s;
	while (in >> s)
		v.push_back(s);

	cout << "모두 " << v.size() << "개의 단어를 읽었습니다" << endl << endl;
}