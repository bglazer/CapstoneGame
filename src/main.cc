#include "../include/SFML/Window/Window.hpp"
#include "../include/Player.h"
#include "../include/Block.h"
#include "../include/StaticBlock.h"
#include "../include/ImageLoader.h"
#include <string>
#include <iostream>

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 60;

Player *player;
Block *block;
StaticBlock *ground;
sf::Window *App;
//Timer fps;
//cpSpace* space;

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
	App = new sf::Window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP), "SFML Window");
}

void update()
{
    const sf::Input& Input = App->GetInput();

	sf::Event event;
    bool LeftKeyPress = Input.IsKeyDown(sf::Key::Left);
    bool RightKeyPress = Input.IsKeyDown(sf::Key::Right);
    bool UpKeyPress = Input.IsKeyDown(sf::Key::Up);
    bool DownKeyPress = Input.IsKeyDown(sf::Key::Down);
    unsigned int MouseX;
    unsigned int MouseY;


	while( App->GetEvent(event) )
	{
        if( event.Type == sf::Event::Closed )
            quit = true;

        if( (event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))
            quit = true;

        if( LeftKeyPress )
            std::cout << "Left Key\n";
    }

}

void draw()
{
	App->Display();
}
