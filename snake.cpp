#include "snake.h"
#include <iostream>
using namespace std;

// Foward declarations
void drawBoard(const vector<Position>& snake, const Position& food);
void moveSnake(vector <Position>& snake, Direction dir);

void runGame() {
    
