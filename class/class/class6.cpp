#include <iostream>
using namespace std;

// ȣ�Ⱑ�� Ÿ��

int sq(int a)
{
	return a * a;
}

class Dog
{
	public:
		void operator()()
		{
			cout << "�۸�" << endl;
		}

		void bark()
		{
			cout << "�����������" << endl;
		}
};

int main()
{
	// 1. �Ϲ��Լ�
	int (*f1)(int) = sq;
	cout << f1(3) << endl;
	cout << typeid(f1).name() << endl << endl;

	// 2. ����
	auto f2 = []() {cout << "�ȳ� �� ���ٶ�� ��" << endl; };
	f2();
	cout << typeid(f2).name() << endl << endl;

	// 3. �Լ���ü - �Լ�ȣ�⿬���ڸ� �����ε��� Ŭ������ ��ü
	Dog f3;
	f3();
	cout << typeid(f3).name() << endl << endl;

	// 4. �ɹ��Լ�
	void (Dog::*f4)() = &Dog::bark;
	f4(f3);
	cout << typeid(f4).name() << endl << endl;
}