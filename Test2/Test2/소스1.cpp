#include <iostream>
#include<string>
using namespace std;

class champion
{
private:
	double a, b;
public:

	void information(double a, double b);
	int add();
	int sub();
	int mux();
	double demux();
};

void champion::information(double fa, double fb)
{
	a = fa;
	b = fb;
}

int champion::add()
{
	return a + b;
}

int champion::sub()
{
	return a - b;
}

int champion::mux()
{
	return a * b;
}

double champion::demux()
{
	return a / b;
}

void main()
{
	int fa, fb;
	char c;
	string d;
	champion plus;
	cin >> fa >> c >> fb >> d;
	plus.information(fa, fb);



	if (d == "=")
		switch (c) {
		case'+':
			cout << plus.add() << "�Դϴ�" << endl;
			break;
		case'-':
			cout << plus.sub() << "�Դϴ�" << endl;
			break;
		case'*':
			cout << plus.mux() << "�Դϴ�" << endl;
			break;
		case'/':
			cout << plus.demux() << "�Դϴ�" << endl;
			break;
		default:
			cout << "�̻��Ѱ� �Է�������" << endl;
		}
	else
		cout << "=�� ������" << endl;
}