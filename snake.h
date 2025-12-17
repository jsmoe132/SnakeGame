#pragma once 

#include <vector>
using namespace std;

const int WIDTH = 20; 
const int HEIGHT = 20;

struct Position {
    int row;
    int col;
};

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
}; 

void runGame(); 

