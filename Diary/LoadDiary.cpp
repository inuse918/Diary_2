#include "LoadDiary.h"

void LoadDiary::Load(){
	system("cls");
	_finddata_t fd;
	long handle;
	int result=0;
	handle = _findfirst(".\\*.txt", &fd);  // .txt ������ ã�´�.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	
	if (handle == -1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "�ϱⰡ �������� �ʽ��ϴ�!" << endl;
		return;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "�ۼ��ߴ� �ϱ��� ����Դϴ�!\n" << endl;
	while (result != -1) {
		string name = fd.name;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << name << endl;
		result = _findnext(handle, &fd);
	} _findclose(handle);

	cout << endl << endl;
	cout<<""
}
