#include "../include/Block.h"
/* 
#include "../include/SDL/SDL.h"
#include "../include/SDL/SDL_image.h"
#include "../include/chipmunk/chipmunk.h"
*/

//Need additional args for constructor (mass, width height etc)?
Block::Block(/*cpSpace* space, SDL_Surface* screen, cpVect pos, cpFloat mass, int size*/)
{
/*
    cpFloat i = cpMomentForBox(mass, 40, 40);
    body = cpBodyNew(mass, i);
    shape = cpBoxShapeNew(body, 40, 40);
    this->screen = *screen;
    
    cpSpaceAddBody(space, body);
    
    cpBodySetPos(body, pos);
    
    ImageLoader* il = new ImageLoader();
    
    img = il->load_image("../resources/block.png");
*/
}

void Block::update()
{
/*
    cpVect pos = cpBodyGetPos(body);
    cpVect vel = cpBodyGetVel(body);
    
    x = pos.x;
    y = pos.y;
*/
}


void Block::render()
{
/*
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( img, NULL, &screen, &offset );
*/
}
