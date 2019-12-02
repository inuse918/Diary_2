#include "WriteDiary.h"

void WriteDiary::Write() {
	system("cls");
	//string diary;
	string diaryName;
	FILE* diary;
	ofstream input;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "일기 제목을 입력하세요"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> diaryName;
	diaryName.append(".txt");
	input.open(diaryName);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "일기의 내용을 입력하세요." << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //
	

	
}