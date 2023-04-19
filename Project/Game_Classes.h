//Group members: 21L-5666, 21L-7692
#pragma once

#ifndef Game_Classes_H_
#define Game_Classes_H_

#include <windows.h>
#include <iostream>
#include<fstream>
#include <string>

using namespace std;

class MyRectangle {
    float x1;   /* top-left x */
    float y1;   /* top-left y */
    float x2;   /* bottom-right x */
    float y2;   /* bottom-right y */

public:
    MyRectangle();
    MyRectangle(int x_1, int y_1, int x_2, int y_2);
    void setY(int check);
    void setX(int check);
    int getMiddle_Y();
    int getX1();
    int getX2();
    int getY1();
    int getY2();
    void setX1(int n);
    void setX2(int n);
    void setDimensions(int x_1, int y_1, int x_2, int y_2);
    // draws a rectangle using top-left and bottom-right x-y coordinates with separate border and fill colours
    void drawRectangle(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB); 
};


class Paddle {
    MyRectangle* paddle;
    int score;

public:
    Paddle();
    Paddle(int x1, int y1, int x2, int y2);
    MyRectangle* getPaddle();
    void setScore();
    int getScore();
    void movePaddle(char key);
};

class Ball {
    MyRectangle* ball;

public:
    Ball();
    Ball(int x1, int y1, int x2, int y2);
    MyRectangle* getBall();
    void moveBall(int n, int n1, int n2);
};

class Court {
    MyRectangle* m_dimensions;
public:
    Court();
    Court(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB);
    // draws a line between two points given their x-y coordinates using RGB colouring
    void drawLine(int x1, int y1, int x2, int y2, int r, int g, int b);
    MyRectangle* getDimensions();
    MyRectangle* getCourt();
};


class PongMenu {
public:
    char showMenu();
};


class PongGame {
    Court* court;
    Paddle* player1;
    Paddle* player2;
    Ball* ball;
    int** gameStates;
    static int gameHighest;
    int totalstates;

public:
    PongGame();
    Paddle* getPlayer1();
    Paddle* getPlayer2();
    // gets width and height of the window
    void getWindowDimensions(int& width, int& height);
    // shows or hides the cursor
    void showConsoleCursor(bool flag);
    // sets console cursor on given x-y coordinates
    void gotoxy(int x, int y);
    // gets key typed into the console without waiting for the input
    char getKey();
    // waits for some time (in milli-seconds)
    void delay(int ms);
    void cls(); // clears the screen
    void drawCourt(int w, int h);
    void drawPlayers(int w, int h);
    void drawBall(int w, int h);
    void InitializeGame();
    void PlayGame(int mode);
    void readData();
    void writeData();
    ~PongGame();
};

#endif /* Game_Classes_H_ */