#include "DefaultHeaderFiles.h"

class GameObject
{
public:
    int x, y, xOld, yOld, row, col, speedX, speedY, color;
    char** sprite;
    bool isToBeDestroyed;

    int updateDelayTimer;
    int updateDelayDuration;

    GameObject();

    void DrawTrail();
    void Draw();
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();

    bool CheckOverBoundary();
    virtual void Update(int elapsedTime);
};
