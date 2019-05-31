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

// 학과 자료실에서 단어들.zip을 받자

// 1. 사용자가 입력한 단어가 단어들에 있는지 확인한다
// 2. 있다면 
//		입력한 단어와 anagram 관계인 단어를 모두 찾아 화면에 출력한다
// 3. 단어들.txt에 있는 모든 단어에서 서로 anagram 관계인 들어들을 출력한다.
// 4. anagram 쌍은 몇 개가 있는지 출력한다.
// 5. 가장 갯수가 많은 angram 쌍은 무엇인가?

void readData();

vector<string> v;

int main()
{
	readData(); 
	
	while (true)
	{
		cout << "Anagram 찾으실 단어를 입력해주세요 : ";
		string s;
		cin >> s;

		bool b = binary_search(v.begin(), v.end(), s);

		if (b)
		{
			cout << s << "의 anagram을 찾는 중..." << endl;

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
			cout << s << "는 사전에 없는 단어입니다" << endl << endl;
	}
	

	// save("소스.cpp");
}

void readData()
{
	ifstream in("단어들.txt");

	string s;
	while (in >> s)
		v.push_back(s);

	cout << "모두 " << v.size() << "개의 단어를 읽었습니다" << endl << endl;
}