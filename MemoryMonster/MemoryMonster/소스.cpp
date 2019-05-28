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

// 7. �پ��� �˰���
//    - �� �˰����� �̸��� �о���� ����� �� �� �ִ�.

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

	cout << "v�� ������ " << my_distance(v.begin(), v.end()) << endl;

	list<int> l{ 1,2,3,4,5 };
	cout << "l�� ������ " << my_distance(l.begin(), l.end()) << endl;

	save("�ҽ�.cpp");
}