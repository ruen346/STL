#include <iostream>
#include <vector>
#include "MemoryMonster.h"
#include "save.h"
using namespace std;

uniform_int_distribution<> uid2(10, 70);
default_random_engine dre2;

// 2장 순차 컨테이너 (sequence container, (homogeneous data type만 담는다))
//   array : smart 배열, []를 완벽하게 대체한다
// - vector
//   deque
//   list
//   forward_list

// MemoryMonster 20개를 만들어 vector에 넣어라
// 초기값은 uid(10,70)로 만들어라
// vector를 .getNum() 오름차순으로 정렬하라
// 결과를 화면 출력한다

int main()
{
	//교수님이 만듬
	vector<MemoryMonster> v;
	v.reserve(20); // 20개 예약함, <엄청 빨라져서 중요함!!!!☆★>

	for(int i=0; i<20; ++i)
		v.push_back(uid2(dre2));

	sort(v.begin(), v.end(), 
		[](const MemoryMonster& a, const MemoryMonster& b)
		{return a.getNum() < b.getNum(); }
	);

	for (const MemoryMonster& a : v)
		cout << a << endl;

	save("소스.cpp");
}