#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <chrono>
using namespace std;

void save(string);

void save(string fname)
{
	// frame�� �ϱ� ���� ����
	ifstream in(fname);


	// �ϵ��ũ�� ������ ������ ���ٿ����� ���� ����
	ofstream out("������������.dat", ios::ate /*app:���ٿ����� ate:�����̱�*/);


	// ���� ��� ������ ����
	// copy(������, ������, ����);
	copy(istreambuf_iterator<char>(in), istreambuf_iterator<char>()/*�����Ǹ�����*/, ostreambuf_iterator<char>(out/*cout�� �ܼ�, out�� �޸���*/));


	// ������ �ð��� ����Ѵ�
	// 1970�� ������ ƽ���� ���´�
	auto tick = chrono::system_clock::now();

	// time �������� ��ȯ�Ѵ�
	auto time = chrono::system_clock::to_time_t(tick);

	// ���ڷ� �ٲ۴�
	string date(ctime(&time)) /*string date = ctime(&time) �� ����*/;
	out << endl << endl;
	out << "============================" << endl;
	out << date;
	out << "============================" << endl;
}