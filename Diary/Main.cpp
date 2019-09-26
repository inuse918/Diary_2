#include <iostream>
#include <Windows.h>
#include "Menu.h"
#include "Help.h"
#include "WriteDiary.h"
using namespace std;

int main() 
{
	Menu menu = Menu(50,1);
	Help help;
	WriteDiary writediary;
	bool isRun = TRUE;
	bool isPrintHelp = FALSE;
	bool isWriteDiary = FALSE;
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
		}
		if (!isRun) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			menu.MovePosition(45, 15);
			cout << "프로그램을 종료합니다." << endl;
			break;
		}
	}
	
}