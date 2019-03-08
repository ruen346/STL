#include <iostream>
#include <random>
#include "class2_save.h"

int a2[10000000];

int main()
{
	// 정수 10개를 생성하여 정렬해 보자
	int a[] {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

	sort(begin(a), end(a));

	for (int d : a)
		cout << d << " ";
	cout << endl;
	
	sort(begin(a), end(a), [](int a, int b) { return a > b; });

	for (int d : a)
		cout << d << " ";
	cout << endl;


	// 정수 1000개를 랜덤으로 생성하여 정렬해보자
	// { } 이 안에 들어있는 것을 지역안으로 한다.
	uniform_int_distribution<> uid(0, 10000);
	default_random_engine dre;
	
	for (int& d : a2)
		d = uid(dre);

	sort(begin(a2), end(a2));

	for (int d : a2)
		cout << d << " ";
	cout << endl;


	////////////////////////////////
	save("class2.cpp");
}