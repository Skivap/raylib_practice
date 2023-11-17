#include "GameScene.h"
#include "Map.h"
#include "Player.h"

static Map map;
static Player player;
static Camera2D camera;

static void init(){
    // initialize the map
    map = Create_Map("assets/map.txt");
    // create Player
    player = Create_Player();
    // create Camera
    camera = (Camera2D){0};
    camera.target = (Vector2){player.x, player.y};
    camera.offset = (Vector2){ SCREEN_W / 2.0f, SCREEN_H / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

static void draw(){
    ClearBackground(RAYWHITE);
    //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    BeginMode2D(camera);
    {
        Draw_Map(&map);
        Draw_Player(&player);
    }
    EndMode2D();
}

static void update(float deltaTime){
    Update_Player(&player, deltaTime);
    camera.target = (Vector2){player.x, player.y};
}

static void destroy(){

}

Scene Create_Game_Scene(){
    Log("Creating Game Scene ... ");

    Scene scene;
    scene.name = "Game Scene";
    scene.init = &init;
    scene.draw = &draw;
    scene.destroy = &destroy;
    scene.update = &update;

    Log("Game Scene Created");

    return scene;
}
