#ifndef TANK_H
#define TANK_H

#include <conio.h>

#include "Constants.h"
#include "Position.h"

#include "ConsoleUI.h"

class Tank
{
public:
    Tank() = default;
    Tank(Position position, int lives, COLOR color);
    Tank(const Tank&) = delete;
    Tank& operator=(const Tank&) = delete;

    void initialize();
    void draw() const;
    void move(int btnCode);
private:
    char     tank_[TANK_WIDTH][TANK_HEIGHT];
    Position position_;
    int      lives_;
    COLOR    color_;
    DIRECTION direction_;

    ConsoleUI& console_;

    void clear() const;
    bool isCollision(Position checkPosition, int offsetX, int offsetY) const;
};

#endif // !TANK_H



