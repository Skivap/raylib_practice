#include <stdio.h>
#include <stdlib.h>
#include "Map.h"
#include "Utility.h"
#include "Engine.h"

static const float tiles_scale = 3.0f;

Map Create_Map(char * path){
    FILE * pfile = fopen(path, "r");

    Map map;

    fscanf(pfile, "%d%d", &map.row, &map.col);

    map.board = (char**)malloc(map.row * sizeof(char*));

    for(int i=0; i<map.row; i++){
        map.board[i] = (char*)malloc(map.col * sizeof(char));

        for(int j=0; j<map.col; j++){
            fscanf(pfile, " %c", &map.board[i][j]);
        }
    }

    fclose(pfile);

    map.tiles = im_load("assets/tiles.png");

    return map;
}

void Draw_Map(Map * map){
    for(int i=0; i<map->row; i++){
        for(int j=0; j<map->col; j++){
            switch(map->board[i][j]){
                case 'G':
                case 'T':
                    DrawTextureEx(
                        map->tiles,
                        (Vector2){
                            j * map->tiles.height * tiles_scale,
                            i * map->tiles.width * tiles_scale
                        }, // position
                        0.0f,
                        tiles_scale,
                        WHITE
                    );
                    break;
                default:
                    break;
            }
        }
    }
}

void Destroy_Map(Map * map){
    for(int i=0; i<map->row; i++){
        free(map->board[i]);
    }
    free(map->board);
}
