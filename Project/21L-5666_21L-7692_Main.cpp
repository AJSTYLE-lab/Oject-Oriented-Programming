//Group members: 21L-5666, 21L-7692
#include <iostream>
#include "Game_Classes.h"

using namespace std;

int main() {

	PongMenu menu;
	char key = menu.showMenu();

	if (key == 'e' || key == 'E') {
		return 0;
	}

	else if (key == 's' || key == 'S') {

		PongGame game;
		game.readData();

		game.cls();
		game.gotoxy(0, 0);

		cout << endl;
		cout << "\t\t\t *******************************PONG GAME";
		cout << "*****************************\t\t\t " << endl << endl << endl << endl;
		cout << "\t\t\t\t\t  *****           MENU           *****\t\t\t  " << endl << endl << endl;
		cout << endl << endl << endl;

		cout << "\t\t\t\t\t           Press 1 for 1-PLAYER mode           \t\t\t  " << endl << endl << endl;
		cout << "\t\t\t\t\t           Press 2 for 2-PLAYERS mode           \t\t\t  " << endl << endl << endl;
		cout << endl << endl << endl << endl;

		cout << "\t\t\t\t\t *****        ENTER NUMBER:         *****\t\t\t  ";
		int mode;
		cin >> mode;

		game.InitializeGame();
		game.PlayGame(mode);
		game.writeData();
	}	

	return 0;
}