#include "engine.h"

const int SCREEN_W = 800;
const int SCREEN_H = 400;
const int FPS = 60;

Scene * current_scene;
Scene * next_scene;

void initGame(){
    InitWindow(SCREEN_W, SCREEN_H, "RayLib 2023");
    SetTargetFPS(FPS);

    current_scene = NULL;
    next_scene = NULL;
}

void GameLoop(){

    while (!WindowShouldClose())
    {
        double deltaTime = getFrameTime();
        // Update

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
}
