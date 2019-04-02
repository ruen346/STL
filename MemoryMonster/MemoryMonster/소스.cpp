#include <iostream>
#include <vector>
#include "MemoryMonster.h"
#include "save.h"

#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

// 2장 순차 컨테이너 (sequence container, (homogeneous data type만 담는다))
//   array : smart 배열, []를 완벽하게 대체한다
// - vector
//   deque
//   list
//   forward_list

// 입력자료구조 - 키보드
// 출력자료구조 - 화면

// 키보드에서 string를 읽어 오름차순으로 정렬함여 출력하라.
// 소스.cpp에서 char을 읽어 오름차순으로 정렬하여 출력하라.

int main()
{
	vector<char> v{ istream_iterator<char>(cin), istream_iterator<char>() };

	copy(v.begin(), v.end(), ostream_iterator<char>(cout));

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;

	
	save("소스.cpp");

}