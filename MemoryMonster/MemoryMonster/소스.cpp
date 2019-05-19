#include <iostream>
#include "MemoryMonster.h"
#include "save.h"
using namespace std;
#include <vector>;

InIter myFind(InIter b, InIter e, Value v)
{

}

int main()
{
	string s{ "Hello, world!" };

	auto p = myFind(s.begin(), s.end(), '!');
	cout << *p << endl;

	//save("¼Ò½º.cpp");
}