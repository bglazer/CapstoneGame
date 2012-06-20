/* 
 * File:   Block.h
 * Author: Bryan
 *
 * Created on February 14, 2012, 6:47 PM
 */

#include "../include/PhysicalObject.h"
#include "../include/chipmunk/chipmunk.h"

#ifndef BLOCK_H
#define	BLOCK_H

class Block : public PhysicalObject
{
        public:
            Block(cpSpace* space, SDL_Surface* screen, cpVect pos, cpFloat mass, int size);
            void render();
            void update();
        private:
            cpFloat x;
            cpFloat y;
            cpFloat width;
            cpFloat height;
            cpBody* body;
            cpShape* shape;
            SDL_Surface* img, screen;
};

#endif	/* BLOCK_H */

