#include <iostream>
#include <string>
#include <unordered_map>
#include "MemoryMonster.h"
#include "save.h"

class Dog {
	string name;
public:
	Dog(string name) : name{ name } {}

	string getName() const { return name; }
	
	bool operator == (const Dog& other) const
	{
		return name == other.name;
	}
};

template <>
struct hash<Dog>
{
	int operator()(const Dog& d) const
	{
		return hash<string>()(d.getName());
	}
};

int main()
{
	unordered_map<Dog, int> dogs;

	dogs.emplace("����", 3);
	dogs.emplace("����", 1);
	dogs.emplace("����", 5);

	for (int i = 0; i < dogs.bucket_count(); ++i)
	{
		cout << "[" << i << "] --- ";
		if (dogs.bucket_size(i))
		{
			for (auto b = dogs.begin(i); b != dogs.end(i); ++b)
				cout << b->second << " ";
		}
		cout << endl;
	}

	cout << dogs[string("����")] << endl;

	save("�ҽ�.cpp");
}