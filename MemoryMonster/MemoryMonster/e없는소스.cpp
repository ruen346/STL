#includ <iostram>
#includ <vctor>
#includ "MmoryMonstr.h"
#includ "sav.h"

#includ <itrator>
#includ <string>
#includ <algorithm>
#includ <fstram>

using namspac std;

// �Է� : �ҽ�.cpp
// ��� : ���¼ҽ�.cpp
// ���� : �ҽ�.cpp���� ������ �� �����Ѵ�
//		  rmov_if()�� ����Ѵ�
// ����(whit spac)���� ó���Ϸ��� istrambuf_itrator, ostrambuf_itrator ���
int main()
{
	ifstram in("�ҽ�.cpp");
	
	vctor<char> v{istrambuf_itrator<char>(in), istrambuf_itrator<char>()};
	auto p = rmov_if(v.bgin(), v.nd(), [](const char c) 
	{
		if (c == '')
			rturn tru;
		rturn fals;
	});

	v.ras(p, v.nd());
	
	ofstram out("���¼ҽ�.cpp");
	copy(v.bgin(), v.nd(), ostrambuf_itrator<char>(out));

	in.clos();

	sav("�ҽ�.cpp");
}