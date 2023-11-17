#include <stdio.h>
#include "Player.h"
#include "Utility.h"

const float speed = 256.0f;
const float update_frame = 0.5f;
const float player_scale = 3.0f;

static float modulo(float a, float b){
    return a > b ? a - b : a;
}

Player Create_Player(){
    Player player;
    player.x = 25;
    player.y = 25;
    player.tick = 0;

    player.idle1 = im_load("assets/player_idle1.png");
    player.idle2 = im_load("assets/player_idle2.png");

    return player;
}

void Draw_Player(Player * player){
    bool flip = player->dir == LEFT ? true : false;
    Texture2D texture = (int)(player->tick * 2.0f / update_frame) == 0 ? player->idle1 : player->idle2;

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

    if(IsKeyDown(KEY_W)){
        player->y -= speed * deltaTime;
    }
    if(IsKeyDown(KEY_S)){
        player->y += speed * deltaTime;
    }
    if(IsKeyDown(KEY_A)){
        player->x -= speed * deltaTime;
        player->dir = LEFT;
    }
    if(IsKeyDown(KEY_D)){
        player->x += speed * deltaTime;
        player->dir = RIGHT;
    }

    player->tick = modulo(player->tick + deltaTime, update_frame);

    return;
}
