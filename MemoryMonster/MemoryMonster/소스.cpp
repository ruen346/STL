#include <iostream>
#include "MemoryMonster.h"
#include "save.h"
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

// 2�� ���� �����̳� (sequence container, (homogeneous data type�� ��´�))
//   array : smart �迭, []�� �Ϻ��ϰ� ��ü�Ѵ�
//   vector : dynamic array (STL ���Ǽ���)
//   deque : double-ended queue, ��
//   list : ���� �����̳ʴ� ���Һ��� �� ū �޸𸮸� ����Ѵ�
//   forward_list

// Ű���忡�� �ܾ �о�� �������� ����϶�
// ex) �ȳ� �ϼ��� -> �ϼ��� �ȳ�

int main()
{
	vector<string> v;

	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(v));

	for (auto i = v.crbegin(); i < v.crend(); ++i)
		cout << *i << endl;

	save("�ҽ�.cpp");
}