#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
// #include <initializer_list>
#include <array>
#include "MemoryMonster.h"
#include "save.h"

// 62p 1������
// std::string ��ü�� �� �迭�� �����ϰ�, �ڽ��� ������ �ܾ��� �ʱ�ȭ�� ��
// �ݺ��ڸ� ����� �迭�� ������ �� �ٿ� �ϳ��� ����ϴ� ���α׷��� �ۼ��϶�


int main()
{
	array<MemoryMonster, 5> a{ 10,3,30,7,20 };

	// a�� �� ���Ҹ� ������������ �����϶�

	cout << a[0];
}