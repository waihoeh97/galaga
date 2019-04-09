#include "DefaultHeaderFiles.h"

Enemy01::Enemy01()
{
    x = 10;
    y = 5;
    AddMove(EAST, 10);

    row = 3;
    col = 3;
    speedX = 1;
    speedY = 1;
    color = GREEN;

    isInTheScreen = false;

    updateDelayTimer = 0;
    updateDelayDuration = 60;

    shootDelayTimer = 10;
    shootDelayDuration = 1000;
    enableShooting = false;
    bulletType = STRAIGHT;

    char tempSprite[3][3] = {
                                {'X','X','X'},
                                {'X','X','X'},
                                {' ','X',' '}
                            };

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

void Enemy01::Update(int elapsedTime)
{
    updateDelayTimer += elapsedTime;
    shootDelayTimer += elapsedTime;
    moveTimer += elapsedTime;

    if (updateDelayTimer < updateDelayDuration)
    {
        return;
    }
    updateDelayTimer %= updateDelayDuration;

    UpdateMove(elapsedTime);

    if (shootDelayTimer > shootDelayDuration)
    {
        enableShooting = true;
        shootDelayTimer = 0;
    }

    int randSpawn = rand() % 3;

    if (CheckOverBoundary())
    {
        if (x > 25)
        {
            if (randSpawn == 0)
            {
                AddMove(SOUTH_WEST, 10);
            }
            else if (randSpawn == 1)
            {
                AddMove(WEST, 10);
            }
        }
        else if (x < 10)
        {
            if (randSpawn == 2)
            {
                AddMove(SOUTH_EAST, 10);
            }
            else if (randSpawn == 3)
            {
                AddMove(EAST, 10);
            }
        }
    }
}
