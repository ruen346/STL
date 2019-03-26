#pragma once

#include <iostream>
#include <string>
#include <fstream>//������ ������
#include <algorithm>
#include <iterator>
#include <chrono>

//void save(const char*);
void save(std::string); //string�� std �ȿ� �ֱ� ������ �ٿ������
void save(std::string fname) {
	//fname�� �б���� ����
	std::ifstream in(fname);
	if (!in) {//���࿡ fname�� ������ ���ٸ�

	}
	//���ڷ� �ٲ۴�
	//ctime_s(&time); �̰� _s�ϱ� ������ �Ӽ����� SDL�˻� �ƴϿ��� �ٲٱ�~~
	//������ �ð��� ����Ѵ�.
	//chrono ��Ŭ���

	//1970 ������ ƽ���� ���´�
	auto tick = std::chrono::system_clock::now();

	//time �������� ��ȯ�Ѵ�
	auto time = std::chrono::system_clock::to_time_t(tick);

	std::string date(ctime(&time));

	//�ϵ��ũ�� ������ ������ ���ٿ� ���� ���(app)�� ����. ������ ate
	std::ofstream out("2019 STL ���� ����.txt", std::ios::app);//�� �̸����� ����

	out << std::endl << std::endl;
	out << "============================" << std::endl;
	out << " " << date;
	out << "============================" << std::endl;
	out << std::endl;

	//���� ��� ������ ����Ѵ�.
	//copy(������, ������, ����);
	copy(std::istreambuf_iterator<char>(in),
		std::istreambuf_iterator<char>(),
		std::ostreambuf_iterator<char>(out)
	);//istream_iterator �ϸ� �����(����)���� ����, istreambuf�ϸ� �������(����)�� ����
}
//�ð�����ڵ�
//auto begin = steady_clock::now();
//cout << duration_cast<milliseconds>(steady_clock::now() - begin).count() << "�� �ɸ�" << endl;