#ifndef GAME_H
#define GAME_H

#include <conio.h>

#include "Constants.h"
#include "ConsoleUI.h"

#include "Tank.h"

class Game
{
public:
    Game();
    void run() const;
private:
    std::unique_ptr<Tank> player_;

    ConsoleUI& console_;
    void drawMaze() const;
};

#endif // !GAME_H



