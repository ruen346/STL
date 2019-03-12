#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <random>
#include <iomanip>
using namespace std;

/*

// a�� ���������̴� - ��� ����ǳ�?
// ���������� �������� �����ΰ�?
// a�� �������Ͽ��� ��� ��ϵǴ°�?
// int a[1000000];
// int a[1000000] {1};
// �� �� ��쿡 ��������(*.exe)�� ũ��� �ſ� �ٸ���. �� �׷��� �˾ƺ���
int a[1000'0000];

int main()
{
	int* a;
	int num;

	cout << "���ϴ� ��ŭ ������ �����Ҵ��Ͽ� ���� �� �տ��� 100���� ���" << endl;
	cout << "1000 �̻��� ������ �Է��ϼ��� : ";
	cin >> num;

	a = new int[num];

	// ���� 1000���� �������� �����Ͽ� �����غ���
	// { } �� �ȿ� ����ִ� ���� ���������� �Ѵ�.
	uniform_int_distribution<> uid(0, 10000);
	default_random_engine dre;

	for (int i=0; i<num; i++)
		a[i] = uid(dre);

	sort(a, a + num);

	for (int i = 0; i < 1000; i++)
		cout << a[i] << " ";
	cout << endl;
}

*/

int main()
{
	// ���� ������ �����Ͽ� ���� �� ���Ͽ� ����϶�
	int* a = new int[10000];

	uniform_int_distribution<> uid;
	default_random_engine dre;

	for (int i = 0; i < 10000; i++)
	{
		a[i] = uid(dre);
	}

	sort(a, a + 10000);
	
	// ���ĵ� a�� ���� "������������.dat"�� �� ����
	ofstream out("������������.dat", ios::binary);

	// ������ �������� �ʰ� �����Ѵٸ� 10000�� * sizeof(int) ����Ʈ�� �ʿ��ϴ�
	// ���ӵ� ������ �� ���� �����ϴ� ������ ����Ѵ�
	out.write((char*)a, 10000 * sizeof(int));
	
	delete a;

	//////////////////////////////////////////////////////////////////////////////////////


	// ���Ͽ��� ���� 10000���� binary mode�� ����Ǿ��ִ�.
	// "������������.dat"�� �о� ȭ�鿡 ����϶�
	ifstream in2("������������.dat", ios::binary);
	int* a2 = new int[10000];
	in2.read((char*)a2, 10000 * sizeof(int));

	if (in2.fail()) { cout << "������ ���� �� �����߽��ϴ�." << endl; }

	for (int i = 0; i < 10000; i++)
	{
		cout << setw(12) << a2[i];
		if (i % 5 == 0)
			cout << endl;
	}

	in2.close();
	delete a2;
}

// �����Ͽ� ���Ͽ� ����Ѵ�
// ? ���� �� ���� ����Ϸ��� �� ����Ʈ�� �ʿ�����? (40000����Ʈ)
// 2���� ���� �����ִ�....