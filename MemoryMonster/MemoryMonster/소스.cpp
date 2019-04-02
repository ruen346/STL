#include <iostream>
#include <vector>
#include "MemoryMonster.h"
#include "save.h"

#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

// 2�� ���� �����̳� (sequence container, (homogeneous data type�� ��´�))
//   array : smart �迭, []�� �Ϻ��ϰ� ��ü�Ѵ�
// - vector
//   deque
//   list
//   forward_list

// �Է��ڷᱸ�� - Ű����
// ����ڷᱸ�� - ȭ��

// Ű���忡�� string�� �о� ������������ �����Կ� ����϶�.
// �ҽ�.cpp���� char�� �о� ������������ �����Ͽ� ����϶�.

int main()
{
	vector<char> v{ istream_iterator<char>(cin), istream_iterator<char>() };

	copy(v.begin(), v.end(), ostream_iterator<char>(cout));

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;

	
	save("�ҽ�.cpp");

}