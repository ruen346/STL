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

// 7. 다양한 알고리즘
//    - 이 알고리즘은 이름만 읽어봐도 기능을 알 수 있다.

template <class Iter>
int my_distance(Iter b, Iter e)
{
	int cnt();
	while (b++ != e)
		cnt++;
	return cnt;
}

int main()
{
	vector<int> v{ 1,2,3,4,5 };

	cout << "v의 갯수는 " << my_distance(v.begin(), v.end()) << endl;

	list<int> l{ 1,2,3,4,5 };
	cout << "l의 갯수는 " << my_distance(l.begin(), l.end()) << endl;

	save("소스.cpp");
}