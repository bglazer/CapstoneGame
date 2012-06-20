/* 
 * File:   StaticBlock.h
 * Author: Bryan
 *
 * Created on February 14, 2012, 6:47 PM
 */

#include "../include/GameObject.h"
#include "../include/chipmunk/chipmunk.h"

#ifndef STATICBLOCK_H
#define	STATICBLOCK_H

class StaticBlock
{
        public:
            StaticBlock(cpSpace* space, SDL_Surface* screen, cpVect pos, int size);
            void render();
        private:
            cpFloat x;
            cpFloat y;
            cpFloat width;
            cpFloat height;
            cpBody* body;
            cpShape* shape;
            SDL_Surface* img, screen;
};

#endif	/* STATICBLOCK_H */

