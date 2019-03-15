#include<iostream>
#include <random>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

uniform_int_distribution<> uid(0,20);
uniform_int_distribution<> uidName('a' , 'z');
default_random_engine dre;

class Dog
{
	char name[11]; //�̸��� 10���ڱ��� ���
	int age;

	friend ostream& operator<<(ostream&, const Dog&);

public:
	Dog()
	{
		for (int i = 0; i < 10; i++)
		{
			name[i] = uidName(dre);
		}
		name[10] = '\0';
		age = uid(dre);
	}

	string getName() const
	{
		return string(name);
	}
};

ostream& operator<<(ostream& os, const Dog& dog)
{
	os << "�̸� : " << dog.name << ", ���� : " << dog.age;
	return os;
}

int main()
{
	/*
	Dog dogs[1000];

	// Dog 1000������ ��������
	// �̸��� ������ ���ĺ� 10���� ä����
	// ���̴� 0 ~ 20 ���� ������ uid(dre) �̿��Ͽ� ä����


	// �̸� ������������ ��������
	sort(begin(dogs), end(dogs), [](const Dog& a, const Dog& b) {
		return a.getName() < b.getName();
	});

	ofstream out("DogNameAscend.dat", ios::binary);
	out.write((char*)dogs, sizeof(Dog) * 1000);

	// ����� "DogNameAscend.dat", ���̷��� ���� ��������
	// ������ ũ�Ⱑ sizeof(Dog) * 1000 ����Ʈ���� Ȯ������
	//   --> �׷��� �ʴٸ� �� ���� ������
	*/


	ifstream in("DogNameAscend.dat", ios::binary);
	
	Dog dogs[1000];
	in.read((char*)dogs, sizeof(Dog) * 1000);

	// "DogNameAscend.dat"�� �о� ȭ�鿡 �Ẹ��
	for (int i = 0; i < 1000; i++)
	{
		cout << dogs[i] << endl; // "�̸� : ********, ���� " **"
	}
}