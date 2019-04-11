#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"
SDL_Rect scrolling(SDL_Rect camera, SDL_Rect positionplayer)
{
    if(positionplayer.x>=1440)
    {
        camera->x++;
    }
    if(positionplayer.x<=480)
    {
        camera.x--;
    }
    if(positionplayer.y<=270)
    {
        camera.y--;
    }
    if(positionplayer.y>=810)
    {
        camera.y++;
    }
    return camera ;
}
