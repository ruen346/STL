#include <iostream>
using namespace std;

class X
{
	int num;

public:

	X(int num) : num{ num } {}
	friend ostream& operator<<(ostream& os, const X& x);
};

ostream& operator<<(ostream& os, const X& x)
{
	os << x.num;
	return os;
}

template <typename T>

void change(T& a, T& b)
{
	T temp{ a };
	a = b;
	b = temp;
}

int main()
{
	X a{ 1 };
	X b{ 2 };

	change(a, b);

	cout << a << ", " << b << endl;
}
