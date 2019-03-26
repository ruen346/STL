#include <iostream>
#include <string>
#include "MemoryMonster.h"
#include "save.h"
using namespace std;

// 62p 1번문제
// std::string 객체로 된 배열을 정의하고, 자신이 선택한 단어들로 초기화한 후
// 반복자를 사용해 배열의 내용을 한 줄에 하나씩 출력하는 프로그램을 작성하라


int main()
{
	string s[5]{"3월", "22일", "MT", "베어스타운", "미세먼지없음"};

	auto b = begin(s);

	while (b != end(s))
	{
		cout << *b << endl;		
		++b;
	}

	save("소스.cpp");
}