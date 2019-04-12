#include <iostream>
#include <list>
#include "MemoryMonster.h"
#include "save.h"
#include <fstream>
#include <string>
using namespace std;

// 2장 순차 컨테이너 (sequence container, (homogeneous data type만 담는다))
//   array : smart 배열, []를 완벽하게 대체한다
//   vector
//   deque : double-ended queue, 덱
// - list : 이후 컨테이너는 원소보다 더 큰 메모리를 사용한다
//   forward_list

// "소스.cpp"에 있는 단어를 읽어
// 길이 순으로 정렬한다(default : ascending order)
// 길이가 4인 단어는 따로 빼서 "길이4.txt" 파일에 저장한다
// copy로 container에 원소를 읽어오기 - 반복자 어뎁터

int main()
{
	ifstream in("소스.cpp");
	
	list<string> words;
	istream_iterator<string> p(in);

	while (p != istream_iterator<string>())
		words.emplace(words.begin(), *p++);

	words.sort([](const string& a, const string& b)
	{
		return a.length() < b.length();
	});

	//길이가 4, 길이가 5인 위치를 찾는다
	auto pos4 = find_if(words.begin(), words.end(), [](const string& a)
	{
		return a.size() == 4;
	});
	if (pos4 == words.end())
		cout << "그럴리가 없는데" << endl;
	auto pos5 = find_if(words.begin(), words.end(), [](const string& a)
	{
		return a.size() == 5;
	});

	for (const string& str : words)
		cout << str << endl;
	cout << endl;

	// 4글자만 찍어줘
	for (auto i = pos4; i != pos5; ++i)
		cout << *i << endl;

	list<string> words_4;
	words_4.splice(words_4.begin(), words, pos4, pos5);

	ofstream out("길이4.txt");
	copy(words_4.begin(), words_4.end(), ostream_iterator<string>(out, "\n"));

	//save("소스.cpp");
}