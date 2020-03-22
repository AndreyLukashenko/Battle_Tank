#include "Game.h"

Game::Game(): console_(ConsoleUI::getInstance()) 
{
    player_ = std::make_unique<Tank>(PLAYER_TANK_POSITION, 3, COLOR::MAGENTA);
}


void Game::run() const
{
    drawMaze();
    while (true)
    {
        if (_kbhit())
        {
            player_->move(_getch());
            console_.clearInputBuffer();
        }
        player_->draw();
        console_.render();
        Sleep(1);
    }
}


void Game::drawMaze() const
{
    for (int y = 0; y < FIELD_HEIGHT; ++y)
    {
        for (int x = 0; x < FIELD_WIDTH; ++x)
        {
            switch (MAZE[y][x])
            {
                case static_cast<char>(MAZE_OBSTACLE::BRICK_WALL) :
                    console_.setChar(x, y, MAZE[y][x], COLOR::RED);
                    break;
                case static_cast<char>(MAZE_OBSTACLE::CONCRETE_WALL) :
                    console_.setChar(x, y, MAZE[y][x], COLOR::BROWN);
                    break;
                case static_cast<char>(MAZE_OBSTACLE::FENCE) :
                    console_.setChar(x, y, MAZE[y][x], COLOR::WHITE);
                    break;
                case static_cast<char>(MAZE_OBSTACLE::BASE) :
                    console_.setChar(x, y, MAZE[y][x], COLOR::DARK_GRAY);
                    break;
                default:
                    console_.setChar(x, y, MAZE[y][x], COLOR::LIGHT_CYAN);
            }
        }
    }
}