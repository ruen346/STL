#include <iostream>
#include "MemoryMonster.h"
#include "save.h"
using namespace std;
#include <map>
#include <algorithm>
#include <unordered_map>
#include <chrono>
#include <random>
#include <vector>
using namespace std::chrono;

// 정수 1000만개를 unorderde_map과 map에 저장한다
// 임의의 정수 100만개가 컨테이너에 있는 지 찾아본다
// 각각 걸리는 시간을 측정한다

int main()
{
	// 정수 1000만개를 map에 넣는다.
	map<int, int> m;

	default_random_engine dre;
	uniform_int_distribution<> uid;

	int i{};
	while( m.size() != 1000'0000)
		m.emplace(uid(dre), ++i);

	cout << "map 생성" << m.size() << endl;

	// map의 원소를 그대로 unordered_map에 넣는다

	unordered_map<int, int> um{ m.begin(), m.end() };
	cout << "unordered map 생성" << um.size() << endl;

	// 찾을 값 100만개를 vector에 저장한다

	cout << "백터에 인덱스 100만개를 생성하였다" << endl;
	vector<int> v;
	v.reserve(100'0000);
	for (int i = 0; i < 100'0000; ++i)
	{
		v.push_back(uid(dre));
	}

	{
		cout << "임의의 정수 100만개를 map에서 찾아보자" << endl;
		cout << "찾기 시작" << endl;

		auto b = steady_clock::now();

		for (int i = 0; i < 100'0000; ++i)
			m.find(v[i]);

		auto d = duration_cast<milliseconds>(steady_clock::now() - b).count();

		cout << "걸린 시간은 - " << d << endl;
	}

	{
		cout << "임의의 정수 100만개를 unordered map에서 찾아보자" << endl;
		cout << "찾기 시작" << endl;

		auto b = steady_clock::now();

		for (int i = 0; i < 100'0000; ++i)
			um.find(v[i]);

		auto d = duration_cast<milliseconds>(steady_clock::now() - b).count();

		cout << "걸린 시간은 - " << d << endl;
	}


	//save("소스.cpp");
}