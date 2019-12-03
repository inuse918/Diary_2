#include "LoadDiary_func.h"
#define _CRT_SECURE_NO_WARNINGS

string diaryName;
ofstream input;
Main main = Main();
char ch;
void LoadDiary_func::DeleteDiary() {
	
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "일기를 삭제합니다." << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "삭제하고 싶은 일기의 제목을 확장자 없이 입력해주세요." << endl;

	cin >> diaryName;
	diaryName.append(".txt");

	
	if (remove(diaryName.c_str())) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout <<"존재하지 않는 파일입니다. 삭제를 실패하였습니다." << endl;
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << diaryName << "파일이 성공적으로 삭제되었습니다." << endl;
	}
	cout << "메인 화면으로 돌아가려면 아무 키나 누르세요." << endl;
	ch = _getch();
	if (ch != 0) {
		system("cls");
		main.printMain();
	}
}
void LoadDiary_func::ModifyDiary() {
	system("cls");
	
}
void LoadDiary_func::WatchDiary() {
	string content;
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "작성한 일기를 봅니다." << endl;
	cout << "보고 싶은 일기의 제목을 확장자 없이 입력해주세요.\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> diaryName;
	diaryName.append(".txt");
	ifstream file(diaryName);
	cout << endl << endl<<endl<<endl;
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, content);
			cout << content << endl;
		}
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "파일이 존재하지 않습니다." << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "메인 화면으로 돌아가려면 아무 키나 누르세요." << endl;
	ch = _getch();
	if (ch != 0) {
		system("cls");
		main.printMain();
	}

}