#include "DefaultHeaderFiles.h"

class Bullet : public GameObject
{
public:
    DIRECTION direction;
    bool isReverseDirection;
    Bullet();

    void Update(int elapsedTime);
};
