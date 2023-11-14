#include <stdio.h>
#include <stdarg.h>
#include "GameScene.h"
#include "engine.h"

const int SCREEN_W = 800;
const int SCREEN_H = 800;
const int FPS = 60;
const char * TITLE = "RayLib 2023";

Scene * current_scene;

void initGame(){
    InitWindow(SCREEN_W, SCREEN_H, TITLE);
    if(!IsWindowReady())
        exit(1);
    SetTargetFPS(FPS);

    current_scene = NULL;
    ChangeScene(Create_Game_Scene());
}

void GameLoop(){

    while (!WindowShouldClose())
    {
        double deltaTime = GetFrameTime();

        // Update
        current_scene->update(deltaTime);

        // Draw
        BeginDrawing();

        current_scene->draw();

        EndDrawing();
    }

    CloseWindow();
}

void ChangeScene(Scene * next_scene){
    //if(current_scene != NULL)
    current_scene = next_scene;
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
    va_start(arg, message);
    vLog(message, arg);
    va_end(arg);
    exit(1);
}

void Log(char * message, ...){
    #ifdef LOG_ENABLE
        va_list arg;
    	va_start(arg, message);
    	vLog(message, arg);
    	va_end(arg);
    #endif
}
