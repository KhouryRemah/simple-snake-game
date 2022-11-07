

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "snake.h"


#define WIDTH 50
#define HEIGHT 25

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75

using namespace std;
int score;
Food food;
Snake snake;
vector<vector<char>> board;
void updateBoard() {
    pair<int, int> foodPos = food.getPos();
    int yFood = foodPos.first;
    int xFood = foodPos.second;
    board[xFood][yFood] = 'X';

    pair<int, int> snakePos = snake.getPos();
    int ySnake = snakePos.first;
    int xSnake = snakePos.second;
    board[xSnake][ySnake] = 'O';

    pair<int, int> snakeDeletedPair = snake.getLastRemovedPair();
    int ySnakeDeletedPair = snakeDeletedPair.first;
    int xSnakeDeletedPair = snakeDeletedPair.second;
    if (xSnakeDeletedPair != -1 && ySnakeDeletedPair != -1) board[xSnakeDeletedPair][ySnakeDeletedPair] = ' ';
}
void printBoard() {
    for (int i = -1; i < HEIGHT + 1; i++) {
        cout << "\t\t\t\t\|";
        for (int j = 0; j < WIDTH; j++) {
            if (i == -1 || i == HEIGHT) cout << "-";
            else cout << board[i][j];
        }
        cout << "|" << endl;
    }
    cout << "\t\t\t\tSCORE : " << score << "\n\n";
}

int main()
{
    score = 0;
    board = vector<vector<char>>(HEIGHT, vector<char>(WIDTH, ' '));
    bool gameOver = false;
    food.foodPos();
    while (!gameOver) {
        updateBoard();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
        printBoard();
        if (_kbhit()) { //change directions? 
            int c = _getch();
            if (c == UP)snake.changeDirection("up");
            else if (c == DOWN)snake.changeDirection("down");
            else if (c == RIGHT)snake.changeDirection("right");
            else if (c == LEFT)snake.changeDirection("left");
        }
        snake.move();
        if (snake.checkIfCollided()) {
            gameOver = true;
            cout << "\t\t\t\tGame Over!" << endl << "\t\t\t\tYour score is: " << score << endl;
        }
        if (snake.checkFood(food)) {
            snake.grow();
            while (true) {
                food.foodPos();
                pair<int, int> foodPos = food.getPos();
                if (board[foodPos.second][foodPos.first] != 'O')break;
            }
            score += 10;
        }
        Sleep(100);
    }
    return 0;
}

