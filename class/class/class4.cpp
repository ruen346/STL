#include<iostream>
using namespace std;

class Dog
{
	char name[11]; //�̸��� 10���ڱ��� ���
	int age;
};

int main()
{
	// Dog 1000������ ��������
	// �̸��� ������ ���ĺ� 10���� ä����
	// ���̴� 0 ~ 20 ���� ������ uid(dre) �̿��Ͽ� ä����

	// �̸� ������������ ��������
	// ����� "DogNameAscend.dat", ���̷��� ���� ��������
	// ������ ũ�Ⱑ sizeof(Dog) * 1000 ����Ʈ���� Ȯ������
	//   --> �׷��� �ʴٸ� �� ���� ������




	// "DogNameAscend.dat"�� �о� ȭ�鿡 �Ẹ��
	for (int i = 0; i < 1000; i++)
	{
		cout << dogs[i] << endl; // "�̸� : ********, ���� " **"
	}
}