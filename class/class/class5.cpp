#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
	// �ð���� ����
	auto begin = steady_clock::now();

	// �ð��� �ɸ��� �ڵ�
	this_thread::sleep_for(123ms);

	// �ð���� ��
	cout << duration_cast<milliseconds>(steady_clock::now() - begin).count() << "�� �ɸ�" << endl;
}