#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS
#include "Main.h"
#include <string>
using namespace std;

class LoadDiary_func {
public:
	void DeleteDiary(); //일기 삭제하기
	void ModifyDiary(); //일기 수정
	void WatchDiary(); //쓴 일기 보기
};
