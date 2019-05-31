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

// �а� �ڷ�ǿ��� �ܾ��.zip�� ����

// 1. ����ڰ� �Է��� �ܾ �ܾ�鿡 �ִ��� Ȯ���Ѵ�
// 2. �ִٸ� 
//		�Է��� �ܾ�� anagram ������ �ܾ ��� ã�� ȭ�鿡 ����Ѵ�
// 3. �ܾ��.txt�� �ִ� ��� �ܾ�� ���� anagram ������ ������ ����Ѵ�.
// 4. anagram ���� �� ���� �ִ��� ����Ѵ�.
// 5. ���� ������ ���� angram ���� �����ΰ�?

void readData();

vector<string> v;

int main()
{
	readData(); 
	
	while (true)
	{
		cout << "Anagram ã���� �ܾ �Է����ּ��� : ";
		string s;
		cin >> s;

		bool b = binary_search(v.begin(), v.end(), s);

		if (b)
		{
			cout << s << "�� anagram�� ã�� ��..." << endl;

			string sc{ s };

			do
			{
				next_permutation(sc.begin(), sc.end());

				cout << sc << "\r";

				if (binary_search(v.begin(), v.end(), sc))
					cout << sc << " ";
			} while (s != sc);
			cout << endl << endl;
		}
		else
			cout << s << "�� ������ ���� �ܾ��Դϴ�" << endl << endl;
	}
	

	// save("�ҽ�.cpp");
}

void readData()
{
	ifstream in("�ܾ��.txt");

	string s;
	while (in >> s)
		v.push_back(s);

	cout << "��� " << v.size() << "���� �ܾ �о����ϴ�" << endl << endl;
}