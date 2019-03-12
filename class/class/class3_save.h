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
	// frame를 일기 모드로 연다
	ifstream in(fname);


	// 하드디스크에 저장할 파일을 덧붙여쓰기 모드로 연다
	ofstream out("정수만개정렬.dat", ios::ate /*app:덧붙여쓰기 ate:덧붙이기*/);


	// 읽은 모든 내용을 쓴다
	// copy(어디부터, 어디까지, 어디로);
	copy(istreambuf_iterator<char>(in), istreambuf_iterator<char>()/*파일의마지막*/, ostreambuf_iterator<char>(out/*cout은 콘솔, out은 메모장*/));


	// 저장한 시간도 기록한다
	// 1970년 이후의 틱수를 얻어온다
	auto tick = chrono::system_clock::now();

	// time 형식으로 변환한다
	auto time = chrono::system_clock::to_time_t(tick);

	// 글자로 바꾼다
	string date(ctime(&time)) /*string date = ctime(&time) 랑 같다*/;
	out << endl << endl;
	out << "============================" << endl;
	out << date;
	out << "============================" << endl;
}