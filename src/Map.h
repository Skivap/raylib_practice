#ifndef MAP_H
#define MAP_H

#include "raylib.h"

typedef struct Map{
    char ** board;
    int row;
    int col;

    Texture2D tiles;
    
} Map;

Map Create_Map();
void Draw_Map(Map * map);

#endif
