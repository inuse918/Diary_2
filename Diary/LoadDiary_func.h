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
	void DeleteDiary(); //�ϱ� �����ϱ�
	void ModifyDiary(); //�ϱ� ����
	void WatchDiary(); //�� �ϱ� ����
};
