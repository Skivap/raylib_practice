#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef enum{
    UP, DOWN, LEFT, RIGHT, NONE
} DIRECTION;

typedef enum{
    CLASSIC
} PLAYER_TYPE;

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

    bool isWalking;
} Player;

Player Create_Player(PLAYER_TYPE TYPE);
void Draw_Player(Player * player);
void Update_Player(Player * player, float deltaTime);

#endif
