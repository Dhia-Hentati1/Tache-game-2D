/**
* @file rotozoom.c
*/
#include"objet.h"
#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include <SDL/SDL_rotozoom.h>

/**
* @brief To initialize the objet o .
* @param o the objet
* @param x the position x of image
* @param y the position y of image
* @return Nothing
*/
void OBJET_Init(obj *o, int x, int y){
	o->image_entite = IMG_Load("coin1.png");
	o->x = x;
	o->y = y;
}

/**
* @brief To rotate the image o->image_entite .
* @param o the objet
* @param ecran the ecran
* @param backg the background
* @return Nothing
*/
void rotation_objet(obj o, SDL_Surface* ecran,SDL_Surface *backg,SDL_Rect position)
{
    SDL_Surface  *rotation = NULL;
SDL_Event event ;
    SDL_Rect rect;
    double angle = 0;
    double zoom = 1;
    int sens = 1;
    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
    int TEMPS=30;

while(continuer)

{SDL_PollEvent(&event);
 switch (event.type)
   { case SDL_QUIT :
 continuer =0;
break;}

        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > TEMPS)
        {
            angle += 2;
            tempsPrecedent = tempsActuel;
        }
        else
        {
            SDL_Delay(TEMPS - (tempsActuel - tempsPrecedent));

        }
        rotation = rotozoomSurface(o.image_entite, angle, zoom, 0);
       o.dst.x = 200;

       o.dst.y =  200;
        SDL_BlitSurface(backg , NULL, ecran, &position);
        SDL_BlitSurface(rotation , NULL, ecran, &o.dst);
       SDL_FreeSurface(rotation);
        if(zoom >= 2){sens = 0;}
        else if(zoom <= 0.5)
             {
                 sens = 1;
             }
        if(sens == 0){zoom -= 0.02;}
        else{zoom += 0.02;}
        SDL_Flip(ecran);

   }
}
