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

// ���� 1000������ unorderde_map�� map�� �����Ѵ�
// ������ ���� 100������ �����̳ʿ� �ִ� �� ã�ƺ���
// ���� �ɸ��� �ð��� �����Ѵ�

int main()
{
	// ���� 1000������ map�� �ִ´�.
	map<int, int> m;

	default_random_engine dre;
	uniform_int_distribution<> uid;

	int i{};
	while( m.size() != 1000'0000)
		m.emplace(uid(dre), ++i);

	cout << "map ����" << m.size() << endl;

	// map�� ���Ҹ� �״�� unordered_map�� �ִ´�

	unordered_map<int, int> um{ m.begin(), m.end() };
	cout << "unordered map ����" << um.size() << endl;

	// ã�� �� 100������ vector�� �����Ѵ�

	cout << "���Ϳ� �ε��� 100������ �����Ͽ���" << endl;
	vector<int> v;
	v.reserve(100'0000);
	for (int i = 0; i < 100'0000; ++i)
	{
		v.push_back(uid(dre));
	}

	{
		cout << "������ ���� 100������ map���� ã�ƺ���" << endl;
		cout << "ã�� ����" << endl;

		auto b = steady_clock::now();

		for (int i = 0; i < 100'0000; ++i)
			m.find(v[i]);

		auto d = duration_cast<milliseconds>(steady_clock::now() - b).count();

		cout << "�ɸ� �ð��� - " << d << endl;
	}

	{
		cout << "������ ���� 100������ unordered map���� ã�ƺ���" << endl;
		cout << "ã�� ����" << endl;

		auto b = steady_clock::now();

		for (int i = 0; i < 100'0000; ++i)
			um.find(v[i]);

		auto d = duration_cast<milliseconds>(steady_clock::now() - b).count();

		cout << "�ɸ� �ð��� - " << d << endl;
	}


	//save("�ҽ�.cpp");
}