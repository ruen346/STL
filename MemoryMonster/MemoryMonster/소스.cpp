#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
// #include <initializer_list>
#include <array>
#include "MemoryMonster.h"
#include "save.h"

// 62p 1번문제
// std::string 객체로 된 배열을 정의하고, 자신이 선택한 단어들로 초기화한 후
// 반복자를 사용해 배열의 내용을 한 줄에 하나씩 출력하는 프로그램을 작성하라


int main()
{
	array<MemoryMonster, 5> a{ 10,3,30,7,20 };

	// a의 각 원소를 오름차순으로 정렬하라

	cout << a[0];
}