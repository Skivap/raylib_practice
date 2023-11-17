#include <stdio.h>
#include "Player.h"
#include "Utility.h"
#include "Engine.h"

const float speed = 256.0f;
const float update_frame = 0.5f;
const float player_scale = 3.0f;

static float modulo(float a, float b){
    while(a > b)
        a -= b;
    return a;
}

Player Create_Player(PLAYER_TYPE TYPE){
    Player player;
    player.x = 25;
    player.y = 25;
    player.tick = 0;

    switch(TYPE){
        case CLASSIC:
            player.idle1 = im_load("assets/player_idle1.png");
            player.idle2 = im_load("assets/player_idle2.png");
            player.walk1 = im_load("assets/player_walk1.png");
            player.walk2 = im_load("assets/player_walk2.png");
            player.walk3 = im_load("assets/player_walk3.png");
            player.walk4 = im_load("assets/player_walk4.png");
            break;
        default:
            Err_Log("PLAYER TYPE NOT FOUND");
    }

    return player;
}

void Draw_Player(Player * player){
    bool flip = player->dir == LEFT ? true : false;
    Texture2D texture;

    int cur_frame = (int)(player->tick * 4.0f / update_frame);
    if(player->isWalking){
        switch(cur_frame){
            case 0:
                texture = player->walk1;
                break;
            case 1:
                texture = player->walk2;
                break;
            case 2:
                texture = player->walk3;
                break;
            case 3:
                texture = player->walk4;
                break;
            default:
                break;
        }
    }
    else{
        switch(cur_frame){
            case 0:
            case 1:
                texture = player->idle1;
                break;
            case 2:
            case 3:
                texture = player->idle2;
                break;
            default:
                break;
        }
    }

    Rectangle source = (Rectangle){
        0.0f,
        0.0f,
        texture.width * (flip ? -1 : 1),
        texture.height
    };
    Rectangle dest = (Rectangle){
        player->x,
        player->y,
        texture.width * player_scale,
        texture.height * player_scale
    };

    DrawTexturePro(
        texture,
        source,
        dest,
        (Vector2){0.0f, 0.0f},
        0.0f,
        WHITE
    );

#ifdef DEBUG_MODE
    // Draw the hitbox
    DrawRectangleLines(
        player->x + texture.width * player_scale / 6.0f,
        player->y, texture.width * player_scale * 2.0f / 3.0f,
        texture.height * player_scale,
        RED
    );

#endif

    return;
}

void Update_Player(Player * player, float deltaTime){
    player->isWalking = false;

    if(IsKeyDown(KEY_W)){
        player->isWalking = true;
        player->y -= speed * deltaTime;
    }
    if(IsKeyDown(KEY_S)){
        player->isWalking = true;
        player->y += speed * deltaTime;
    }
    if(IsKeyDown(KEY_A)){
        player->isWalking = true;
        player->x -= speed * deltaTime;
        player->dir = LEFT;
    }
    if(IsKeyDown(KEY_D)){
        player->isWalking = true;
        player->x += speed * deltaTime;
        player->dir = RIGHT;
    }

    player->tick = modulo(player->tick + deltaTime, update_frame);

    return;
}
