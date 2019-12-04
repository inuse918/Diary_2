#include "LoadDiary_func.h"
#define _CRT_SECURE_NO_WARNINGS

string diaryName;
ofstream input;

char ch;
void LoadDiary_func::DeleteDiary() {
	Main main = Main();
	LoadDiary loaddiary = LoadDiary();
	int choose;
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "일기를 삭제합니다." << endl;

	cout << "삭제하고 싶은 일기의 제목을 확장자 없이 입력해주세요." << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	cin >> diaryName;
	diaryName.append(".txt");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << " 삭제한 파일은 되돌릴 수 없습니다. 파일 삭제를 계속 진행하시겠습니까?" << endl;
	cout << "계속 진행하려면 1, 이전으로 돌아가려면 0을 입력해 주세요=> " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> choose;

	switch (choose)
	{
	case 1:
		if (remove(diaryName.c_str()) != 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "존재하지 않는 파일입니다. 삭제를 실패하였습니다." << endl;
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << diaryName << "파일이 성공적으로 삭제되었습니다." << endl;
		}
		input.close();
		cout << "메인 화면으로 돌아가려면 아무 키나 누르세요." << endl;
		ch = _getch();
		if (ch != 0) {
			system("cls");
			main.printMain();
		}
		break;
	case 0:
		loaddiary.Load();
		break;
	default:
		loaddiary.Load();
		break;
	}
}
void LoadDiary_func::ModifyDiary() {
	system("cls");
	LoadDiary loaddiary = LoadDiary();
	ofstream out;
	int choose;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //빨간색
	std::cout << "[주의] 이전의 내용은 사라집니다." << endl;
	cout << "그래도 진행하시려면 1, 이전으로 되돌아가려면 0을 입력하세요=> ";
	cin >> choose;

	switch (choose) {
	case 1:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		std::cout << "수정하고 싶은 일기 제목을 확장자 없이 입력해주세요." << endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> diaryName;
		diaryName.append(".txt");
		out.open(diaryName, ios::out);

		out.close();

		break;
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "메인 화면으로 돌아가려면 아무 키나 누르세요." << endl;
	ch = _getch();
	if (ch != 0) {
		system("cls");
		main.printMain();
	}

}