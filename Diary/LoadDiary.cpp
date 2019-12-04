#include "LoadDiary.h"

void LoadDiary:: SelectMenu() {
	Menu menu = Menu(60, 0);
	Main main = Main();
	LoadDiary_func ldf = LoadDiary_func();
	menu.LPrintMenu();
	menu.LRecieveMenu();
//	LoadDiary loaddiary;
	bool isRun = TRUE;
	bool isWatchDiary = FALSE;
	bool isModifyDiary = FALSE;
	bool isDeleteDiary = FALSE;
	bool isBackToMain = FALSE;
	bool chk = FALSE;
	while (isRun) {
		int selectedMenu = menu.GetSelectedMenu();
		switch (selectedMenu)
		{
		case 1:
			if (!isWatchDiary) {
				ldf.WatchDiary();
				isWatchDiary = TRUE;
			}
			break;
		case 2:
			if (!isModifyDiary) {
				ldf.ModifyDiary();
				isModifyDiary = TRUE;
			}
			break;
		case 3:
			if (!isDeleteDiary) {
				ldf.DeleteDiary();
				isDeleteDiary = TRUE;
			}
			break;
		case 4:
			if (!isBackToMain) {
				system("cls");
				main.printMain();
			}
		default:
			if (!chk) {
				system("cls");
				main.printMain();
			}
			break;
		}
		
		if (!isRun) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			menu.MovePosition(45, 15);
			cout << "프로그램을 종료합니다." << endl;
			break;
		}
		
	}

}
void LoadDiary::Load(){
	system("cls");
	Main main = Main();
	_finddata_t fd;
	long handle;
	int result=0;
	handle = _findfirst(".\\*.txt", &fd);  // .txt 파일을 찾는다.
	char ch;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	
	if (handle == -1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "일기가 존재하지 않습니다!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "메인 화면으로 돌아가려면 아무 키나 누르세요." << endl;
		ch = _getch();
		if (ch != 0) {
			system("cls");
			main.printMain();
		}
		return;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "[작성했던 일기의 목록입니다]\n" << endl;
	while (result != -1) {
		string name = fd.name;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << name << endl;
		result = _findnext(handle, &fd);
	} _findclose(handle);

	SelectMenu();
}
