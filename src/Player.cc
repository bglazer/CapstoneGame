#include "../include/Player.h"
#include "../include/ImageLoader.h"
#include "../include/SDL/SDL.h"
#include "../include/SDL/SDL_image.h"
#include "../include/chipmunk/chipmunk.h"
#include <iostream>

Player::Player(cpSpace *space, SDL_Surface *screen, cpVect pos)
{
    this->screen = screen;
    this->pos = pos;
    this->space = space;
    
    cpFloat i = cpMomentForCircle(10, 10,0,cpv(0,0));
    body = cpBodyNew(10, i);
    cpCircleShape shape = cpCircleShape();
    
    cpSpaceAddBody(this->space, body);
    
    ImageLoader* il = new ImageLoader();
    sprite = il->load_image("../resources/dot.bmp");
}

void Player::handle_input( SDL_Event *event )
{
    if( event->type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event->key.keysym.sym )
        {
            case SDLK_UP: cpBodyApplyImpulse(body, cpv(0, -100), cpv(0,0)); break;
            case SDLK_DOWN: break;
            case SDLK_LEFT: cpBodyApplyImpulse(body, cpv(-100, 0), cpv(0,0)); break;
            case SDLK_RIGHT: cpBodyApplyImpulse(body, cpv(100, 0), cpv(0,0)); break;
            default: ;
        }
    }
}

void Player::move(cpFloat x, cpFloat y)
{
    pos.x = x;
    pos.y = y;
}

int Player::get_x()
{
	return 1;
}

void Player::set_x(int new_x)
{
}

int Player::get_y()
{
	return 1;
}

void Player::set_y(int new_y)
{
}

void Player::render()
{
    apply_surface( pos.x, pos.y, sprite, screen, NULL );
}

void Player::update()
{
    cpVect pos = cpBodyGetPos(body);
    cpVect vel = cpBodyGetVel(body);

    move(pos.x,pos.y);
}

void Player::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}
