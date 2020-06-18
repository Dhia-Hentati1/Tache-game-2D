#pragma once
/**
* @struct Clochard
* @brief struct for Clochard
*/
typedef struct Clochard {
	SDL_Surface *sprite,*sprite2; /*!< Surface. */
	int x,y;
	int dx,cx;
} Clochard;

void CLOCHARD_Init(Clochard *c, int x, int y);
void CLOCHARD_Render(Clochard *c, SDL_Surface **screen);

