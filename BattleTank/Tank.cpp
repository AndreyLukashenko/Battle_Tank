#include "Tank.h"

Tank::Tank(Position position, int lives, COLOR color) : position_(position), lives_(lives), color_(color), 
    direction_(DIRECTION::DOWN), console_(ConsoleUI::getInstance())
{
    initialize();
}


void Tank::initialize()
{
    for (int i = 0; i < TANK_WIDTH; ++i)
        for (int j = 0; j < TANK_HEIGHT; ++j)
            tank_[i][j] = TANK_FIGURE_1;

    switch (direction_)
    {
    case DIRECTION::UP:
        tank_[0][1] = static_cast<char>(BARREL::VERTICAL);
        break;
    case DIRECTION::RIGHT:
        tank_[1][2] = static_cast<char>(BARREL::HORIZONTAL);
        break;
    case DIRECTION::DOWN:
        tank_[2][1] = static_cast<char>(BARREL::VERTICAL);
        break;
    case DIRECTION::LEFT:
        tank_[1][0] = static_cast<char>(BARREL::HORIZONTAL);
        break;
    }
}


void Tank::draw() const
{
    for (int i = 0; i < TANK_WIDTH; ++i)
        for (int j = 0; j < TANK_HEIGHT; ++j)
            console_.setChar(position_.x + i, position_.y + j, tank_[j][i], color_);
}


void Tank::clear() const
{
    for (int i = 0; i < TANK_WIDTH; ++i)
        for (int j = 0; j < TANK_HEIGHT; ++j)
            console_.setChar(position_.x + i, position_.y + j, '-', COLOR::LIGHT_CYAN);
}


void Tank::move(int btnCode)
{
    DIRECTION newDirection = static_cast<DIRECTION>(_getch());
    clear();

    if (direction_ != newDirection)
    {
        direction_ = newDirection;
        initialize();
    }
    else 
    {
        switch (direction_)
        {
        case DIRECTION::UP:
            if (!isCollision({position_.x, position_.y - 1}, TANK_WIDTH - 1, 0))
                --position_.y;
            break;
        case DIRECTION::RIGHT:
            if (!isCollision({position_.x + TANK_WIDTH, position_.y}, 0, TANK_HEIGHT - 1))
                ++position_.x;
            break;
        case DIRECTION::DOWN:
            if(!isCollision({position_.x, position_.y + TANK_HEIGHT}, TANK_WIDTH - 1, 0))
                ++position_.y;
            break;
        case DIRECTION::LEFT:
            if(!isCollision({position_.x - 1, position_.y}, 0, TANK_HEIGHT - 1))
                --position_.x;
            break;
        }
    }
}


bool Tank::isCollision(Position checkPosition, int offsetX, int offsetY) const
{
    for (int x = 0; x <= offsetX; ++x)
    {
        for (int y = 0; y <= offsetY; ++y)
        {
            if (console_.getChar(checkPosition.x + x, checkPosition.y + y) == static_cast<char>(MAZE_OBSTACLE::BRICK_WALL) ||
                console_.getChar(checkPosition.x + x, checkPosition.y + y) == static_cast<char>(MAZE_OBSTACLE::CONCRETE_WALL) ||
                console_.getChar(checkPosition.x + x, checkPosition.y + y) == static_cast<char>(MAZE_OBSTACLE::FENCE))
                return true;
        }
    }

    return false;
}
