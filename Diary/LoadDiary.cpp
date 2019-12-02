#include "LoadDiary.h"

void LoadDiary::Load(){
	system("cls");
	_finddata_t fd;
	long handle;
	int result=0;
	handle = _findfirst(".\\*.txt", &fd);  // .txt 파일을 찾는다.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	
	if (handle == -1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "일기가 존재하지 않습니다!" << endl;
		return;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "작성했던 일기의 목록입니다!\n" << endl;
	while (result != -1) {
		string name = fd.name;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << name << endl;
		result = _findnext(handle, &fd);
	} _findclose(handle);

	cout << endl << endl;
	cout<<""
}
