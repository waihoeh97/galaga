#include "DefaultHeaderFiles.h"

class Player : public GameObject
{
public:
    bool enableShooting;
    int clockTime = 0;
    int score;
    int shootDelayTimer;
    int shootDelayDuration;
    int life;
    BULLET_TYPE bulletType;

    Player();
    void Update(int elapsedTime);
};
