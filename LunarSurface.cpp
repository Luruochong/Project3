#include "LunarSurface.h"
#include"LunarRover.h"

LunarSurface::LunarSurface() {}
LunarSurface::~LunarSurface() {}

bool LunarSurface::readBoardFile(string filename) {
	bool ret = false;
	string temp;
	int rows = 15, cols = 40;
	char unit_type;
	ifstream input(filename.c_str());
	if (input) {
		int j = 0;
		while (getline(input, temp)) {
			for (int i = 0; i < cols; i++) {
				board[j][i] = temp[i];
			}
			j += 1;
		}
		ret = true;
	}
	return ret;
}

char LunarSurface::getBoardUnit(int row, int col) {
	//if (row >= ROWS || col >= COLS) return '#';
	return board[row][col];
}


void LunarSurface::setBoardUnit(int row, int col, char inChg) {
	//if (row >= ROWS || col >= COLS) {
		//return;
	//}
	board[row][col] = inChg;
}

