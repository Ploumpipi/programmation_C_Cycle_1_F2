#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 780

SDL_Window *pWindow=NULL;
SDL_Renderer *pRenderer=NULL;


int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){//Initialisation de la SDL
       SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
       return 1;
       }else{
        //An SDL2 window = titre de la fenêtre
        //250 = position x et y
        pWindow=SDL_CreateWindow("Exercice SDL2", 250, 250, WINDOW_WIDTH, WINDOW_HEIGHT,SDL_WINDOW_SHOWN);//Création de la fenêtre SDL_CreateWindow(titre, axe x, axe y, largeur, longueur, flags)
        if(pWindow){
            pRenderer=SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
        }
       }
    if(pRenderer){
        //Set Couleur fond d'écran
        SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        //
        SDL_RenderClear(pRenderer);
/*-----------------------------------------------------------------------------------------------------------------*/
        SDL_Rect rectanglevide;
            rectanglevide.x = 50;
            rectanglevide.y = 50;
            rectanglevide.h = 100;
            rectanglevide.w = 200;
        //on défini le rendu du rectangle en noir(rect sera dans la couleur voulu avec l'opacité voulu)
        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        //Rendu du SDL_Rect
        SDL_RenderDrawRect(pRenderer, &rectanglevide);
/*-----------------------------------------------------------------------------------------------------------------*/
        //SDL_Point point={0, 0}; il faut déclarer un point x et un point y pour le SDL_Point
        SDL_Rect rectangleplein; //SDL_Rect défini deux points x et y qui sont dans un tableau
            rectangleplein.x = (WINDOW_WIDTH/2);
            rectangleplein.y = 50;
            rectangleplein.h = 100;
            rectangleplein.w = 200;
        //on défini le rendu du rectangle en noir(rect sera dans la couleur voulu avec l'opacité voulu)
        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        //Rendu du SDL_Rect
        SDL_RenderFillRect(pRenderer, &rectangleplein);
        //Update rendu (render)
        SDL_RenderPresent(pRenderer);
        //Appel de la fonction cercle plein
        //void DrawFillCircle(SDL_Renderer *pRenderer, 50, 400, 30, SDL_Color color);
    }
    SDL_Delay(10000);

    if(pRenderer){//Si pRenderer a une référence je la détruit
        SDL_DestroyRenderer(pRenderer);
    }
    if(pWindow){// Si pWindow a une référence je la détruit
        SDL_DestroyWindow(pWindow);
    }

    SDL_Quit();

    return 0;
}

// Dessine le cercle donné, rempli
/*void DrawFillCircle(SDL_Renderer *p_renderer, int origin_x, int origin_y, int radius, SDL_Color color)
{
    for(double dy = 1; dy <= radius; dy += 1.0){
        double dx = floor(sqrt((2.0 * radius * dy) - (dy * dy)));
        SDL_SetRenderDrawColor(p_renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLine(p_renderer, origin_x - dx, origin_y + dy - radius, origin_x + dx, origin_y + dy - radius);
        SDL_RenderDrawLine(p_renderer, origin_x - dx, origin_y - dy + radius, origin_x + dx, origin_y - dy + radius);
    }
    SDL_SetRenderDrawColor(p_renderer, 0, 0, 0, 0);
}*/
