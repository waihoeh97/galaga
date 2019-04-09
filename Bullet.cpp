#include "DefaultHeaderFiles.h"

Bullet::Bullet()
{
    x = 65;
    y = 5;
    row = 1;
    col = 1;
    speedX = 2;
    speedY = 2;
    color = YELLOW;

    updateDelayTimer = 0;
    updateDelayDuration = 60;

    isReverseDirection = false;

    char tempSprite[1][1] = {{'*'}};

    sprite = new char*[row];
    for (int i = 0; i < row; i++)
    {
        sprite[i] = new char[col];
        for (int j = 0; j < col; j++)
        {
            sprite[i][j] = tempSprite[i][j];
        }
    }
}

void Bullet::Update(int elapsedTime)
{
    updateDelayTimer += elapsedTime;
    if (updateDelayTimer < updateDelayDuration)
    {
        return;
    }
    updateDelayTimer %= updateDelayDuration;

    if (!isReverseDirection)
    {
        if (direction == NORTH)
        {
            MoveUp();
        }
        else if (direction == EAST)
        {
            MoveRight();
        }
        else if (direction == WEST)
        {
            MoveLeft();
        }
        else if (direction == SOUTH)
        {
            MoveDown();
        }
        else if (direction == NORTH_EAST)
        {
            MoveUp();
            MoveRight();
        }
        else if (direction == NORTH_WEST)
        {
            MoveUp();
            MoveLeft();
        }
        else if (direction == SOUTH_EAST)
        {
            MoveDown();
            MoveRight();
        }
        else if (direction == SOUTH_WEST)
        {
            MoveDown();
            MoveLeft();
        }
    }
    else
    {
        if (direction == NORTH)
        {
            MoveDown();
        }
        else if (direction == EAST)
        {
            MoveLeft();
        }
        else if (direction == SOUTH)
        {
            MoveUp();
        }
        else if (direction == WEST)
        {
            MoveRight();
        }
        else if (direction == NORTH_EAST)
        {
            MoveDown();
            MoveLeft();
        }
        else if (direction == NORTH_WEST)
        {
            MoveDown();
            MoveRight();
        }
        else if (direction == SOUTH_EAST)
        {
            MoveUp();
            MoveLeft();
        }
        else if (direction == SOUTH_WEST)
        {
            MoveUp();
            MoveRight();
        }
    }

    if (CheckOverBoundary())
    {
        isToBeDestroyed = true;
    }
}
