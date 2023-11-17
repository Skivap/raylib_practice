#include <stdio.h>
#include <stdarg.h>
#include "GameScene.h"
#include "Engine.h"
#include "Utility.h"

const int SCREEN_W = 800;
const int SCREEN_H = 800;
const int FPS = 60;
const char * GAME_TITLE = "RayLib 2023";

Scene current_scene;

void initGame(){
    InitWindow(SCREEN_W, SCREEN_H, GAME_TITLE);
    if(!IsWindowReady())
        exit(1);
    SetTargetFPS(FPS);

    ChangeScene(Create_Game_Scene());
}

void StartGame(){

    Log("Initializing ...");

    initGame();

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        // Update
        current_scene.update(deltaTime);

        // Draw
        BeginDrawing();

        current_scene.draw();

        EndDrawing();
    }

    Log("Window Closed");
    Log("Exiting ... ");

    CloseWindow();
}

void ChangeScene(Scene next_scene){
    static bool first_scene = true;

    if(!first_scene){
        current_scene.destroy();
    }

    current_scene = next_scene;
    current_scene.init();

    first_scene = false;
}

static void vLog(char * message, va_list arg){
    static bool new_file = true;
	vprintf(message, arg);
	printf("\n");

    #ifdef LOG_ENABLED
    	FILE* pFile = fopen("log.txt", new_file ? "w" : "a");
    	if (pFile) {
    		vfprintf(pFile, message, arg);
    		fprintf(pFile, "\n");
    		fclose(pFile);
    	}
    	new_file = false;
    #endif
}

void Err_Log(char * message, ...){
    va_list arg;
    printf("ERR : ");
    va_start(arg, message);
    vLog(message, arg);
    va_end(arg);
    exit(1);
}

void Log(char * message, ...){
    #ifdef LOG_ENABLE
        va_list arg;
        printf("LOG : ");
    	va_start(arg, message);
    	vLog(message, arg);
    	va_end(arg);
    #endif
}
