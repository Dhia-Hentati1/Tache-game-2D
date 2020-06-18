#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>

/**
* @struct objet
* @brief struct for objet
*/
typedef struct obj {
	SDL_Surface *image_entite; /*!< Surface. */
	int x,y;
	SDL_Rect dst; /*!< Rectangle*/
} obj;
void OBJET_Init(obj *o, int x, int y);
void rotation_objet(obj o, SDL_Surface *ecran,SDL_Surface *backg,SDL_Rect position);



#endif // OBJET_H_INCLUDED
