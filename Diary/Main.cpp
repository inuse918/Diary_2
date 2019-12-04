#include "Main.h"

void Main::printMain() {
	Menu menu = Menu(50, 1);
	Help help;
	WriteDiary writediary;
	LoadDiary loaddiary;
	bool isRun = TRUE;
	bool isPrintHelp = FALSE;
	bool isWriteDiary = FALSE;
	bool isLoadDiary = FALSE;
	bool isTrue = FALSE;
	menu.PrintMenu();
	menu.RecieveMenu();

	while (isRun) {
		int selectedMenu = menu.GetSelectedMenu();
		switch (selectedMenu)
		{
		case 1:
			if (!isWriteDiary) {
				writediary.Write();
				isWriteDiary = TRUE;
			}
			break;
		case 2:
			if (!isLoadDiary) {
				loaddiary.Load();
				isLoadDiary = TRUE;
			}
			break;
		case 3:
			if (!isPrintHelp) {
				help.PrintHelp();
				isPrintHelp = TRUE;
			}
			break;
		case 4:
			isRun = FALSE;
			break;
		default:
			if (!isTrue) {
				printMain();
				isTrue = TRUE;
			}
		}
		if (!isRun) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			menu.MovePosition(45, 15);
			cout << "프로그램을 종료합니다." << endl;
			exit(0);
		}
	}
}

int main() 
{
	system("cls");
	Main main = Main();
	main.printMain();
}