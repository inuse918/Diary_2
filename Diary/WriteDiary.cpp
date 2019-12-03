#include "WriteDiary.h"

void WriteDiary::Write() {
	system("cls");
	string diaryName;
	Main main = Main();
	ofstream input;
	time_t curr_time;
	struct tm* curr_tm;
	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);
	char ch;

	vector<string> content;
	string line;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "일기 제목을 입력하세요(30자 이내): ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> diaryName;
	diaryName.append(".txt");
	input.open(diaryName);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\n일기의 내용을 입력하세요.\n(날짜는 시스템 시간에 맞추어 자동으로 입력됩니다.)" << endl;
	cout << "만약 일기를 끝내고 싶다면 마지막 줄에서 enter 후 '<end>'를 입력해 주세요.\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); 
	//날짜 입력
	input << curr_tm->tm_year + 1900 << "년 " << curr_tm->tm_mon + 1 << "일 " << curr_tm->tm_mday << "일" << endl;
	
	while (1) {
		getline(cin, line);  
		if (line.compare("<end>") == 0) 
			break;
		content.push_back(line); 
	}
	vector<string>::iterator iter;
	for (iter = content.begin(); iter != content.end(); ++iter) {
		input << *iter << endl;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\n\n일기 저장 완료" <<endl;
	cout << "메인 화면으로 돌아가려면 아무 키나 누르세요." << endl;
	ch = _getch();
	if (ch != 0) {
		system("cls");
		main.printMain();
	}
}
