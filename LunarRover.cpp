#include"LunarRover.h"
#include"LunarSurface.h"
#include<iostream>
#include<iomanip>

LunarRover::LunarRover(LunarSurface* inBoard){gameBoard = inBoard;}
LunarRover::~LunarRover(){}

void LunarRover::drawGrid() {
	std::cout << "   | ";
	for (int i = 0; i < 40; i++) {
		std::cout << right << setw(3) << i;
	}
	std::cout << "\n---+--------------------------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < 15; i++) {
		std::cout << setw(3) << i << "| ";
		for (int j = 0; j < 40; j++) {
			std::cout << gameBoard->getBoardUnit(i, j) << gameBoard->getBoardUnit(i, j) << gameBoard->getBoardUnit(i, j);
		}
		if (i == 0) std::cout << setw(12) << "FUEL:" << setw(8) << fuel;
		else if (i == 1) std::cout << setw(12) << "DAMAGE:" << setw(8) << damage;
		std::cout << std::endl;
	}
}

bool LunarRover::land(int row, int col) {
	char temp_pos = gameBoard->getBoardUnit(row, col);
	return temp_pos == ' ';
}

int	 LunarRover::move(int newrow, int newcol) {
	char temp_pos = gameBoard->getBoardUnit(newrow, newcol);
	int result = 0;
	if (temp_pos == 'X') result = -1;
	else if (temp_pos == '-') damage += 8;
	else if (temp_pos == 'F') fuel += 25;
	else if (temp_pos == '$') result = 1;
	return result;
}

void LunarRover::getPosition(int& oldrow, int& oldcol) {
	oldrow = rowPOS;
	oldcol = colPOS;
}

void LunarRover::setPosition(int newrow, int newcol) {
	rowPOS = newrow;
	colPOS = newcol;
}

int	 LunarRover::getDamage() {
	return damage;
}

void LunarRover::setDamage(int newdmg) {
	damage = newdmg;
}

int	 LunarRover::getFuel() {
	return fuel;
}

void LunarRover::setFuel(int newfuel) {
	fuel = newfuel;
}
