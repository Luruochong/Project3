#include "LunarSurface.h"
#include"LunarRover.h"
using namespace std;


int main() {
	LunarSurface ls;
	LunarSurface* ptrls = &ls;
	LunarRover lr(ptrls);
	string filename;
	char move, choice, last_pos_type;
	cout << "Specify a board file: ";
	cin >> filename;
	do{
		if (ls.readBoardFile(filename)) break;
		else {
			cout << "File read error for board file: " << filename << endl;
			cout << "Either the file does not exist or does not contain a valid board file!";
			cout << endl << endl << "Specify a different board file: ";
			cin >> filename;
		}
	} while (true);
	do {
		int result = 0, fuel = 100, damage = 0, col_pos, row_pos, col_old, row_old;
		lr.setFuel(fuel);
		lr.setDamage(damage);
		system("cls");
		lr.drawGrid();
		cout << "\n\nEnter (row, col) coordinates: ";
		cin >> row_pos >> col_pos;
		if (lr.land(row_pos, col_pos)) {
			do {
				lr.setPosition(row_pos, col_pos);
				lr.getPosition(row_old, col_old);
				if (ls.getBoardUnit(row_old, col_old) != 'F') last_pos_type = ls.getBoardUnit(row_old, col_old);
				else last_pos_type = ' ';
				system("cls");
				ls.setBoardUnit(row_pos, col_pos, 'LLL');
				lr.drawGrid();
				cout << "\n\nEnter a move (W (up), A (left), S (down), D (right)): ";
				cin >> move;
				if (move == 'w' || move == 'W') row_pos--;
				else if (move == 's' || move == 'S') row_pos++;
				else if (move == 'a' || move == 'A') col_pos--;
				else if (move == 'd' || move == 'D') col_pos++;
				fuel -= 2;
				lr.setFuel(fuel);
				result = lr.move(row_pos, col_pos);
				fuel = lr.getFuel();
				if (row_pos > 14 || row_pos < 0 || col_pos < 0 || col_pos>39) {
					cout << "\n\nYou fell off the moon, better luck next time!";
					break;
				}
				if (result == -1) {
					cout << "\n\nYou crashed in impassable terrain, better luck next time!";
					break;
				}
				else if (result == 1) {
					cout << "\n\nCongratulation! You're reached the target - one small step for man, one giant leap for mankind!";
					break;
				}
				ls.setBoardUnit(row_old, col_old, last_pos_type);
				if (lr.getDamage() > 100) {
					cout << "\n\nYour little rover couldn't take all the damage from rough terrain, better luck next time!";
					break;
				}
				else if (lr.getFuel() <= 0) {
					cout << "\n\nYou ran out of fuel! Take a better route next time!";
					break;
				}
			} while (true);
		}
		else cout << "Crash! Sorry, you lose!\n";
		do {
			cout << "\n\nWould you like to play again(Y/N)?";
			cin >> choice;
			if (choice != 'Y' && choice != 'y' && choice != 'n' && choice != 'N') cout << "Invalid!";
		} while (choice != 'Y' && choice != 'y' && choice != 'n' && choice != 'N');
	}while (choice == 'y' || choice == 'Y');
	return 0;
}