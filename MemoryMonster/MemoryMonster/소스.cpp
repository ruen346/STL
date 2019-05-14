#include <iostream>
#include "MemoryMonster.h"
#include "save.h"
using namespace std;
#include <vector>;

// STL 표준을 만족하는 
//	   반복자 만들기
//     컨테이너 만들기
// 표준 STL 컨테이너 처럼 동작하게 한다.

int main()
{
	MemoryMonster m{ 33 };
	copy(m.begin(), m.end(), ostream_iterator<char>(cout));
	cout << endl;

	auto p = find(m.begin(), m.end(), 'x');
	cout << distance(m.begin(), p) << "번째 글자입니다 " << endl;
	cout << *p << endl;

	sort(m.rbegin(), m.rend());

	for (char c : m)
		cout << c;
	cout << endl;

	//save("소스.cpp");
}