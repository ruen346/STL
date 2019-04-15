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

		cout << endl << endl << "< 양의 정수 2개를 덧셈하는 코드입니다 >" << endl << endl;
		cout << "키보드로 부터 입력받을려면 '1'을" << endl;
		cout << "파일로 부터 입력받을려면 '2'를" << endl;
		cout << "종료하실려면 '3'을 입력하세요." << endl;
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
			cout << endl << "허용되지 않은 명령어 입니다." << endl << endl;
		}
	}
}