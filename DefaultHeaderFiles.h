#ifndef _DEFAULT_HEADER_FILES_H
#define _DEFAULT_HEADER_FILES_H

#include <iostream>
#include <windows.h>
#include <vector>
#include <time.h>
#include <fstream>
#include "conio_yp.h"

using namespace std;

#define BOUNDARY_LEFT 4
#define BOUNDARY_RIGHT 77
#define BOUNDARY_TOP 3
#define BOUNDARY_BOTTOM 38

enum DIRECTION
{
    NORTH = 0,
    SOUTH,
    EAST,
    WEST,
    NORTH_EAST,
    NORTH_WEST,
    SOUTH_EAST,
    SOUTH_WEST,
};

enum ENEMY_TYPE
{
    ENEMY_01 = 0,
    ENEMY_02,
    ENEMY_03,
    ENEMY_04,
};

enum BULLET_TYPE
{
    STRAIGHT = 0,
};

struct SpawnInfo
{
    ENEMY_TYPE type;
    int time;
    bool isSpawned;
};

struct MoveInfo
{
    DIRECTION direction;
    int time;
    bool isCompleted;
};

#include "GameObject.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Enemy01.h"
#include "Enemy02.h"
#include "Enemy03.h"
#include "Enemy04.h"

#endif // _DEFAULT_HEADER_FILES_H
