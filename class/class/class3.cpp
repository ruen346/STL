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

// a는 전역변수이다 - 어디에 저장되나?
// 지역변수와 차이점은 무엇인가?
// a는 실행파일에서 어떻게 기록되는가?
// int a[1000000];
// int a[1000000] {1};
// 이 두 경우에 실행파일(*.exe)의 크기는 매우 다르다. 왜 그런지 알아보자
int a[1000'0000];

int main()
{
	int* a;
	int num;

	cout << "원하는 만큼 정수를 동적할당하여 정렬 후 앞에서 100개를 출력" << endl;
	cout << "1000 이상의 정수를 입력하세요 : ";
	cin >> num;

	a = new int[num];

	// 정수 1000개를 랜덤으로 생성하여 정렬해보자
	// { } 이 안에 들어있는 것을 지역안으로 한다.
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
	// 정수 만개를 생성하여 정렬 후 파일에 기록하라
	int* a = new int[10000];

	uniform_int_distribution<> uid;
	default_random_engine dre;

	for (int i = 0; i < 10000; i++)
	{
		a[i] = uid(dre);
	}

	sort(a, a + 10000);
	
	// 정렬된 a를 파일 "정수만개정렬.dat"에 써 버자
	ofstream out("정수만개정렬.dat", ios::binary);

	// 공간을 낭비하지 않고 저장한다면 10000개 * sizeof(int) 바이트가 필요하다
	// 연속된 공간을 한 번에 저장하는 영향을 사용한다
	out.write((char*)a, 10000 * sizeof(int));
	
	delete a;

	//////////////////////////////////////////////////////////////////////////////////////


	// 파일에는 정수 10000개가 binary mode로 저장되어있다.
	// "정수만개정렬.dat"을 읽어 화면에 출력하라
	ifstream in2("정수만개정렬.dat", ios::binary);
	int* a2 = new int[10000];
	in2.read((char*)a2, 10000 * sizeof(int));

	if (in2.fail()) { cout << "파일을 여는 데 실패했습니다." << endl; }

	for (int i = 0; i < 10000; i++)
	{
		cout << setw(12) << a2[i];
		if (i % 5 == 0)
			cout << endl;
	}

	in2.close();
	delete a2;
}

// 정렬하여 파일에 기록한다
// ? 정수 만 개를 기록하려면 몇 바이트가 필요하지? (40000바이트)
// 2가지 모드로 열수있다....