#include<iostream>
#include <future>
#include <conio.h>
#include"Sudoku.h"
#include<windows.h>
using namespace std;

bool passRules = false;
void setPosition(int r, int c) {
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = c;
	scrn.Y = r;
	SetConsoleCursorPosition(hOuput, scrn);
}
void setColor(int color = 7) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void printTitle() {
	setColor(59);
	cout << "---------------------------------------------------------" << endl;
	setColor(144);
	cout << "|                         數獨                          |" << endl;
	setColor(59);
	cout << "---------------------------------------------------------" << endl << endl;
	setColor();
}
void printRules() {
	cout << "規則: " << endl << "每一局都只有";
	setColor(12);
	cout << "5";
	setColor();
	cout << "次的錯誤機會," << endl << "當5次機會用完或是完成解題遊戲即結束.";
	cout << endl << "遊戲全程只使用";
	setColor(14);
	cout << "方向";
	setColor();
	cout << "鍵和";
	setColor(14);
	cout << "數字";
	setColor();
	cout << "鍵和";
	setColor(14);
	cout << "Enter";
	setColor();
	cout << "鍵" << endl << endl << "按任意鍵繼續遊戲" << endl;
}
Sudoku sudoku;
Sudoku secondSudoku;
void loading(int creatTimes, int createMaskTimes, int percent) {
	if (passRules) {
		setPosition(8, 1);
		setColor(2);
		cout << "模板" << creatTimes << "/序列" << (createMaskTimes + 1) << "/" << percent << "%";
		setColor();
	}
}
bool creatSudoku(Sudoku &s) {
	s.init();
	callback cb = loading;
	s.creat(cb);
	return true;
}
future<bool> fut = async(creatSudoku, ref(sudoku));
future<bool> fut2;

int main() {
	printTitle();
	printRules();
	char c=_getch();
	setPosition(4, 0);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 20; j++)cout << "　";
		cout << endl;
	}
	setPosition(7, 3);
	setColor(2);
	cout << "載入中...";
	passRules = true;
	bool r = fut.get();
	if (r) {
		do {
			sudoku.clear();
			setColor();
			passRules = false;
			fut2 = async(creatSudoku, ref(secondSudoku));
			sudoku.print(3, 0);
			bool finish = sudoku.start(3, 0);
			sudoku.clear();
			setColor(12);
			setPosition(5, 0);
			if (finish)cout << "恭喜過關！！！" << endl;
			else cout << "請再接再厲！加油～" << endl;
			setPosition(7, 3);
			setColor(2);
			cout << "正在加載新的局";
			passRules = true;
			bool r2 = fut2.get();
			if (r2) {
				sudoku = secondSudoku;
				setPosition(9, 3);
				setColor();
				cout << "加載完成" << endl << "按任意鍵下一局...";
			}
		} while (_getch());
	}
	system("pause");
	return 0;
}
