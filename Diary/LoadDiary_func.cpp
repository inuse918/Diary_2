#include "LoadDiary_func.h"

void LoadDiary_func::DeleteDiary() {
	string diaryName;
	ofstream input;
	
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "�ϱ⸦ �����մϴ�." << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "�����ϰ� ���� �ϱ��� ������ Ȯ���� ���� �Է����ּ���." << endl;
	cin >> diaryName;
	diaryName.append(".txt");
	input.remove_all(diaryName);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\n�ϱ��� ������ �Է��ϼ���.\n(��¥�� �ý��� �ð��� ���߾� �ڵ����� �Էµ˴ϴ�.)" << endl;
	cout << "���� �ϱ⸦ ������ �ʹٸ� ������ �ٿ��� enter �� '<end>'�� �Է��� �ּ���.\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void LoadDiary_func::ModificateDiary() {
	system("cls");
}
void LoadDiary_func::WatchDiary() {
	system("cls");
}