#include <iostream>
#include <vector>
#include "MemoryMonster.h"
#include "save.h"
using namespace std;

uniform_int_distribution<> uid2(10, 70);
default_random_engine dre2;

// 2�� ���� �����̳� (sequence container, (homogeneous data type�� ��´�))
//   array : smart �迭, []�� �Ϻ��ϰ� ��ü�Ѵ�
// - vector
//   deque
//   list
//   forward_list

// MemoryMonster 20���� ����� vector�� �־��
// �ʱⰪ�� uid(10,70)�� ������
// vector�� .getNum() ������������ �����϶�
// ����� ȭ�� ����Ѵ�

int main()
{
	//�������� ����
	vector<MemoryMonster> v;
	v.reserve(20); // 20�� ������, <��û �������� �߿���!!!!�١�>

	for(int i=0; i<20; ++i)
		v.push_back(uid2(dre2));

	sort(v.begin(), v.end(), 
		[](const MemoryMonster& a, const MemoryMonster& b)
		{return a.getNum() < b.getNum(); }
	);

	for (const MemoryMonster& a : v)
		cout << a << endl;

	save("�ҽ�.cpp");
}