#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

int main()
{
	int select;

	while (true)
	{
		vector<char> num1;
		vector<int> num2;

		cout << endl << endl << "< ���� ���� 2���� �����ϴ� �ڵ��Դϴ� >" << endl << endl;
		cout << "Ű����� ���� �Է¹������� '1'��" << endl;
		cout << "���Ϸ� ���� �Է¹������� '2'��" << endl;
		cout << "�����ϽǷ��� '3'�� �Է��ϼ���." << endl;
		cin >> select;

		if (select == 1)
		{
			cout << endl;

			char num;

			do
			{
				num = _getche();

				if (num != '\r')
					num1.push_back(num);
			}while (num != '\r');

			for (int i = 0; i < num1.size(); i++)
			{
				cout << num1[i] << endl;
			}
		}
		else if (select == 2)
		{
			cout << endl;
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