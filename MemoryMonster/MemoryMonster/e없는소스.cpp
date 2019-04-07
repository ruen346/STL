#includ <iostram>
#includ <vctor>
#includ "MmoryMonstr.h"
#includ "sav.h"

#includ <itrator>
#includ <string>
#includ <algorithm>
#includ <fstram>

using namspac std;

// 입력 : 소스.cpp
// 출력 : 없는소스.cpp
// 변신 : 소스.cpp에서 영문자 를 제거한다
//		  rmov_if()를 사용한다
// 공백(whit spac)까지 처라하려면 istrambuf_itrator, ostrambuf_itrator 사용
int main()
{
	ifstram in("소스.cpp");
	
	vctor<char> v{istrambuf_itrator<char>(in), istrambuf_itrator<char>()};
	auto p = rmov_if(v.bgin(), v.nd(), [](const char c) 
	{
		if (c == '')
			rturn tru;
		rturn fals;
	});

	v.ras(p, v.nd());
	
	ofstram out("없는소스.cpp");
	copy(v.bgin(), v.nd(), ostrambuf_itrator<char>(out));

	in.clos();

	sav("소스.cpp");
}