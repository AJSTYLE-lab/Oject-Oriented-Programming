//Group members: 21L-5666, 21L-7692
#include <iostream>
#include <windows.h>
#include<fstream>
#include <string>
#include "Game_Classes.h"

using namespace std;

MyRectangle::MyRectangle() {
    x1 = y1 = x2 = y2 = 0;
}

MyRectangle::MyRectangle(int x_1, int y_1, int x_2, int y_2) {
    x1 = x_1;
    y1 = y_1;
    x2 = x_2;
    y2 = y_2;
}

void MyRectangle::setY(int check) {
    if (check == 1) {
        y1 -= 20;
        y2 -= 20;
    }
    else {
        y1 += 20;
        y2 += 20;
    }
}

void MyRectangle::setX(int check) {
    if (check == 1) {
        x1 -= 10;
        x2 -= 10;
    }
    else {
        x1 += 10;
        x2 += 10;
    }
}

int MyRectangle::getMiddle_Y() {
    return (y1 + y2) / 2;
}

int MyRectangle::getX1() {
    return x1;
}

int MyRectangle::getX2() {
    return x2;
}

int MyRectangle::getY1() {
    return y1;
}

int MyRectangle::getY2() {
    return y2;
}

void MyRectangle::setX1(int n) {
    x1 = n;
}

void MyRectangle::setX2(int n) {
    x2 = n;
}

void MyRectangle::setDimensions(int x_1, int y_1, int x_2, int y_2) {
    x1 = x_1;
    y1 = y_1;
    x2 = x_2;
    y2 = y_2;
}

void MyRectangle::drawRectangle(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB) {
    HWND consoleHandle = GetConsoleWindow();
    HDC deviceContext = GetDC(consoleHandle);

    //change the colour by changing the values in RGB (from 0-255)
    HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
    SelectObject(deviceContext, pen);
    HBRUSH brush = CreateSolidBrush(RGB(FR, FG, FB));
    SelectObject(deviceContext, brush);
    Rectangle(deviceContext, x1, y1, x2, y2);
    DeleteObject(pen);
    DeleteObject(brush);
    ReleaseDC(consoleHandle, deviceContext);

}



Paddle::Paddle() {
    paddle = nullptr;
    score = 0;
}
Paddle::Paddle(int x1, int y1, int x2, int y2) {
    paddle = new MyRectangle(x1, y1, x2, y2);
    paddle->drawRectangle(x1, y1, x2, y2, 0, 0, 0, 0, 255, 0);
    score = 0;
}

MyRectangle* Paddle::getPaddle() {
    return paddle;
}

void Paddle::setScore() {
    score += 1;
}

int Paddle::getScore() {
    return score;
}

void Paddle::movePaddle(char key) {
    if (key == 'a' || key == 'k' || key == 's' || key == 'l') {
        paddle->drawRectangle(paddle->getX1(), paddle->getY1(), paddle->getX2(), paddle->getY2(), 0, 0, 0, 0, 0, 0);
        if (key == 'a' || key == 'k')
            paddle->setY(1);
        else if (key == 's' || key == 'l')
            paddle->setY(0);

        paddle = new MyRectangle(paddle->getX1(), paddle->getY1(), paddle->getX2(), paddle->getY2());
        paddle->drawRectangle(paddle->getX1(), paddle->getY1(), paddle->getX2(), paddle->getY2(), 0, 0, 0, 0, 255, 0);
    }
}



Ball::Ball() {
    ball = nullptr;
}
Ball::Ball(int x1, int y1, int x2, int y2) {
    ball = new MyRectangle(x1, y1, x2, y2);
    ball->drawRectangle(x1, y1, x2, y2, 0, 0, 0, 255, 0, 0);
}

MyRectangle*  Ball::getBall() {
    return ball;
}

void Ball::moveBall(int n, int n1, int n2) {
    ball->drawRectangle(ball->getX1(), ball->getY1(), ball->getX2(), ball->getY2(), 0, 0, 0, 0, 0, 0);
    if (n)
        ball->setX(n1);
    else {
        ball->setX(n1);
        ball->setY(n2);
    }
    ball = new MyRectangle(ball->getX1(), ball->getY1(), ball->getX2(), ball->getY2());
    ball->drawRectangle(ball->getX1(), ball->getY1(), ball->getX2(), ball->getY2(), 0, 0, 0, 255, 0, 0);
}



Court::Court() {
    m_dimensions = nullptr;
}

Court::Court(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB) {
    m_dimensions = new MyRectangle(x1, y1, x2, y2);
    m_dimensions->drawRectangle(x1, y1, x2, y2, R, G, B, FR, FG, FB);
    drawLine(x2 / 2, 0, x2 / 2, y2, 0, 0, 0);

}

// draws a line between two points given their x-y coordinates using RGB colouring
void Court::drawLine(int x1, int y1, int x2, int y2, int R, int G, int B) { //use three 3 integers if you want colored lines.
    HWND consoleHandle = GetConsoleWindow();
    HDC deviceContext = GetDC(consoleHandle);

    //change the colour by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for color.
    HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B)); //2 is the width of the pen
    SelectObject(deviceContext, pen);
    MoveToEx(deviceContext, x1, y1, NULL);
    LineTo(deviceContext, x2, y2);
    DeleteObject(pen);
    ReleaseDC(consoleHandle, deviceContext);
}

MyRectangle* Court::getDimensions() {
    return m_dimensions;
}

MyRectangle* Court::getCourt() {
    return m_dimensions;
}

char PongMenu::showMenu() {

    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console_color, 3);
    cout << endl;
    cout << "\t\t\t *******************************PONG GAME";
    cout << "*****************************\t\t\t " << endl << endl << endl << endl;
    cout << "\t\t\t\t\t  *****           MENU           *****\t\t\t  " << endl << endl << endl;
    cout << endl << endl << endl;

    SetConsoleTextAttribute(console_color, 6);
    cout << "\t\t\t\t\t           Press S to START game           \t\t\t  " << endl << endl << endl;
    cout << "\t\t\t\t\t           Press E to EXIT game           \t\t\t  " << endl << endl << endl;
    cout << endl << endl << endl << endl;

    SetConsoleTextAttribute(console_color, 3);
    cout << "\t\t\t\t\t *****        ENTER KEY:         *****\t\t\t  ";

    char key;
    cin >> key;

    return key;
}

int PongGame::gameHighest = 0;

PongGame::PongGame() {
    court = nullptr;
    player1 = nullptr;
    player2 = nullptr;
    ball = nullptr;
    gameStates = nullptr;
    totalstates = 0;
}

Paddle* PongGame::getPlayer1() {
    return player1;
}

Paddle* PongGame::getPlayer2() {
    return player2;
}

// gets width and height of the window
void PongGame::getWindowDimensions(int& width, int& height) {
    HWND consoleHandle = GetConsoleWindow();
    RECT rc;
    GetClientRect(consoleHandle, &rc);
    width = rc.right;
    height = rc.bottom;
}

// shows or hides the cursor
void PongGame::showConsoleCursor(bool flag) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = flag; // show or hide if flag is true or false respectively
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

// sets console cursor on given x-y coordinates
void PongGame::gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// gets key typed into the console without waiting for the input
char PongGame::getKey() {
    HANDLE consoleHandle = GetStdHandle(STD_INPUT_HANDLE);
    DWORD size = 1;
    INPUT_RECORD input[1];
    DWORD events = 0;
    char key = '\0';

    if (PeekConsoleInput(consoleHandle, input, size, &events)) {
        if (input[0].EventType == KEY_EVENT) {
            key = input[0].Event.KeyEvent.uChar.AsciiChar;
            FlushConsoleInputBuffer(consoleHandle);
            return key;
        }
    }

    return key; // returns NULL if no input event recorded
}

// waits for some time (in milli-seconds)
void PongGame::delay(int ms) {
    Sleep(ms);
}

void PongGame::cls() {
    COORD coordScreen = { 0, 0 };    // home for the cursor
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    if (!GetConsoleScreenBufferInfo(consoleHandle, &csbi)) {
        return;
    }

    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(consoleHandle,        // Handle to console screen buffer
        (TCHAR)' ',          // Character to write to the buffer
        dwConSize,            // Number of cells to write
        coordScreen,          // Coordinates of first cell
        &cCharsWritten);     // Receive number of characters written

}

void PongGame::drawCourt(int w, int h) {
    court = new Court(0, 0, w, h, 0, 0, 0, 0, 0, 0);
}

void PongGame::drawPlayers(int w, int h) {
    int n1 = h / 2 - 35;
    int n2 = h / 2 + 35;
    player1 = new Paddle(w - 80, n1, w - 60, n2);
    player2 = new Paddle(60, n1, 80, n2);
}

void PongGame::drawBall(int w, int h) {
    int n1 = w / 2;
    int n2 = h / 2;
    ball = new Ball(n1 - 10, n2 - 10, n1 + 10, n2 + 10);
}

void PongGame::readData() {

    ifstream read;
    read.open("PongGame.txt", ios::in);
    if (!read) {
        return;
    }
    else {

        while (!read.eof()) {

            int total;
            read >> total;
            totalstates = total + 1;
            gameStates = new int* [total + 1];

            string snumber, p1, p2, highest;
            int p1_score, p2_score, hscore;

            for (int i = 0; i < total; i++) {

                read >> snumber >> p1 >> p1_score;
                read >> p2 >> p2_score;

                int len1 = sizeof(p1_score);
                int len2 = sizeof(p2_score);

                gameStates[i] = new int[2];
                gameStates[i][0] = p1_score;
                gameStates[i][1] = p2_score;

            }

            read >> highest >> hscore;
            gameHighest = hscore;

        }
        /*cout << "Entered" << endl;*/
        read.close();
    }
}

void PongGame::InitializeGame() {

    cls();
    int w, h;
    getWindowDimensions(w, h);
    cls();

    showConsoleCursor(false);
    drawCourt(w, h);

    drawBall(w, h);
    drawPlayers(w, h);

}

void PongGame::writeData() {

    if (player1->getScore() > gameHighest)
        gameHighest = player1->getScore();
    if (player2->getScore() > gameHighest)
        gameHighest = player2->getScore();

    ofstream write;
    write.open("PongGame.txt", ios::out);

    if (write) {

        write << totalstates << endl;
        for (int i = 1; i < totalstates; i++) {
            write << "Game-" << i << ":" << endl;
            write << "Player-1: " << gameStates[i - 1][0] << endl;
            write << "Player-1: " << gameStates[i - 1][1] << endl;
        }

        write << "Game-" << totalstates << ":" << endl;
        write << "Player-1: " << player1->getScore() << endl;
        write << "Player-2: " << player2->getScore() << endl;
        write << "Hughest-Score: " << gameHighest << endl;

    }
    else
        cout << "File notn Found!" << endl;
}

void PongGame::PlayGame(int mode) {

    //Read data from file and update file after game finished

    while (player1->getScore() < 10 && player2->getScore() < 10) {

        gotoxy(0, 0);

        cout << "Player-1 Score: " << player2->getScore();
        cout << "                                                           ";
        cout << "Player-2 Score: " << player1->getScore();

        delay(50);

        int w, h;
        getWindowDimensions(w, h);
        drawBall(w, h);

        bool Bflag = true;
        bool updown = true;
        bool ifstraight = true;
        char key = '\0';

        while (true) {

            gotoxy(0, 0);

            key = getKey();

            if (mode == 1 && key != 'a' && key != 's') {
                int temp = rand() % 10;

                if (temp == 1)
                    key = 'k';
                else if (temp == 2)
                    key = 'l';
            }

            if (key == 'a' || key == 's') {
                if (player2->getPaddle()->getY1() - 20 > 20 && player2->getPaddle()->getY2() + 20 < 480)
                    player2->movePaddle(key);
                if (player2->getPaddle()->getY1() - 20 <= 20 && key == 's')
                    player2->movePaddle(key);
                if (player2->getPaddle()->getY2() + 20 >= 480 && key == 'a')
                    player2->movePaddle(key);
            }

            else if (key == 'k' || key == 'l') {
                if (player1->getPaddle()->getY1() - 20 > 20 && player1->getPaddle()->getY2() + 20 < 480)
                    player1->movePaddle(key);
                if (player1->getPaddle()->getY1() - 20 <= 20 && key == 'l')
                    player1->movePaddle(key);
                if (player1->getPaddle()->getY2() + 20 >= 480 && key == 'k')
                    player1->movePaddle(key);
            }

            else if (key == 'e')
                break;

            ball->moveBall(ifstraight, Bflag, updown);
            delay(100);

            // ball is hit by player 2
            if (player2->getPaddle()->getY1() <= ball->getBall()->getY1() &&
                player2->getPaddle()->getY2() >= ball->getBall()->getY2() &&
                player2->getPaddle()->getX2() == ball->getBall()->getX1()) {

                //ball hit the paddle in upper half -> move diagonal upward in opposite direction
                if (player2->getPaddle()->getMiddle_Y() != ball->getBall()->getMiddle_Y() &&
                    player2->getPaddle()->getMiddle_Y() >= ball->getBall()->getY2() &&
                    player2->getPaddle()->getY1() <= ball->getBall()->getY2()) {

                    ifstraight = false;
                    Bflag = false;
                    updown = true;
                    ball->moveBall(ifstraight, Bflag, updown);
                    delay(100);

                }

                //ball hit the paddle in lower half -> move diagonal downward in opposite direction
                else if (player2->getPaddle()->getMiddle_Y() != ball->getBall()->getMiddle_Y() && player2->getPaddle()->getMiddle_Y() <= ball->getBall()->getY1() && player2->getPaddle()->getY2() >= ball->getBall()->getY2()) {

                    ifstraight = false;
                    Bflag = false;
                    updown = false;
                    ball->moveBall(ifstraight, Bflag, updown);
                    delay(100);
                }


                //ball hit the paddle in middle -> move straight in opposite direction
                else if (player2->getPaddle()->getMiddle_Y() == ball->getBall()->getMiddle_Y()) {
                    Bflag = false;
                    ifstraight = true;
                    ball->moveBall(ifstraight, Bflag, updown);
                    delay(100);
                }
            }

            // ball is hit by player 1
            else if (player1->getPaddle()->getY1() <= ball->getBall()->getY1() && player1->getPaddle()->getY2() >= ball->getBall()->getY2() && player1->getPaddle()->getX1() == ball->getBall()->getX2()) {

                //ball hit the paddle in upper half -> move diagonal upward in opposite direction
                if (player1->getPaddle()->getMiddle_Y() != ball->getBall()->getMiddle_Y() &&
                    player1->getPaddle()->getMiddle_Y() >= ball->getBall()->getY2() &&
                    player1->getPaddle()->getY1() >= ball->getBall()->getY2()) {

                    ifstraight = false;
                    Bflag = true;
                    updown = true;
                    ball->moveBall(ifstraight, Bflag, updown);
                    delay(100);
                }

                //ball hit the paddle in lower half -> move diagonal downward in opposite direction
                else if (player1->getPaddle()->getMiddle_Y() != ball->getBall()->getMiddle_Y() && player1->getPaddle()->getMiddle_Y() <= ball->getBall()->getY1() && player1->getPaddle()->getY2() >= ball->getBall()->getY1()) {

                    ifstraight = false;
                    Bflag = true;
                    updown = false;
                    ball->moveBall(ifstraight, Bflag, updown);
                    delay(100);
                }

                //ball hit the paddle in middle -> move straight in opposite direction
                if (player1->getPaddle()->getMiddle_Y() == ball->getBall()->getMiddle_Y()) {
                    Bflag = true;
                    ifstraight = true;
                    ball->moveBall(ifstraight, Bflag, updown);
                    delay(100);
                }
            }

            //ball is hitting border at top
            if (ball->getBall()->getY1() == 10) {
                updown = false;
                ball->moveBall(ifstraight, Bflag, updown);
                delay(100);
            }

            //ball is hitting border at bottom
            if (ball->getBall()->getY2() == 470) {
                updown = true;
                ball->moveBall(ifstraight, Bflag, updown);
                delay(100);
            }

            //ball is missed by player
            if (ball->getBall()->getX1() <= player2->getPaddle()->getX2()) {
                player1->setScore();
                ball->getBall()->drawRectangle(ball->getBall()->getX1(), ball->getBall()->getY1(),
                    ball->getBall()->getX2(), ball->getBall()->getY2(), 0, 0, 0, 0, 0, 0);
                break;
            }

            if (ball->getBall()->getX2() >= player1->getPaddle()->getX1()) {
                player2->setScore();
                ball->getBall()->drawRectangle(ball->getBall()->getX1(), ball->getBall()->getY1(),
                    ball->getBall()->getX2(), ball->getBall()->getY2(), 0, 0, 0, 0, 0, 0);
                break;
            }

        }

        if (key == 'e')
            break;

    }

    cls();

    if (player1->getScore() == 10)
        cout << "PLAYER TWO WON!" << endl;

    if (player2->getScore() == 10)
        cout << "PLAYER ONE WON!" << endl;

    showConsoleCursor(true);

}

PongGame::~PongGame() {
    for (int i = 0; i < totalstates; i++)
        delete[] gameStates[i];
    delete[] gameStates;
}