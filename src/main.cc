#include "../include/SFML/SFML_Window.h"
#include "../include/Player.h"
#include "../include/Timer.h"
#include "../include/Block.h"
#include "../include/StaticBlock.h"
#include "../include/ImageLoader.h"
#include <string>

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 60;

Player *player;
Block *block;
StaticBlock *ground;
Timer fps;
cpSpace* space;

bool quit = false;

bool initialize();
void update();
void draw();

int main( int argc, char* argv[] )
{
    if(initialize())
    {
        while(quit == false)
        {
            update();
            draw();
        }
    }
    
    return 1;
}

bool initialize()
{
	sf::Window App(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP), "SFML Window");
	
}

void update()
{
}

void draw()
{
	App.Display();
}
