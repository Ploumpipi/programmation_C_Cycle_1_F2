#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 780

SDL_Window *pWindow=NULL;
SDL_Renderer *pRenderer=NULL;


int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
       SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
       return 1;
       }else{
        //An SDL2 window = titre de la fenêtre
        //250 = position x et y
        pWindow=SDL_CreateWindow("An SDL2 window", 250, 250, WINDOW_WIDTH, WINDOW_HEIGHT,SDL_WINDOW_SHOWN);
        if(pWindow){
            pRenderer=SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
        }
       }
    if(pRenderer){
        //Set Color
        SDL_SetRenderDrawColor(pRenderer, 205, 92, 92, SDL_ALPHA_OPAQUE);
        //Clear Render
        SDL_RenderClear(pRenderer);
        //Update rendu (render)
        SDL_RenderPresent(pRenderer);
    }
    SDL_Delay(10000);

    if(pRenderer){//Si pRenderer a une référence je la détruit
        SDL_DestroyRenderer(pRenderer);
    }
    if(pWindow){// Si pWindow a une référence je la détruit
        SDL_DestroyWindow(pWindow);
    }
    //SDL_DestroyRenderer(pRenderer);
    //SDL_DestroyWindow(pWindow);
    SDL_Quit();

    return 0;
}
