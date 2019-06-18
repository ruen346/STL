#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<iterator>
#include<unordered_map>
#include<chrono>
#include<random>
#include<numeric>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;
using namespace std::chrono;

void makeData();

class Player {
	int year;
	int month;
	string name;

public:
	Player() = default;
	Player(int y, int m, string n) : year{ y }, month{ m }, name{ n }{}

	int getYear() const { return year; }
	int getMonth() const { return month; }
	string getName() const { return name; }

	void show() const
	{
		cout << year << ". " << setw(2) << month << ". " << name << endl;
	}
};

int main()
{
	// makeData();

	// 문제1

	ifstream in("기말.dat", ios::binary);

	vector<Player> p2;
	Player v;

	while (!in.eof())
	{
		in.read((char *)& v, sizeof(Player));
		p2.push_back(v);
	}

	p2[99999].show();

	


	// 문제2


	//sort(p2.begin(), p2.end());

	p2[99999].show();


	// 문제3
	//Player p{ 1999,1,"test" };


	// 문제4

	for (auto i = words.begin(); i != words.end(); i = words.upper_bound(*i))
		v.emplace_back(*i, words.count(*i));

}

void makeData()
{
	ofstream out("기말.dat", ios::binary);

	default_random_engine dre;
	uniform_int_distribution<int> year{ 1950,2010 };
	uniform_int_distribution<int> month{ 1,12 };
	uniform_int_distribution<int> name{ 'a', 'z' };
	uniform_int_distribution<int> len{ 3, 15 };

	for (int i = 0; i < 100000; ++i)
	{
		string s{};

		for (int j = 0; j < len(dre); ++j)
			s += name(dre);
		*s.begin() = toupper(*s.begin());

		Player p{ year(dre), month(dre), s };

		out.write((const char*)& p, sizeof(Player));
	}

	cout << "10만명의 선수 정보를 파일에 기록하였다" << endl;
}