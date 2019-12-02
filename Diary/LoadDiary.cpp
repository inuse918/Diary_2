#include "LoadDiary.h"

void LoadDiary:: SelectMenu() {
	Menu menu = Menu(60, 0);
	Main main = Main();
	menu.LPrintMenu();
	menu.LRecieveMenu();
	LoadDiary loaddiary;
	bool isRun = TRUE;
	bool isWatchDiary = FALSE;
	bool isModificateDiary = FALSE;
	bool isDeleteDiary = FALSE;
	bool isBackToMain = FALSE;

	while (isRun) {
		int selectedMenu = menu.GetSelectedMenu();
		switch (selectedMenu)
		{
		case 1:
			if (!isWatchDiary) {
				//writediary.Write();
				isWatchDiary = TRUE;
			}
			break;
		case 2:
			if (!isModificateDiary) {
				loaddiary.Load();
				isModificateDiary = TRUE;
			}
			break;
		case 3:
			if (!isDeleteDiary) {
				//help.PrintHelp();
				isDeleteDiary = TRUE;
			}
			break;
		case 4:
			if (!isBackToMain) {
				system("cls");
				main.printMain();
			}
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
	_finddata_t fd;
	long handle;
	int result=0;
	handle = _findfirst(".\\*.txt", &fd);  // .txt 파일을 찾는다.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	
	if (handle == -1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "일기가 존재하지 않습니다!" << endl;
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
