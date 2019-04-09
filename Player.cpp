#include "DefaultHeaderFiles.h"

Player::Player()
{
    x = 30;
    y = 30;
    row = 3;
    col = 3;
    speedX = 1;
    speedY = 1;
    color = YELLOW;

    bulletType = STRAIGHT;
    updateDelayDuration = 60;

    enableShooting = false;
    score = 0;
    life = 5;
    shootDelayTimer = 0;
    shootDelayDuration = 10;

    char tempSprite[3][3] = {
                                {' ', (char)239, ' '},
                                {'//', '.', '\\'},
                                {'\\', '_', '//'}
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

void Player::Update(int elapsedTime)
{
    updateDelayTimer += elapsedTime;
    if (updateDelayTimer < updateDelayDuration)
    {
        return;
    }
    updateDelayTimer %= updateDelayDuration;

    shootDelayTimer += elapsedTime;
    if (shootDelayTimer < shootDelayDuration)
    {
        return;
    }
    shootDelayTimer %= shootDelayDuration;

    if (GetAsyncKeyState(VK_LEFT))
    {
        MoveLeft();
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        MoveRight();
    }
    if (GetAsyncKeyState(VK_SPACE))
    {
        if (clock() - clockTime > 1000)
        {
            enableShooting = true;
            clockTime = clock();
        }
        else
        {
            enableShooting = false;
        }
    }

    if (CheckOverBoundary())
    {
        x = xOld;
        y = yOld;
    }
}
