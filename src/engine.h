#ifndef ENGINE_H
#define ENGINE_H

#include <stdlib.h>
#include "raylib.h"

/* Why Extern ??
It's a bad idea to put global variable in header file,
as all files compiled together and they share the same header file,
which lead to multiple declaration of variable

If it's necessary then we can declare it in a single c file
and use extern at the header file so every c file can share the same variable
*/

#define LOG_ENABLE

// Window Screen Width
extern const int SCREEN_W;
// Window Screen Height
extern const int SCREEN_H;
// Frame per Second
extern const int FPS;

// Function Pointer
typedef void(*function_void)(void);
typedef void(*function_update)(double deltaTime);
typedef void(*function_key_down)(int key);

// Scene
typedef struct Scene{
    char * name;
    function_void init;
    function_void draw;
    function_update update;
} Scene;

// Initialize the game
void initGame();
// Start Game Event Loop
void GameLoop();
// Change Scene
void ChangeScene(Scene * next_scene);
// Error Log
void Err_Log(char * message, ...);
// Log
void Log(char * message, ...);


#endif
