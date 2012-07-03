/* 
 * File:   Block.h
 * Author: Bryan
 *
 * Created on February 14, 2012, 6:47 PM
 */

#include "PhysicalObject.h"
#include "SFML/Graphics.hpp"
#include "ImageLoader.h"
#include "Box2D.h"

#ifndef BLOCK_H
#define	BLOCK_H

class Block : public PhysicalObject
{
        public:
            Block(b2Vec2* size, b2Vec2* position, float32 angle, b2World* world, sf::RenderWindow* app);
            Block(b2Vec2* position, float32 angle, b2World* world, sf::RenderWindow* app, ImageLoader &img_loader, std::string filename);
            void render();
            void update();
        private:
            b2BodyDef *blockBodyDef;
            b2Body *blockBody;
            sf::Sprite *sprite;
            bool using_image;
            const FwImage* block_fwimg;
            const sf::Image* block_img;
};

#endif 
