#ifndef SUDOKU_H
#define SUDOKU_H
class Sudoku {
public:
	Sudoku();
	bool creat();
	void print(int, int);
	void start(int, int);
private:
	int data[81];
	int mask[81];
	int exit[81];
	int life = 5;
	void createMask();
	bool input(int, int, int, int, int);
	bool isRowVailable(int*);
	bool isColumnVailable(int*);
	bool isBoxVailable(int, int,int[]);
	bool getAnswer(int*);
	void copy(const int*, int*);
	void dig();
	int ans;
	int createMaskTimes = 0;
	int digData[81];
	void setColor(int color = 7);
	void setPosition(int, int);
	void printLife();
};

#endif // !SUDOKU_H
