#include "LoadDiary_func.h"

void LoadDiary_func::DeleteDiary() {
	string diaryName;
	ofstream input;
	
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "일기를 삭제합니다." << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "삭제하고 싶은 일기의 제목을 확장자 없이 입력해주세요." << endl;
	cin >> diaryName;
	diaryName.append(".txt");
	input.remove_all(diaryName);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\n일기의 내용을 입력하세요.\n(날짜는 시스템 시간에 맞추어 자동으로 입력됩니다.)" << endl;
	cout << "만약 일기를 끝내고 싶다면 마지막 줄에서 enter 후 '<end>'를 입력해 주세요.\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void LoadDiary_func::ModificateDiary() {
	system("cls");
}
void LoadDiary_func::WatchDiary() {
	system("cls");
}