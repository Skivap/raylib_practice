#include "Utility.h"
#include "Engine.h"

Texture2D im_load(char * path){
    Texture2D ret = LoadTexture(path);

    if(!IsTextureReady(ret)){
        Err_Log("Not Loading Texture : %s", path);
    }

    Log("Loading \"%s\" successful", path);
    return ret;
}
