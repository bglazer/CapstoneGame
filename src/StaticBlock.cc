#include "../include/StaticBlock.h"
#include "../include/SDL/SDL.h"
#include "../include/SDL/SDL_image.h"
#include "../include/chipmunk/chipmunk.h"
#include "../ImageLoader.h"

//Need additional args for constructor (mass, width height etc)?
StaticBlock::StaticBlock(cpSpace* space, SDL_Surface* screen, cpVect pos, int size)
{
    body = cpSpaceGetStaticBody(space);
    shape = cpBoxShapeNew(body, 40, 40);
//    cpBodyAddShape(body, shape);
    this->screen = *screen;
    
    //cpSpaceAddBody(space, body);
    
    cpBodySetPos(body, pos);
    
    ImageLoader* il = new ImageLoader();
    
    img = il->load_image("../resources/block.png");
    
    x = pos.x;
    y = pos.y;
}

void StaticBlock::render()
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( img, NULL, &screen, &offset );
}

