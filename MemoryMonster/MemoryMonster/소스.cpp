#include <iostream>
#include <string>
#include "MemoryMonster.h"
#include "save.h"
using namespace std;

// 62p 1������
// std::string ��ü�� �� �迭�� �����ϰ�, �ڽ��� ������ �ܾ��� �ʱ�ȭ�� ��
// �ݺ��ڸ� ����� �迭�� ������ �� �ٿ� �ϳ��� ����ϴ� ���α׷��� �ۼ��϶�


int main()
{
	string s[5]{"3��", "22��", "MT", "���Ÿ��", "�̼���������"};

	auto b = begin(s);

	while (b != end(s))
	{
		cout << *b << endl;		
		++b;
	}

	save("�ҽ�.cpp");
}