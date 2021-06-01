#pragma once
class Sudoku {
public:
	Sudoku();
	bool creat();
	void print();
	void start();
	

private:
	int data[81];
	int mask[81];
	void createMask();
	void input(int, int, int);
	bool isRowVailable(int*);
	bool isColumnVailable(int*);
	bool isBoxVailable(int, int,int[]);
	bool getAnswer(int*);
	void copy(const int*, int*);
	void dig();
	int ans;
	int* ansList[2];
	int digData[81];
};
