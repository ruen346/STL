#include <iostream>
#include <vector>
#include "MemoryMonster.h"
#include "save.h"

#include <iterator>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

// �Է� : �ҽ�.cpp
// ��� : �Ųٷμҽ�.cpp
// ���� : �ҽ�.cpp�� �ܾ �������� ����Ѵ�
// ����(white space)���� ó���Ϸ��� istreambuf_iterator, ostreambuf_iterator ���
int main()
{
	ifstream in("�ҽ�.cpp");

	string a("abcdefg xyz");
	copy(a.begin(), a.end(), ostreambuf_iterator<char>(cout));
	cout << endl;
	copy(a.rbegin(), a.rend(), ostreambuf_iterator<char>(cout));

	vector<string> v{ istreambuf_iterator<string>(in), istreambuf_iterator<string>() };
	/*
	vector<char> v{istreambuf_iterator<char>(in), istreambuf_iterator<char>()};
	auto p = remove_if(v.begin(), v.end(), [](const char c) 
	{
		if (c == 'e')
			return true;
		return false;
	});

	v.erase(p, v.end());
	*/
	
	//ofstream out("�Ųٷμҽ�.cpp");
	//copy(v.begin(), v.end(), ostreambuf_iterator<char>(out));

	in.close();

	//save("�ҽ�.cpp");
}