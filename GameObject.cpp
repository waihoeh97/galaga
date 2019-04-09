#include "DefaultHeaderFiles.h"

GameObject::GameObject()
{
    isToBeDestroyed = false;
}

void GameObject::DrawTrail()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (xOld + j <= BOUNDARY_LEFT ||
                xOld + j >= BOUNDARY_RIGHT ||
                yOld + i <= BOUNDARY_TOP ||
                yOld + i >= BOUNDARY_BOTTOM)
            {
                continue;
            }
            gotoxy(xOld + j, yOld + i);
            cout << " ";
        }
    }
}

void GameObject::Draw()
{
    DrawTrail();
    textcolor(color);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (x + j <= BOUNDARY_LEFT ||
                x + j >= BOUNDARY_RIGHT ||
                y + i <= BOUNDARY_TOP ||
                y + i >= BOUNDARY_BOTTOM)
            {
                continue;
            }
            gotoxy(x + j, y + i);
            cout << sprite[i][j];
        }
    }
    textcolor(WHITE);
    xOld = x;
    yOld = y;
}

void GameObject::MoveLeft()
{
    x -= speedX;
}

void GameObject::MoveRight()
{
    x += speedX;
}

void GameObject::MoveUp()
{
    y -= speedY;
}

void GameObject::MoveDown()
{
    y += speedY;
}

bool GameObject::CheckOverBoundary()
{
    if (x <= BOUNDARY_LEFT ||
        x + col - 1 >= BOUNDARY_RIGHT ||
        y <= BOUNDARY_TOP ||
        y + row - 1 >= BOUNDARY_BOTTOM)
    {
        return true;
    }
    return false;
}

void GameObject::Update(int elapsedtime)
{

}
