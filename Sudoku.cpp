#include"Sudoku.h"
#include <cstdlib>
#include <ctime> 
#include<iostream>
#include<iomanip>
#include<windows.h>
#include <conio.h>
using namespace std;

void SetColor(int color = 7)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
void newPosition(int r, int c)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = c;
	scrn.Y = r;
	SetConsoleCursorPosition(hOuput, scrn);
}
/*
void getWH(int &w,int &h) {
	RECT rect;
	HWND hwnd = GetDesktopWindow();
	if (GetWindowRect(hwnd, &rect))
	{
		w = rect.right - rect.left;
		h = rect.bottom - rect.top;
	}
}*/
void init(int array[],int num) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)array[i*9+j] = num;
	}
}
void Sudoku::copy(const int *from,int *to) {
	for (int i = 0; i < 81; i++) {
		to[i] = from[i];
	}
}



Sudoku::Sudoku() {
	init(data,0);
}
bool Sudoku::creat() {
	srand(time(0));
	for (int i = 0; i < 9; i++)data[i] = i + 1;
	for (int i = 0; i < 9; i++) {
		int t = data[i];
		int index = rand() % 9;
		data[i] = data[index];
		data[index] = t;
	}
	int r = 1;
	int c = 0;
	int load = 0;
	//SetColor(1);
	while (r < 9 && c < 9) {
		data[r*9+c]++;
		if (data[r * 9 + c] <10) {
			if (!isRowVailable(data) || !isColumnVailable(data) || ((r + 1) % 3 == 0 && (c + 1) % 3 == 0 && !isBoxVailable(r / 3 * 3, c / 3 * 3,data))) continue;
			c++;
			if (c > 8) {
				c = 0;
				r++;
			}
		}
		else {
			data[r * 9 + c] = 0;
			c--;
			if (c < 0) {
				c = 8;
				r--;
			}
		}
		/*if ((r * 9 + c) / 10 * 10 != load && (r * 9 + c) / 10 * 10 > load) {
			load = (r * 9 + c) / 10 * 10;
			system("cls");
			cout << "╔";
			for (int i = 0; i < 81; i++)cout << "═";
			cout << "╗" << endl << "║";
			SetColor(9);
			for (int i = 0; i < 81; i++) {
				if (i <= load)cout << "▇";
				else cout << "▁";
			}
			SetColor(1);
			cout << "║" << endl << "╚";
			for (int i = 0; i < 81; i++)cout << "═";
			cout << "╝"<<endl;
			SetColor(9);
			cout << setw(46) << "運算模組中..." << endl;
			SetColor(1);
		}*/
	}
	createMask();
	return true;
}
void Sudoku::createMask() {
	init(mask,1);
	dig();
}

bool Sudoku::isRowVailable(int *newData) {
	for (int i = 0; i < 9; i++) {
		int num[10] = { 0 };
		for (int j = 0; j < 9; j++) {
			num[*(newData+(i*9+j))]++;
		}
		for (int j = 1; j < 10; j++) {
			if (num[j] > 1)return false;
		}
	}
	return true;
}
bool Sudoku::isColumnVailable(int* newData) {
	for (int j = 0; j < 9; j++) {
		int num[10] = { 0 };
		for (int i = 0; i < 9; i++) {
			num[newData[i * 9 + j]]++;
		}
		for (int i = 1; i < 10; i++) {
			if (num[i] > 1)return false;
		}
	}
	return true;
}
bool Sudoku::isBoxVailable(int r,int c,int newData[]) {
	int num[10] = {0};
	for (int i = r; i < r+3; i++) {
		for (int j = c; j < c+3; j++) {
			num[newData[i * 9 + j]]++;
		}
	}
	for (int i = 1; i < 10; i++) {
		if (num[i] > 1)return false;
	}
	return true;
}
void Sudoku::input(int r, int c, int num) {
	if (mask[r*9+c] == 1) {
		newPosition(1 + r + r / 3, 2 + c * 2 + c / 3 * 2);
	}else {
		newPosition(1 + r + r / 3, 2 + c * 2 + c / 3 * 2);
		if(data[r * 9 + c]!=num-48)SetColor(207);
		cout << num - 48;
		SetColor();
		newPosition(1 + r + r / 3, 2 + c * 2 + c / 3 * 2);
	}
	
}
void Sudoku::start() {
	int r = 0;
	int c = 0;
	newPosition(1 + r + r / 3, 2 + c * 2 + c / 3 * 2);
	int t=0;
	while (t!=274&&t!=27) {
		if (t / 10 >= 49 && t / 10 <= 57)input(r, c, t / 10);
		if (t >= 49 && t <= 57)input(r, c, t);
		t = _getch();
		if (t == 224) {
			t = _getch();
			if (t / 10 >= 49 && t / 10 <= 57)input(r, c, t / 10);
			if (t >= 49 && t <= 57)input(r, c, t);
			switch (t) {
			case 72:
				if (r - 1 < 0) {
					newPosition(1 + r + r / 3, 2 + c * 2 + c / 3 * 2);
					break;
				}
				r--;
				newPosition(1 + r + r / 3, 2 + c * 2 + c / 3 * 2);
				break;
			case 80:
				if (r + 1 > 8) {
					newPosition(1 + r + r / 3, 2 + c * 2 + c / 3 * 2);
					break;
				}
				r++;
				newPosition(1 + r + r / 3, 2 + c * 2 + c / 3 * 2);
				break;
			case 75:
				if (c - 1 < 0) {
					newPosition(1 + r + r / 3, 2 + c * 2 + c / 3 * 2);
					break;
				}
				c--;
				newPosition(1 + r + r / 3, 2 + c * 2 + c / 3 * 2);
				break;
			case 77:
				if (c + 1 > 8) {
					newPosition(1 + r + r / 3, 2 + c * 2 + c / 3 * 2);
					break;
				}
				c++;
				newPosition(1 + r + r / 3, 2 + c * 2 + c / 3 * 2);
				break;
			default:break;
			}
		}
	}
	/*
	while (first=_getch())
	{
		newPosition(9, 0);
		cout << "first: " << first << endl;
		if (first == 324)return;
		t = _getch();
		if (t == 224)t = _getch();
		newPosition(10, 0);
		cout <<"t: " <<t << endl;
		switch (t)
		{
		case 32:
			return;
			break;
		case 72:
			if (r - 1 < 0) {
				newPosition(r, c);
				break;
			}
			newPosition(--r, c);
			break;
		case 80:
			if (r + 1 > 8) {
				newPosition(r, c);
				break;
			}
			newPosition(++r, c);
			break;
		case 75:
			if (c - 1 < 0) {
				newPosition(r, c);
				break;
			}
			newPosition(r, --c);
			break;
		case 77:
			if (c + 1 > 8) {
				newPosition(r, c);
				break;
			}
			newPosition(r, ++c);
			break;
		default:
			break;
		}
	}*/
}

void Sudoku::print() {
	//system("cls");
	newPosition(0, 0);
	SetColor();
	cout << "╔═══════════════════════╗" << endl;
	for (int i = 0; i < 9; i++) {
		cout << "║ ";
		for (int j = 0; j < 9; j++) {
			if (mask[i*9+j] == 1)cout << digData[i * 9 + j];
			else cout << " ";
			cout << " ";
			if (j == 2 || j == 5)cout << "| ";
		}
		cout << "║" << endl;
		if (i == 2 || i == 5)cout << "║-------+-------+-------║" << endl;
	}
	cout << "╚═══════════════════════╝" << endl;
}


void Sudoku::dig() {
	int order[81];
	for (int i = 0; i < 81; i++)order[i] = i;
	for (int i = 0; i < 81; i++) {
		int t = order[i];
		int index = rand() % 81;
		order[i] = order[index];
		order[index] = t;
	}
	copy(data, digData);
	digData[order[0]] = 0;
	int target = 50;
	int shouldDigging =target;
	int numOfDig = 0;
	for (int i = 0; i < target && target<81; i++) {
		int *tData=new int[81];
		int t = digData[order[i]];
		digData[order[i]] = 0;
		ans = 0;
		copy(digData, tData);
		if (getAnswer(tData)) {
			digData[order[i]] = t;
			target++;
		}
		else {
			mask[order[i]] = 0;
			numOfDig++;
		}
		for(int j=0;j<ans;j++)delete ansList[j];
		delete [] tData;
	}
	if (numOfDig < shouldDigging)createMask();
}
bool Sudoku::getAnswer(int *digData) {
	if (ans > 1)return true;
	bool getZero = false;
	bool next = false;
	for (int k = 0; k < 81; k++) {
			if (digData[k] == 0) {
				int i = k / 9;
				int j = k % 9;
				getZero = true;
				for (int l = 1; l < 10; l++) {
					digData[k] = l;
					if (isRowVailable(digData) && isColumnVailable(digData) && isBoxVailable(i/3*3,j/3*3,digData)) {
						int *newDigData = new int[81];
						copy(digData, newDigData);
						getAnswer(newDigData);
						next = true;
					}
				}

			}

	}
	if (ans > 1)return true;
	if (!getZero) { 
		ans++;
	}else if (!next)delete[] digData;
	return false;
}
