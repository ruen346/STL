#include <iostream>
#include <vector>
#include <conio.h>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	int select;

	while (true)
	{
		cout << endl << endl << "< ���� ���� 2���� �����ϴ� �ڵ��Դϴ� >" << endl << endl;
		cout << "Ű����� ���� �Է¹������� '1'��" << endl;
		cout << "���Ϸ� ���� �Է¹������� '2'��" << endl;
		cout << "�����ϽǷ��� '3'�� �Է��ϼ���." << endl;
		cin >> select;

		if (select == 1)
		{
			vector<char> num1;
			vector<char> num2;
			vector<int> num3;

			cout << endl << "  ";
			
			char num;

			// ù��° �Է¹���
			do
			{
				num = _getche();

				if (num != '\r')
					num1.push_back(num);
			}while (num != '\r');

			cout << endl << "+ ";

			// �ι�° �Է¹���
			do
			{
				num = _getche();

				if (num != '\r')
					num2.push_back(num);
			} while (num != '\r');

			cout << endl << "= ";

			// ���ϱ� ����
			int min_size, max_size;
			if (num1.size() > num2.size())
			{
				max_size = num1.size();
				min_size = num2.size();
			}
			else
			{
				max_size = num2.size();
				min_size = num1.size();
			}

			int upper = 0;
			int i;
			for (i = 2; i <= min_size; i+= 2)
			{
				int ex1 = num1[num1.size() - i] - 48;
				int ex2 = num2[num2.size() - i] - 48;

				int sum = ex1 + ex2 + upper;

				if (sum >= 10)
				{
					upper = 1;
					sum -= 10;
				}
				else
					upper = 0;

				num3.push_back(sum);
			}
			for (; i <= max_size; i += 2)
			{
				if (num1.size() > num2.size())
					num3.push_back(num1[num1.size() - i] - 48 + upper);
				else
					num3.push_back(num2[num2.size() - i] - 48 + upper);
				upper = 0;
			}

			for (int i = num3.size() - 1; i >= 0; i--)
			{
				cout << num3[i];
			}
		}
		else if (select == 2)
		{
			vector<int> num3;

			char num;

			// ù��° �Է¹���
			string name1;

			cout << "���� 1 �����̸� : ";
			cin >> name1;

			ifstream in(name1);
			vector<char> num1{ istream_iterator<char>(in), istream_iterator<char>() };
			// copy(num1.begin(), num1.end(), ostream_iterator<char>(cout));

			// cout << endl << "+ ";

			// �ι�° �Է¹���
			string name2;

			cout << "���� 2 �����̸� : ";
			cin >> name2;

			ifstream in2(name2);
			vector<char> num2{ istream_iterator<char>(in2), istream_iterator<char>() };
			// copy(num2.begin(), num2.end(), ostream_iterator<char>(cout));

			// cout << endl << "= ";

			// ���ϱ� ����
			int min_size, max_size;
			if (num1.size() > num2.size())
			{
				max_size = num1.size();
				min_size = num2.size();
			}
			else
			{
				max_size = num2.size();
				min_size = num1.size();
			}

			int upper = 0;
			int i;
			for (i = 1; i <= min_size; i++)
			{
				int ex1 = num1[num1.size() - i] - 48;
				int ex2 = num2[num2.size() - i] - 48;

				int sum = ex1 + ex2 + upper;

				if (sum >= 10)
				{
					upper = 1;
					sum -= 10;
				}
				else
					upper = 0;

				num3.push_back(sum);
			}
			for (; i <= max_size; i++)
			{
				if (num1.size() > num2.size())
					num3.push_back(num1[num1.size() - i] - 48 + upper);
				else
					num3.push_back(num2[num2.size() - i] - 48 + upper);
				upper = 0;
			}

			for (int i = num3.size() - 1; i >= 0; i--)
			{
				// cout << num3[i];
			}

			string last = name1.substr(0, name1.size() - 4);
			ofstream out(last + name2, ios::ate);
			for (int i = num3.size() - 1; i >= 0; i--)
			{
				out << num3[i];
			}
		}
		else if (select == 3)
		{
			break;
		}
		else
		{
			cout << endl << "������ ���� ��ɾ� �Դϴ�." << endl << endl;
		}
	}
}