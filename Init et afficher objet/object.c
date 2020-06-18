/**
* @file object.c
*/
#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "object.h"
/**
* @brief To initialize the object .
* @param obj the object
* @param image the image
* @return Nothing
*/
SDL_Surface*Init(SDL_Surface*obj,SDL_Surface*image)
{
	SDL_Rect posecran;
	SDL_Rect posobj;
	obj=IMG_Load("pomme.png");
	if(obj==NULL)
	{
		printf("Cannot load image %s",SDL_GetError());
	}
	else
	{
		posecran.x=0;
		posecran.y=0;
		posecran.w=image->w;
		posecran.h=image->h;
		posobj.x=275;
		posobj.y=150;
	}
	return obj;
}
/**
* @brief To show the object .
* @param obj the object
* @param image the image
* @param screen the screen
* @return Nothing
*/
void aff_obj(SDL_Surface*obj,SDL_Surface* screen,SDL_Surface*image)
{
	SDL_Rect posecran;
	SDL_Rect posobj;
	image=IMG_Load("backx.png");
	SDL_BlitSurface(image,NULL,screen,&posecran);
	SDL_BlitSurface(obj,NULL,screen,&posobj);	
	SDL_Flip(screen);
	SDL_FreeSurface(image);
	SDL_FreeSurface(obj);
}
