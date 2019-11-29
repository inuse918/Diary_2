#include "WriteDiary.h"
using namespace std;

void WriteDiary::Write() {
	system("cls");
	//string diary;
	string diaryName;
	FILE* diary;
	ofstream input;

	cout << "일기 제목을 입력하세요 (15자 이내) → ";
	getline(cin, diaryName);
	
	input.open(diaryName.c_str());
	input << "Hello";
	input.close();
	
}