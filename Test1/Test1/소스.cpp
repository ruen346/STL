#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <array>
#include <list>
#include <chrono>
#include <random>
#include <fstream>
#include <vector>
using namespace std;

class Gamer{
	
	string name{};
	int score{};

public:
	Gamer() = default;
	Gamer(const string& name, int score) : name{ name }, score{ score }{}

	string getName() const { return name; }
	int getScore() const { return score; }
	void setName(const string& str) { name = str; }

	void show() const
	{
		cout << "[" << name << "] - " << score << endl;
	}
};

void makeData();

string file1{ "�÷��̾�1.txt" }, file2{ "�÷��̾�2.txt" };

int main()
{
	{
		makeData();
	}

	// [���� 1] �÷��̾�1.txt ��ϵ� 2000��ü�� ������ �����̳ʷ� �о�Ͷ�
	
	ifstream in1(file1);

	vector <string> name;

	istream_iterator<string> beg{ in1 };
	istream_iterator<string> end{};

	while (beg != end)
	{
		name.push_back(*beg++);
	}

	
	double num = 0;
	double num_sum;
	for (int i = 1; i <= 40; i += 2)
	{
		num = stoi(name[i]) / 1000.0;
	}
	cout << num  << endl;

	// 5��

	ifstream in(file1);
	ifstream in2(file2);
	vector<char> v{ istreambuf_iterator<char>(in), istreambuf_iterator<char>() };
	vector<char> v2{ istreambuf_iterator<char>(in2), istreambuf_iterator<char>() };
	string last = file1.substr(0, file1.size() - 4);
	ofstream out(last + file2, ios::app);
	copy(v.begin(), v.end(), ostreambuf_iterator<char>(out));
	copy(v2.begin(), v2.end(), ostreambuf_iterator<char>(out));
}

void makeData()
{
	ofstream out1(file1);
	ofstream out2(file2);

	default_random_engine dre;

	uniform_int_distribution<> uiName('a', 'z');
	
	normal_distribution<> ndScore{ 1000000.0, 100000.0 };

	for (int i = 0; i < 2000; ++i)
	{
		string name;
		for (int i = 0; i < 4; ++i)
			name += uiName(dre);

		Gamer g(name, ndScore(dre));
		out1 << g.getName() << "\t" << g.getScore() << endl;
	}

	for (int i = 0; i < 2000; ++i)
	{
		string name;
		for (int i = 0; i < 4; ++i)
			name += uiName(dre);

		Gamer g(name, ndScore(dre));
		out2 << g.getName() << "\t" << g.getScore() << endl;
	}
}