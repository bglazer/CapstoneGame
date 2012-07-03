/* 
 * File:   Block.h
 * Author: Bryan
 *
 * Created on February 14, 2012, 6:47 PM
 */

#include "PhysicalObject.h"

#ifndef BLOCK_H
#define	BLOCK_H

class Block : public PhysicalObject
{
        public:
            Block();
            void render();
            void update();
        private:
};

#endif 
