#pragma once
#include <iostream>
#include <io.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>
#include "Menu.h"
using namespace std;

class LoadDiary {
public:
	void Load();
	void MovePosition(int x, int y);
	void SelectMenu();
	void DeleteDiary();
	void ModificateDiary();
	void WatchDiary();
};
