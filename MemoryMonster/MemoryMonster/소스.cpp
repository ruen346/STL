#include <iostream>
#include <list>
#include "MemoryMonster.h"
#include "save.h"
using namespace std;

// 2장 순차 컨테이너 (sequence container, (homogeneous data type만 담는다))
//   array : smart 배열, []를 완벽하게 대체한다
//   vector
//   deque : double-ended queue, 덱
// - list : 이후 컨테이너는 원소보다 더 큰 메모리를 사용한다
//   forward_list

// list에 MemoryMonster 3개를 추가해보세요
// 각 원소를 출력해보세요

int main()
{
	list<MemoryMonster> monsters{ 10, 20, 30, 3, 40, 50 };

	// 리스트에서 길이가 10보다 작은 원소를 제거하라.
	monsters.remove_if();

	for (MemoryMonster& mon : monsters)
		cout << mon << endl;

	save("소스.cpp");
}