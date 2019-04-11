#include <iostream>
#include <list>
#include "MemoryMonster.h"
#include "save.h"
using namespace std;

// 2�� ���� �����̳� (sequence container, (homogeneous data type�� ��´�))
//   array : smart �迭, []�� �Ϻ��ϰ� ��ü�Ѵ�
//   vector
//   deque : double-ended queue, ��
// - list : ���� �����̳ʴ� ���Һ��� �� ū �޸𸮸� ����Ѵ�
//   forward_list

// list�� MemoryMonster 3���� �߰��غ�����
// �� ���Ҹ� ����غ�����

int main()
{
	list<MemoryMonster> monsters{ 10, 20, 30, 3, 40, 50 };

	// ����Ʈ���� ���̰� 10���� ���� ���Ҹ� �����϶�.
	monsters.remove_if();

	for (MemoryMonster& mon : monsters)
		cout << mon << endl;

	save("�ҽ�.cpp");
}