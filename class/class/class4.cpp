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
	char name[11]; //이름을 10글자까지 허용
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
	os << "이름 : " << dog.name << ", 나이 : " << dog.age;
	return os;
}

int main()
{
	/*
	Dog dogs[1000];

	// Dog 1000마리를 생성하자
	// 이름은 임의의 알파벳 10글자 채우자
	// 나이는 0 ~ 20 까지 값으로 uid(dre) 이용하여 채우자


	// 이름 오름차순으로 정렬하자
	sort(begin(dogs), end(dogs), [](const Dog& a, const Dog& b) {
		return a.getName() < b.getName();
	});

	ofstream out("DogNameAscend.dat", ios::binary);
	out.write((char*)dogs, sizeof(Dog) * 1000);

	// 결과를 "DogNameAscend.dat", 바이러니 모드로 저장하자
	// 파일의 크기가 sizeof(Dog) * 1000 바이트임을 확인하자
	//   --> 그렇지 않다면 내 컴을 버리자
	*/


	ifstream in("DogNameAscend.dat", ios::binary);
	
	Dog dogs[1000];
	in.read((char*)dogs, sizeof(Dog) * 1000);

	// "DogNameAscend.dat"를 읽어 화면에 써보자
	for (int i = 0; i < 1000; i++)
	{
		cout << dogs[i] << endl; // "이름 : ********, 나이 " **"
	}
}