#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
	// 시간재기 시작
	auto begin = steady_clock::now();

	// 시간이 걸리는 코드
	this_thread::sleep_for(123ms);

	// 시간재기 끝
	cout << duration_cast<milliseconds>(steady_clock::now() - begin).count() << "가 걸림" << endl;
}