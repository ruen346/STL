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

	// 모든 anagram 쌍을 찾아 파일에 기록하라.
	auto p = adjacent_find(v.begin(), v.end(), [](const PS& a, const PS& b)
	{
		return a.first == b.first;
	});

	for(int i = 0; i < 5; ++i, ++p)
		cout << p->first << " --- " << p->second << endl;

	// save("소스.cpp");
}

void readData()
{
	ifstream in("단어들.txt");

	string s;
	while (in >> s)
		v.push_back(s);

	cout << "모두 " << v.size() << "개의 단어를 읽었습니다" << endl << endl;
}