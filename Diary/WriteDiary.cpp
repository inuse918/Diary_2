#include "WriteDiary.h"

void WriteDiary::Write() {
	system("cls");
	//string diary;
	string diaryName;
	FILE* diary;
	ofstream input;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "�ϱ� ������ �Է��ϼ���"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> diaryName;
	diaryName.append(".txt");
	input.open(diaryName);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "�ϱ��� ������ �Է��ϼ���." << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //
	

	
}