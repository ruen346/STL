#include <iostream>
#include <vector>
#include "MemoryMonster.h"
#include "save.h"

#include <iterator>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

// 입력 : 소스.cpp
// 출력 : 거꾸로소스.cpp
// 변신 : 소스.cpp의 단어를 역순으로 기록한다
// 공백(white space)까지 처라하려면 istreambuf_iterator, ostreambuf_iterator 사용
int main()
{
	ifstream in("소스.cpp");

	string a("abcdefg xyz");
	copy(a.begin(), a.end(), ostreambuf_iterator<char>(cout));
	cout << endl;
	copy(a.rbegin(), a.rend(), ostreambuf_iterator<char>(cout));

	vector<string> v{ istreambuf_iterator<string>(in), istreambuf_iterator<string>() };
	/*
	vector<char> v{istreambuf_iterator<char>(in), istreambuf_iterator<char>()};
	auto p = remove_if(v.begin(), v.end(), [](const char c) 
	{
		if (c == 'e')
			return true;
		return false;
	});

	v.erase(p, v.end());
	*/
	
	//ofstream out("거꾸로소스.cpp");
	//copy(v.begin(), v.end(), ostreambuf_iterator<char>(out));

	in.close();

	//save("소스.cpp");
}