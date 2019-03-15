#include <iostream>
using namespace std;

// 호출가능 타입

int sq(int a)
{
	return a * a;
}

class Dog
{
	public:
		void operator()()
		{
			cout << "멍멍" << endl;
		}

		void bark()
		{
			cout << "물어버릴꺼얌" << endl;
		}
};

int main()
{
	// 1. 일반함수
	int (*f1)(int) = sq;
	cout << f1(3) << endl;
	cout << typeid(f1).name() << endl << endl;

	// 2. 람다
	auto f2 = []() {cout << "안녕 난 람다라고 해" << endl; };
	f2();
	cout << typeid(f2).name() << endl << endl;

	// 3. 함수객체 - 함수호출연산자를 오버로딩한 클레스와 객체
	Dog f3;
	f3();
	cout << typeid(f3).name() << endl << endl;

	// 4. 맴버함수
	void (Dog::*f4)() = &Dog::bark;
	f4(f3);
	cout << typeid(f4).name() << endl << endl;
}