#include "DefaultHeaderFiles.h"

class Enemy : public GameObject
{
public:
    int killScore;
    bool isInTheScreen;

    BULLET_TYPE bulletType;
    bool enableShooting;
    int shootDelayTimer;
    int shootDelayDuration;

    int moveTimer;
    vector<MoveInfo> moveList;

    Enemy();

    virtual void Update(int elapsedTime);
    void AddMove(DIRECTION direction, int time);
    void UpdateMove(int elapsedTime);
};
