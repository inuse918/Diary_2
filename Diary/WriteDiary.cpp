#include "WriteDiary.h"

void WriteDiary::Write() {
	system("cls");
	//string diary;
	string diaryName;
	FILE* diary;
	ofstream input;
	time_t curr_time;
	struct tm* curr_tm;
	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "일기 제목을 입력하세요"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> diaryName;
	diaryName.append(".txt");
	input.open(diaryName);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "일기의 내용을 입력하세요." << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); 
	//날짜 입력
	input << curr_tm->tm_year + 1900 << "년 " << curr_tm->tm_mon + 1 << "일 " << curr_tm->tm_mday << "일" << endl;

	
}