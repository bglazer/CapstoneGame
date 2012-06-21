#ifndef TERRAIN_H
#define TERRAIN_H

#include "../include/GameObject.h"
//#include "../include/chipmunk/chipmunk.h"

class Terrain : public GameObject
{
    public:
        Terrain();
        virtual ~Terrain();
        virtual void render()=0;
    protected:
    private:
/*
        cpBody body;
        cpShape shape;
*/
};

#endif // TERRAIN_H
