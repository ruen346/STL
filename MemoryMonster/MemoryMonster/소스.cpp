#include <iostream>
#include "MemoryMonster.h"
#include "save.h"
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

// 2장 순차 컨테이너 (sequence container, (homogeneous data type만 담는다))
//   array : smart 배열, []를 완벽하게 대체한다
//   vector : dynamic array (STL 간판선수)
//   deque : double-ended queue, 덱
//   list : 이후 컨테이너는 원소보다 더 큰 메모리를 사용한다
//   forward_list

// 키보드에서 단어를 읽어와 역순으로 출력하라
// ex) 안녕 하세요 -> 하세요 안녕

int main()
{
	vector<string> v;

	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(v));

	for (auto i = v.crbegin(); i < v.crend(); ++i)
		cout << *i << endl;

	save("소스.cpp");
}