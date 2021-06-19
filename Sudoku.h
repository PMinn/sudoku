#ifndef SUDOKU_H
#define SUDOKU_H
typedef void(*callback)(int, int, int);
class Sudoku {
public:
	Sudoku();
	bool creat(callback);
	void print(int, int);
	bool start(int, int);
	void clear();
	void init();
	Sudoku& operator=(Sudoku&);
private:
	int data[81];
	int mask[81];
	int exit[81];
	int life = 5;
	void createMask(callback);
	bool input(int, int, int, int, int);
	bool isRowVailable(int*);
	bool isColumnVailable(int*);
	bool isBoxVailable(int, int,int[]);
	bool getAnswer(int*);
	void copy(const int*, int*);
	void dig(callback);
	int ans;
	int creatTimes;
	int createMaskTimes;
	int digData[81];
	void setColor(int color = 7);
	void setPosition(int, int);
	void printLife();
};

#endif // !SUDOKU_H
