#include <iostream>
#include "MemoryMonster.h"
#include "save.h"
using namespace std;
#include <vector>;

// STL ǥ���� �����ϴ� 
//	   �ݺ��� �����
//     �����̳� �����
// ǥ�� STL �����̳� ó�� �����ϰ� �Ѵ�.

int main()
{
	MemoryMonster m{ 33 };
	copy(m.begin(), m.end(), ostream_iterator<char>(cout));
	cout << endl;

	auto p = find(m.begin(), m.end(), 'x');
	cout << distance(m.begin(), p) << "��° �����Դϴ� " << endl;
	cout << *p << endl;

	sort(m.rbegin(), m.rend());

	for (char c : m)
		cout << c;
	cout << endl;

	//save("�ҽ�.cpp");
}