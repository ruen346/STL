#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
// #include <initializer_list>
#include <array>
#include "MemoryMonster.h"
#include "save.h"

// 2장 순차 컨테이너
// - array
// - vector
// - deque
// - list
// - forward_list


int main()
{
	array<MemoryMonster, 5> a{10,3,30,7,20};

	// a의 각 원소를 오름차순으로 정렬하라

	for (int i = 0; i < a.size(); i++)
	{
		char* p = a[i].getP();
		sort(p, p + a[i].get());

		cout << a[i] << endl;
	}

	save("소스.cpp");
}