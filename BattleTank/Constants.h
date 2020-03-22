#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "Position.h"

enum class COLOR {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
    LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN,
    LIGHT_CYAN, LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE
};

// MAZE SETUP
const int FIELD_WIDTH = 42;
const int FIELD_HEIGHT = 33;

enum class MAZE_OBSTACLE {
    FENCE = '*',
    BRICK_WALL = 'X',
    CONCRETE_WALL = '#',
    BASE = 'B'
};

const char MAZE[FIELD_HEIGHT][FIELD_WIDTH] = {
    "*****************************************",
    "*---------------------------------------*",
    "*---------------------------------------*",
    "*---------------------------------------*",
    "*---XXX---XXX---XXX---XXX---XXX---XXX---*",
    "*---XXX---XXX---XXX###XXX---XXX---XXX---*",
    "*---XXX---XXX---XXX###XXX---XXX---XXX---*",
    "*---XXX---XXX---XXX---XXX---XXX---XXX---*",
    "*---XXX---XXX---------------XXX---XXX---*",
    "*---XXX---XXX---------------XXX---XXX---*",
    "*---------------------------------------*",
    "*---------------XXX---XXX---------------*",
    "*---------------XXX---XXX---------------*",
    "*XX---XXXXXXX---------------XXXXXXX---XX*",
    "*XX---XXXXXXX---------------XXXXXXX---XX*",
    "*##---XXXXXXX---------------XXXXXXX---##*",
    "*---------------XXX---XXX---------------*",
    "*---------------XXX---XXX---------------*",
    "*---------------XXXXXXXXX---------------*",
    "*---XXX---XXX---XXXXXXXXX---XXX---XXX---*",
    "*---XXX---XXX---XXX---XXX---XXX---XXX---*",
    "*---XXX---XXX---XXX---XXX---XXX---XXX---*",
    "*---XXX---XXX---------------XXX---XXX---*",
    "*---XXX---XXX---------------XXX---XXX---*",
    "*---XXX---XXX---------------XXX---XXX---*",
    "*----------------XXXXXXX----------------*",
    "*----------------XXBBBXX----------------*",
    "*----------------XXBBBXX----------------*",
    "*****************************************",
    "*                                       *",
    "* Score:       Lives:      Enemies:     *",
    "*                                       *",
    "*****************************************"
};

// TANK
const int TANK_WIDTH = 3;
const int TANK_HEIGHT = 3;

const char TANK_FIGURE_1 = '0';
const char TANK_FIGURE_2 = '|';

const Position PLAYER_TANK_POSITION { 19,20 };
enum class DIRECTION { UP = 72, RIGHT = 77, DOWN = 80, LEFT = 75 };
enum class BARREL { HORIZONTAL = '-', VERTICAL = '|' };

#endif // !CONSTANTS_H
