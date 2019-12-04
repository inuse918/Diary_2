#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <cstdio>
#include "Main.h"
#include "LoadDiary.h"
#include <string>
#include <vector>
using namespace std;


class LoadDiary_func {
public:
	void DeleteDiary(); //일기 삭제하기
	void ModifyDiary(); //일기 수정
	void WatchDiary(); //쓴 일기 보기
};
