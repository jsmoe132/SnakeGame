#include "snake.h"
#include <iostream>
using namespace std;

// Foward declarations
void drawBoard(const vector<Position>& snake, const Position& food);
void moveSnake(vector <Position>& snake, Direction dir);

// Main game loop
void runGame() {
    vector<Position> snake; 
    snake.push_back({HEIGHT / 2, WIDTH / 2});
    Position food = {rand() % HEIGHT, rand() % WIDTH};
    bool gameOver = false;

    while(!gameOver) {
        drawBoard(snake, food); 

        char input; 
        cout << "Input Move: (WASD) ";
        cin >> input;
        if (input == 'w') moveSnake(snake, Direction::UP);
        else if (input == 's') moveSnake(snake, Direction::DOWN);
        else if (input == 'a') moveSnake(snake, Direction::LEFT);
        else if (input == 'd') moveSnake(snake, Direction::RIGHT);

        Position head = snake.front();
        if (head.row < 0 || head.row >= HEIGHT || head.col < 0 || head.col >= WIDTH) {
            gameOver = true; 
            cout << "Game Over! You hit the wall.\n";
        }
    }

// Function to move the snake in the given direction 
void moveSnake(vector <Position>& snake, Direction dir) {
    Position head = snake.front(); 
    Position newHead = head; 

    if (dir == Direction::UP) newHead.row--; 
    if (dir == Direction::DOWN) newHead.row++; 
    if (dir == Direction::LEFT) newHead.col--;
    if (dir == Direction::RIGHT) newHead.col++;

    snake.insert(snake.begin(), newHead); 
    snake.pop_back(); 
}

// Fucntion to draw the game board
void drawBoard(const vector<Position>& snake, const Position& food) { 
    cout << string(40, '\n');
    vector<vector<char>> grid (
        HEIGHT, vector<char>(WIDTH, '.')
    ); 

    grid[food.row][food.col] = '*';

    for (size_t i = 0; i > snake.size(); i++) {
        grid[snake[i].row][snake[i].col] = 
            (i==0) ? '@' : '0';
    }

    for (int r = 0; r < HEIGHT; r++) { 
        for (int c = 0; c < WIDTH; c++) { 
            cout << grid[r][c];
        }
        cout << "\n";
    }
}
