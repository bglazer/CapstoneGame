/* 
 * File:   StaticBlock.h
 * Author: Bryan
 *
 * Created on February 14, 2012, 6:47 PM
 */

#include "Box2D.h"
#include "ImageLoader.h"
#include "SFML/Graphics.hpp"

#ifndef STATICBLOCK_H
#define	STATICBLOCK_H

class StaticBlock
{
    public:
        StaticBlock(b2Vec2* position, float32 angle, b2World* world, sf::RenderWindow* app, ImageLoader *img_loader, std::string filename);
        void render();
    private:
        b2BodyDef *staticBodyDef;
        b2Body *staticBody;
        sf::Sprite *sprite;
        const FwImage* fwimg;
        const sf::Image* img;
        sf::RenderWindow* app;
};

#endif	/* STATICBLOCK_H */

