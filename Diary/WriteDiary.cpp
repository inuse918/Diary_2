#include <iostream>
#include "WriteDiary.h"
using namespace std;

void WriteDiary::Write() {
	system("cls");
	ofstream out("test.txt");
	string write;
	string fin;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for (int i = 0; i < 5; i++) {
		cin >> write;
		out << write << endl;
	}
	out.close();
	
}