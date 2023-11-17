#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef enum{
    UP = 2,
    DOWN = -2,
    LEFT = -1,
    RIGHT = 1,
    NONE = 0
} DIRECTION;

typedef struct Player{
    double x;
    double y;
    float tick;
    DIRECTION dir;

    Texture2D idle1;
    Texture2D idle2;
    Texture2D walk1;
    Texture2D walk2;
    Texture2D walk3;
    Texture2D walk4;
} Player;

Player Create_Player();
void Draw_Player(Player * player);
void Update_Player(Player * player, float deltaTime);

#endif
