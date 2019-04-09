#include "DefaultHeaderFiles.h"

Enemy::Enemy()
{
    killScore = 0;
    isInTheScreen = false;
}

void Enemy::Update(int elapsedTime)
{

}

void Enemy::AddMove(DIRECTION direction, int time)
{
    MoveInfo tempMoveInfo;
    tempMoveInfo.direction = direction;
    tempMoveInfo.time = time;
    tempMoveInfo.isCompleted = false;

    moveList.push_back(tempMoveInfo);
}

void Enemy::UpdateMove(int elapsedTime)
{
    for (int i = 0; i < moveList.size(); i++)
    {
        if (moveList[i].isCompleted == true)
        {
            continue;
        }

        if (moveTimer > moveList[i].time)
        {
            if (moveList[i].direction == NORTH)
            {
                MoveUp();
            }
            else if (moveList[i].direction == EAST)
            {
                MoveRight();
            }
            else if (moveList[i].direction == SOUTH)
            {
                MoveDown();
            }
            else if (moveList[i].direction == WEST)
            {
                MoveLeft();
            }
            else if (moveList[i].direction == NORTH_EAST)
            {
                MoveUp();
                MoveRight();
            }
            else if (moveList[i].direction == NORTH_WEST)
            {
                MoveUp();
                MoveLeft();
            }
            else if (moveList[i].direction == SOUTH_EAST)
            {
                MoveDown();
                MoveRight();
            }
            else if (moveList[i].direction == SOUTH_WEST)
            {
                MoveDown();
                MoveLeft();
            }

            if (i > 0)
            {
                moveList[i-1].isCompleted = true;
            }
        }
    }
}
