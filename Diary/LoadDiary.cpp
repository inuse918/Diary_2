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
			cout << "���α׷��� �����մϴ�." << endl;
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
	handle = _findfirst(".\\*.txt", &fd);  // .txt ������ ã�´�.
	char ch;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	
	if (handle == -1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "�ϱⰡ �������� �ʽ��ϴ�!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "���� ȭ������ ���ư����� �ƹ� Ű�� ��������." << endl;
		ch = _getch();
		if (ch != 0) {
			system("cls");
			main.printMain();
		}
		return;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "[�ۼ��ߴ� �ϱ��� ����Դϴ�]\n" << endl;
	while (result != -1) {
		string name = fd.name;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << name << endl;
		result = _findnext(handle, &fd);
	} _findclose(handle);

	SelectMenu();
}
