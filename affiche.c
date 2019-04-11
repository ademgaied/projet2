#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
SDL_Rect scrolling(SDL_Rect camera, SDL_Rect positionplayer)
{
    if(positionplayer.x>=45)
    {
        camera.x++; 
    }
    if(positionplayer.x<=68)
    {
        camera.x--;
    }
    if(positionplayer.y<=45)
    {
        camera.y--;  
    }
    if(positionplayer.y>=98)
    {
        camera.y++;    
    }
    return camera ;    
}


int main(int argc, char *argv[])
{ SDL_Rect camera ;


char pause;
SDL_Surface *screen = NULL, *ecran = NULL , *image = NULL;
SDL_Rect positionecran,positionplayer;
Mix_Music *musique;
camera= scrolling(camera ,  positionplayer);
  positionecran.x = 0;
    positionecran.y = 0;
SDL_Surface *back=NULL;
SDL_Rect pull;
back=IMG_Load("voiture.png");
pull.x=5;
pull.y=385;

 
    SDL_Init(SDL_INIT_VIDEO);
 
    screen = SDL_SetVideoMode(1600,900, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("TunDrive", NULL);
    image = IMG_Load("sidibouside.png");
 
     
    SDL_BlitSurface(image, NULL, screen, &positionecran);
    SDL_BlitSurface(back, NULL, screen, &pull);

    
    

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
           { 
           printf("%s",Mix_GetError());
           }
           musique=Mix_LoadMUS("music.mp3");
           Mix_PlayMusic(musique, -1);
SDL_Flip(screen);
    


int continuer=1;

while (continuer)
{	SDL_Event event;
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE: 
                    continuer = 0;
                    break;
            }
            break;
    }
}
    








//pause=getchar();
SDL_FreeSurface(screen);

SDL_Quit();
 

   
 
    
   return 0;
 }
