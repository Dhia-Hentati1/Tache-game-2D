/**
* @file main.c;
* @author Dhia Hentati
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include"objet.h"

int main()

{

obj o;
SDL_Rect position;
SDL_Event event ;
int continuer =1;
 SDL_Surface  *rotation = NULL;
 SDL_Rect rect;
    double angle = 0;
    double zoom = 1;
    int sens = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
    int TEMPS=10;
   SDL_Surface* ecran = NULL;

    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);
    ecran = SDL_SetVideoMode(800, 800, 32, SDL_HWSURFACE| SDL_DOUBLEBUF );

    SDL_Surface* backg = NULL;
    backg = IMG_Load("menu2.jpg");
    SDL_BlitSurface(backg, NULL, ecran,& position);
    SDL_WM_SetCaption("Rotozoom", NULL);
    SDL_Flip(ecran);


OBJET_Init(&o,0,200);

while(continuer)
{
while(SDL_PollEvent(&event))
		{

			if(event.type==SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
		{
				continuer= 0;
		}}}
rotation_objet(o,ecran,backg,position);

SDL_FreeSurface(ecran);
SDL_FreeSurface(backg);
SDL_FreeSurface(o.image_entite);
SDL_Quit ();
}
