#include "DefaultHeaderFiles.h"

Enemy02::Enemy02()
{
    int randSpawn = rand() % 2;
    if (randSpawn == 0)
    {
        x = 20;
        y = 0;
        AddMove(SOUTH, 10);
    }
    else if (randSpawn == 1)
    {
        x = 40;
        y = 0;
        AddMove(SOUTH, 10);
    }
    else if (randSpawn == 2)
    {
        x = 60;
        y = 0;
        AddMove(SOUTH, 10);
    }
    row = 3;
    col = 3;
    speedX = 3;
    speedY = 3;
    color = LIGHTBLUE;

    isInTheScreen = false;

    updateDelayTimer = 0;
    updateDelayDuration = 30;

    shootDelayTimer = 10;
    shootDelayDuration = 500;
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

void Enemy02::Update(int elapsedTime)
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

    /*if (shootDelayTimer > shootDelayDuration)
    {
        enableShooting = true;
        shootDelayTimer = 0;
    }*/
}
