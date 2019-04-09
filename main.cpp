#include "DefaultHeaderFiles.h"

int startTime = 0;
int currentTime = 0;
int elapsedTime = 0;
int lastUpdateTime = 0;

bool isExit = false;

Player player;

vector<Enemy*> enemyList;
vector<Bullet> playerBulletList;
vector<Bullet> enemyBulletList;
vector<SpawnInfo> spawnList;

void Header()
{
    int choice = 0;
    textcolor(LIGHTCYAN);
    gotoxy(27, 10);
    cout << "=======================";
    gotoxy(27, 11);
    cout << "|                     |";
    gotoxy(27, 12);
    cout << "|        GALAGA       |";
    gotoxy(27, 13);
    cout << "|                     |";
    gotoxy(27, 14);
    cout << "=======================";
    textcolor(WHITE);
    gotoxy(33, 20);
    cout << "1. Play game";
    gotoxy(33,21);
    cout << "2. Exit game";
    textcolor(LIGHTGREEN);
    gotoxy(30, 25);
    cout << "Your choice : ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Enjoy";
    }
    else
    {
        exit(0);
    }
    system("CLS");
    gotoxy(20, 12);
    textcolor(LIGHTRED);
    cout << "Try to survive as long as you can...";
    system("PAUSE>NUL");
    textcolor(LIGHTGREEN);
}

void DrawHUD()
{
    textcolor(LIGHTCYAN);
    gotoxy(BOUNDARY_LEFT, BOUNDARY_TOP - 1);
    cout << "Score : " << player.score;
    textcolor(WHITE);
    gotoxy(BOUNDARY_RIGHT - 9, BOUNDARY_TOP - 1);
    cout << "Life : ";
    textcolor(LIGHTRED);
    for (int i = 0; i < player.life; i++)
    {
        cout << char(233);
    }
    for (int i = 0; player.life + i < 5; i++)
    {
        cout << " ";
    }
    textcolor(LIGHTRED);
}

void DrawBorder()
{
    for (int i = BOUNDARY_LEFT; i < BOUNDARY_RIGHT; i++)
    {
        gotoxy(i, BOUNDARY_TOP);
        cout << char(205);
    }
    for (int i = BOUNDARY_LEFT; i < BOUNDARY_RIGHT; i++)
    {
        gotoxy(i, BOUNDARY_BOTTOM);
        cout << char(205);
    }
    for (int i = BOUNDARY_TOP; i < BOUNDARY_BOTTOM; i++)
    {
        gotoxy(BOUNDARY_LEFT, i);
        cout << char(186);
    }
    for (int i = BOUNDARY_TOP; i < BOUNDARY_BOTTOM; i++)
    {
        gotoxy(BOUNDARY_RIGHT, i);
        cout << char(186);
    }
    gotoxy(BOUNDARY_LEFT, BOUNDARY_TOP);
    cout << char(201);
    gotoxy(BOUNDARY_LEFT, BOUNDARY_BOTTOM);
    cout << char(200);
    gotoxy(BOUNDARY_RIGHT, BOUNDARY_TOP);
    cout << char(187);
    gotoxy(BOUNDARY_RIGHT, BOUNDARY_BOTTOM);
    cout << char(188);
}

void Shoot(bool isPlayer, GameObject& object)
{
    BULLET_TYPE tempBulletType;
    vector<Bullet>* tempBulletList;
    bool tempIsReverseDirection = false;

    if (isPlayer)
    {
        tempBulletType = ((Player*)&object)->bulletType;
        tempBulletList = &playerBulletList;
        player.enableShooting = false;
    }
    else
    {
        tempBulletType = ((Enemy*)&object)->bulletType;
        tempBulletList = &enemyBulletList;
        ((Enemy*)&object)->enableShooting = false;
        tempIsReverseDirection = true;
    }

    if (tempBulletType == STRAIGHT)
    {
        if (isPlayer)
        {
            Bullet tempBullet;
            tempBullet.x = object.x + 1;
            tempBullet.y = object.y + 1;
            tempBullet.direction = NORTH;
            tempBullet.color = WHITE;
            tempBullet.isReverseDirection = tempIsReverseDirection;
            tempBulletList->push_back(tempBullet);
        }
        else
        {
            Bullet tempBullet;
            tempBullet.x = object.x + 1;
            tempBullet.y = object.y + 1;
            tempBullet.direction = NORTH;
            tempBullet.color = WHITE;
            tempBullet.isReverseDirection = tempIsReverseDirection;
            tempBulletList->push_back(tempBullet);
        }
    }
}

bool CheckBoundingBoxCollision(GameObject a, GameObject b)
{
    if (a.x + a.col < b.x ||
        a.x > b.x + b.col ||
        a.y + a.row < b.y ||
        a.y > b.y + b.row)
    {
        return false;
    }
    return true;
}

void CheckCollision()
{
    //! enemy vs bullet
    for (int i = 0; i < enemyList.size(); i++)
    {
        for (int j = 0; j < playerBulletList.size(); j++)
        {
            if (CheckBoundingBoxCollision(*enemyList[i], playerBulletList[j]))
            {
                //! true -> both object colliding
                enemyList[i]->isToBeDestroyed = true;
                playerBulletList[i].isToBeDestroyed = true;
                player.score += 10;
            }
        }
    }
    //! player vs enemy Bullet
    for (int i = 0; i < enemyBulletList.size(); i++)
    {
        if (CheckBoundingBoxCollision(enemyBulletList[i], player))
        {
            enemyBulletList[i].isToBeDestroyed = true;
            player.isToBeDestroyed = true;
            player.life -= 1;
        }
    }
    //! player vs enemy
    for (int i = 0; i < enemyList.size(); i++)
    {
        if (CheckBoundingBoxCollision(*enemyList[i], player))
        {
            enemyList[i]->isToBeDestroyed = true;
            player.isToBeDestroyed = true;
            player.life -= 1;
        }
    }
}

void SpawnEnemy(ENEMY_TYPE type)
{
    Enemy* tempEnemy;
    if (type == ENEMY_01)
    {
        tempEnemy = new Enemy01();
    }
    else if (type == ENEMY_02)
    {
        tempEnemy = new Enemy02();
    }
    else if (type == ENEMY_03)
    {
        tempEnemy = new Enemy03();
    }
    else if (type == ENEMY_04)
    {
        tempEnemy = new Enemy04();
    }
    enemyList.push_back(tempEnemy);
}

void AddEnemy(ENEMY_TYPE type, int time)
{
    SpawnInfo tempSpawnInfo;
    tempSpawnInfo.type = type;
    tempSpawnInfo.time = time;
    tempSpawnInfo.isSpawned = false;

    spawnList.push_back(tempSpawnInfo);
}

void AddEnemyPattern01(int timeOffset)
{
    AddEnemy(ENEMY_01, timeOffset + 10);
}

void AddEnemyPattern02(int timeOffset)
{
    AddEnemy(ENEMY_02, timeOffset + 10);
    AddEnemy(ENEMY_02, timeOffset + 10);
}

void AddEnemyPattern03(int timeOffset)
{
    AddEnemy(ENEMY_03, timeOffset + 10);
    AddEnemy(ENEMY_04, timeOffset + 10);
}

void InitializeSpawnList()
{
    for (int i = 0; i < 100; i++)
    {
        AddEnemyPattern01(1500 * i);
        AddEnemyPattern02(1500 * i);
        AddEnemyPattern03(1500 * i);
    }
}

void UpdateSpawn()
{
    for (int i = 0; i < spawnList.size(); i++)
    {
        if (spawnList[i].isSpawned == true)
        {
            continue;
        }
        if (currentTime - startTime > spawnList[i].time)
        {
            SpawnEnemy(spawnList[i].type);
            spawnList[i].isSpawned = true;
        }
    }
}

void HighScore()
{
    system("CLS");

    textcolor(LIGHTRED);
    cout << "Unfortunately you died..." << endl;
    textcolor(WHITE);
    cout << "Please enter your name : ";
    ofstream myFile("GalagaHighScore.txt", ios::app);

    string name = "";
    int s = player.score;

    cin >> name;

    if (myFile.is_open())
    {
        myFile << name << endl;
        myFile << player.score << endl;
        myFile.close();
    }
    else
    {
        cout << "Unable to open file";
    }

    string line;
    ifstream myfile("GalagaHighScore.txt", ios::app);

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << endl;
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

int main()
{
    system("mode con: cols=80 lines=40");
    srand(time(NULL));

    Header();
    system("CLS");

    DrawBorder();
    InitializeSpawnList();

    startTime = clock();

    do
    {
        currentTime = clock();
        //! Player
        player.Draw();
        player.Update(elapsedTime);
        if (player.enableShooting)
        {
            Shoot(true, player);
        }
            //! player bullet update
        for (int i = 0; i < playerBulletList.size(); i++)
        {
            playerBulletList[i].Update(elapsedTime);
        }
            //! player bullet draw
        for (int i = 0; i < playerBulletList.size(); i++)
        {
            if (playerBulletList[i].isToBeDestroyed)
            {
                playerBulletList[i].DrawTrail();
                playerBulletList.erase(playerBulletList.begin() + i);
                i--;
            }
            else
            {
                playerBulletList[i].Draw();
            }
        }
        if (player.life <= 0)
        {
            isExit = true;
        }

        //! Enemy
        UpdateSpawn();
            //! enemy update
        for (int i = 0; i < enemyList.size(); i++)
        {
            enemyList[i]->Update(elapsedTime);
            if (enemyList[i]->enableShooting)
            {
                Shoot(false, *enemyList[i]);
            }
        }
            //! enemy bullet update
        for (int i = 0; i < enemyBulletList.size(); i++)
        {
            enemyBulletList[i].Update(elapsedTime);
        }
            //! draw enemy
        for (int i = 0; i < enemyList.size(); i++)
        {
            //! is out of screen
            if (enemyList[i]->isToBeDestroyed)
            {
                enemyList[i]->DrawTrail();
                enemyList.erase(enemyList.begin() + i);
                i--;
            }
            else
            {
                //! Draw
                enemyList[i]->Draw();
            }
        }
            //! draw enemy bullet
        for (int i = 0; i < enemyBulletList.size(); i++)
        {
            //! is out of screen
            if (enemyBulletList[i].isToBeDestroyed)
            {
                enemyBulletList[i].DrawTrail();
                enemyBulletList.erase(enemyBulletList.begin() + i);
                i--;
            }
            else
            {
                //! Draw
                enemyBulletList[i].Draw();
            }
        }

        CheckCollision();

        DrawHUD();

        elapsedTime = (clock() - lastUpdateTime)*1000 / CLOCKS_PER_SEC;
        lastUpdateTime = clock();
        Sleep(25);
    } while (!isExit);

    HighScore();

    system("PAUSE");
    return 0;
}
