#include "../include/GameObject.h"
#include "../include/chipmunk/chipmunk.h"
#include "../include/SDL/SDL.h"
#include <vector>

#ifndef PLAYER_H
#define PLAYER_H

class Player : public GameObject
{
	private:
		int x_vel;
		int y_vel;
		SDL_Surface* screen;
                cpSpace* space;
                cpVect pos;
                cpBody* body;
                SDL_Surface* sprite;
		void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip );

	public:
		Player(cpSpace *space, SDL_Surface *screen, cpVect pos);
		void move(cpFloat x, cpFloat y);
		void handle_input( SDL_Event *event );
		void render();
		void update();
		std::vector<SDL_Rect>& get_rects();
		int get_x();
		int get_y();
		void set_x(int new_x);
		void set_y(int new_y);

};

#endif 