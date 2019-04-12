#include <iostream>
#include <list>
#include "MemoryMonster.h"
#include "save.h"
#include <fstream>
#include <string>
using namespace std;

// 2�� ���� �����̳� (sequence container, (homogeneous data type�� ��´�))
//   array : smart �迭, []�� �Ϻ��ϰ� ��ü�Ѵ�
//   vector
//   deque : double-ended queue, ��
// - list : ���� �����̳ʴ� ���Һ��� �� ū �޸𸮸� ����Ѵ�
//   forward_list

// "�ҽ�.cpp"�� �ִ� �ܾ �о�
// ���� ������ �����Ѵ�(default : ascending order)
// ���̰� 4�� �ܾ�� ���� ���� "����4.txt" ���Ͽ� �����Ѵ�
// copy�� container�� ���Ҹ� �о���� - �ݺ��� ���

int main()
{
	ifstream in("�ҽ�.cpp");
	
	list<string> words;
	istream_iterator<string> p(in);

	while (p != istream_iterator<string>())
		words.emplace(words.begin(), *p++);

	words.sort([](const string& a, const string& b)
	{
		return a.length() < b.length();
	});

	//���̰� 4, ���̰� 5�� ��ġ�� ã�´�
	auto pos4 = find_if(words.begin(), words.end(), [](const string& a)
	{
		return a.size() == 4;
	});
	if (pos4 == words.end())
		cout << "�׷����� ���µ�" << endl;
	auto pos5 = find_if(words.begin(), words.end(), [](const string& a)
	{
		return a.size() == 5;
	});

	for (const string& str : words)
		cout << str << endl;
	cout << endl;

	// 4���ڸ� �����
	for (auto i = pos4; i != pos5; ++i)
		cout << *i << endl;

	list<string> words_4;
	words_4.splice(words_4.begin(), words, pos4, pos5);

	ofstream out("����4.txt");
	copy(words_4.begin(), words_4.end(), ostream_iterator<string>(out, "\n"));

	//save("�ҽ�.cpp");
}