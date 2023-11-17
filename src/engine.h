#ifndef ENGINE_H
#define ENGINE_H

#include <stdlib.h>
#include "raylib.h"

// Window Screen Width
extern const int SCREEN_W;
// Window Screen Height
extern const int SCREEN_H;
// Frame per Second
extern const int FPS;

// Function Pointer
typedef void(*function_void)(void);
typedef void(*function_update)(float deltaTime);
typedef void(*function_key_down)(int key);

// Scene
typedef struct Scene{
    char * name;
    function_void init;
    function_void draw;
    function_void destroy;
    function_update update;
} Scene;

// Initialize the game
void initGame();
// Start Game Event Loop
void StartGame();
// Change Scene
void ChangeScene(Scene next_scene);
// Error Log
void Err_Log(char * message, ...);
// Log
void Log(char * message, ...);


#endif
