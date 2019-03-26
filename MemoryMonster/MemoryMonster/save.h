#pragma once

#include <iostream>
#include <string>
#include <fstream>//파일을 읽을때
#include <algorithm>
#include <iterator>
#include <chrono>

//void save(const char*);
void save(std::string); //string은 std 안에 있기 때문에 붙여줘야해
void save(std::string fname) {
	//fname을 읽기모드로 연다
	std::ifstream in(fname);
	if (!in) {//만약에 fname의 파일이 없다면

	}
	//글자로 바꾼다
	//ctime_s(&time); 이거 _s하기 싫으면 속성에서 SDL검사 아니오로 바꾸기~~
	//저장한 시간도 기록한다.
	//chrono 인클루드

	//1970 이후의 틱수를 얻어온다
	auto tick = std::chrono::system_clock::now();

	//time 형식으로 변환한다
	auto time = std::chrono::system_clock::to_time_t(tick);

	std::string date(ctime(&time));

	//하드디스크에 저장할 파일을 덧붙여 쓰기 모드(app)로 연다. 덮어쓰기는 ate
	std::ofstream out("2019 STL 강의 저장.txt", std::ios::app);//이 이름으로 저장

	out << std::endl << std::endl;
	out << "============================" << std::endl;
	out << " " << date;
	out << "============================" << std::endl;
	out << std::endl;

	//읽은 모든 내용을 기록한다.
	//copy(어디부터, 어디까지, 어디로);
	copy(std::istreambuf_iterator<char>(in),
		std::istreambuf_iterator<char>(),
		std::ostreambuf_iterator<char>(out)
	);//istream_iterator 하면 빈공간(띄어쓰기)없이 저장, istreambuf하면 빈공간도(띄어쓰기)도 저장
}
//시간재기코드
//auto begin = steady_clock::now();
//cout << duration_cast<milliseconds>(steady_clock::now() - begin).count() << "가 걸림" << endl;