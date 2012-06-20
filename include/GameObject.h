#include "chipmunk/chipmunk.h"
#include "SDL/SDL.h"

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();
        virtual void render() = 0;
    protected:
    private:
};

#endif