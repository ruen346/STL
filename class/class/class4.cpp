#include<iostream>
using namespace std;

class Dog
{
	char name[11]; //이름을 10글자까지 허용
	int age;
};

int main()
{
	// Dog 1000마리를 생성하자
	// 이름은 임의의 알파벳 10글자 채우자
	// 나이는 0 ~ 20 까지 값으로 uid(dre) 이용하여 채우자

	// 이름 오름차순으로 정렬하자
	// 결과를 "DogNameAscend.dat", 바이러니 모드로 저장하자
	// 파일의 크기가 sizeof(Dog) * 1000 바이트임을 확인하자
	//   --> 그렇지 않다면 내 컴을 버리자




	// "DogNameAscend.dat"를 읽어 화면에 써보자
	for (int i = 0; i < 1000; i++)
	{
		cout << dogs[i] << endl; // "이름 : ********, 나이 " **"
	}
}