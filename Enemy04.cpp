#include "DefaultHeaderFiles.h"

Enemy04::Enemy04()
{
    int randSpawn = rand() % 1;
    x = 80;
    y = 15;
    AddMove(WEST, 1000);
    if (randSpawn == 0)
    {
        AddMove(SOUTH, 2000);
    }
    else if (randSpawn == 1)
    {
        AddMove(SOUTH, 10000);
    }
    row = 3;
    col = 3;
    speedX = 1;
    speedY = 1;
    color = LIGHTRED;

    isInTheScreen = false;

    updateDelayTimer = 0;
    updateDelayDuration = 20;

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

void Enemy04::Update(int elapsedTime)
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
}
