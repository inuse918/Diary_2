#include "LoadDiary_func.h"
#define _CRT_SECURE_NO_WARNINGS

char ch;

bool FileExists(const string& filename)
{
	WIN32_FIND_DATAA fd = { 0 };
	HANDLE hFound = FindFirstFileA(filename.c_str(), &fd);
	bool retval = hFound != INVALID_HANDLE_VALUE;
	FindClose(hFound);

	return retval;
}

void LoadDiary_func::DeleteDiary() {
	fstream input;
	Main main = Main();
	LoadDiary loaddiary = LoadDiary();
	int choose;
	string diaryName;
	//ofstream out;
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "일기를 삭제합니다." << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "삭제한 파일은 되돌릴 수 없습니다. 파일 삭제를 계속 진행하시겠습니까?" << endl;
	cout << "계속 진행하려면 1, 이전으로 돌아가려면 0을 입력해 주세요=> ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> choose;
	switch (choose)
	{
	case 1: {
		cout << "삭제하고 싶은 일기의 제목을 확장자 없이 입력해주세요." << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> diaryName;
		diaryName.append(".txt");
		input.open(diaryName.c_str(), ios::in | ios::out | ios::ate);
		if (input.is_open())
		{
			input.close();
		}
		input.close();
		if (FileExists(diaryName)==0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "존재하지 않는 파일입니다. 삭제를 실패하였습니다." << endl;
		}
		else {
			input.close();
			DeleteFile(diaryName.c_str());
			//remove(diaryName.c_str());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << diaryName << "파일이 성공적으로 삭제되었습니다." << endl;
		}
		cout << "이전 화면으로 돌아가려면 아무 키나 누르세요." << endl;
		ch = _getch();
		if (ch != 0) {
			system("cls");
			loaddiary.Load();
		}
		break;
	}
	case 0:
		loaddiary.Load();
		break;
	default:
		loaddiary.Load();
		break;
	}
}
void LoadDiary_func::ModifyDiary() {
	fstream input;
	Main main = Main();
	system("cls");
	LoadDiary loaddiary = LoadDiary();
	string diaryName;
	
	time_t curr_time;
	struct tm* curr_tm;
	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);
	char ch;
	int choose;
	vector<string> content;
	string line;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //빨간색
	std::cout << "[주의] 이전의 내용은 사라집니다." << endl;
	cout << "그래도 진행하시려면 1, 이전으로 되돌아가려면 0을 입력하세요=> ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //흰색
	cin >> choose;
	switch (choose) {
	case 1: {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		std::cout << "수정하고 싶은 일기 제목을 확장자 없이 입력해주세요." << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> diaryName;
		diaryName.append(".txt");
		input.open(diaryName);
		cout << endl << endl << endl << endl;
		if (FileExists(diaryName) != 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << "\n일기의 내용을 다시 입력하세요.\n(날짜는 시스템 시간에 맞추어 자동으로 입력됩니다.)" << endl;
			cout << "만약 일기를 끝내고 싶다면 마지막 줄에서 enter 후 '***'를 입력해 주세요.\n" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			//날짜 입력
			input << curr_tm->tm_year + 1900 << "년 " << curr_tm->tm_mon + 1 << "일 " << curr_tm->tm_mday << "일" << endl;
			while (1) {
				getline(cin, line);
				if (line.compare("***") == 0)
					break;
				content.push_back(line);
			}
			vector<string>::iterator iter;
			for (iter = content.begin(); iter != content.end(); ++iter) {
				input << *iter << endl;
			}
			input.close();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "\n\n일기 저장 완료" << endl;
			cout << "메인 화면으로 돌아가려면 아무 키나 누르세요." << endl;
			ch = _getch();
			if (ch != 0) {
				system("cls");
				main.printMain();
			}
		} 
		else  {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "파일이 존재하지 않습니다." << endl;
			cout << "아무 키나 누르면 되돌아갑니다." << endl;
			ch = _getch();
			if (ch != 0) {
				system("cls");
				loaddiary.Load();
			}
		}
		break;
	}
	case 0:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << "\n되돌아갑니다." << endl;
		loaddiary.Load();
		break;
	default:
		loaddiary.Load();
		break;
	}

	
}
void LoadDiary_func::WatchDiary() {
	string diaryName;
	Main main = Main();
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
	file.close();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "메인으로 돌아가려면 아무 키나 누르세요." << endl;
	ch = _getch();
	if (ch != 0) {
		system("cls");
		main.printMain();
	}
}