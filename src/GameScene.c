#include "GameScene.h"

static void init(){

}

static void draw(){
    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
}

static void update(double deltaTime){

}

Scene * Create_Game_Scene(){
    Log("Creating Game Scene ... ");

    Scene * scene = (Scene*)malloc(sizeof(Scene));
    scene->name = "Game Scene";
    scene->init = &init;
    scene->draw = &draw;
    scene->update = &update;

    Log("Game Scene Created");

    return scene;
}
