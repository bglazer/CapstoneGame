#include "../include/SFML/Window/Window.hpp"
#include "../include/SFML/Graphics.hpp"
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

sf::RenderWindow *app;
sf::Clock gameClock;
ImageLoader* img_loader;
std::vector<sf::Image*>* imgs;
std::vector<sf::Sprite*>* sprites;

bool quit = false;

bool initialize();
void update();
void draw();
void cleanup();

int main( int argc, char* argv[] )
{
    if(initialize())
    {
        while(quit == false)
        {
            update();
            draw();
        }

        cleanup();
    }
    
    return 1;
}

bool initialize()
{
	app =  new sf::RenderWindow( sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP), "SFML Window" );
    img_loader = new ImageLoader();
    imgs = new std::vector<sf::Image*>();
    sprites = new std::vector<sf::Sprite*>();

    img_flyweight* block_fw = img_loader->load_image( "./resources/block.png" ); 
    FwImage block_fwimg = block_fw->get();
    sf::Image* block_img = &block_fwimg.getImage();

    imgs->push_back(block_img);

    sprites->push_back(new sf::Sprite(*block_img));
}

void update()
{
    const sf::Input& Input = app->GetInput();

	sf::Event event;
    bool leftKeyPress = Input.IsKeyDown(sf::Key::Left);
    bool rightKeyPress = Input.IsKeyDown(sf::Key::Right);
    bool upKeyPress = Input.IsKeyDown(sf::Key::Up);
    bool downKeyPress = Input.IsKeyDown(sf::Key::Down);
    unsigned int MouseX;
    unsigned int MouseY;

    float ElapsedTime = gameClock.GetElapsedTime();
    gameClock.Reset();
   
	while( app->GetEvent(event) )
	{
        if( event.Type == sf::Event::Closed )
            quit = true;

        if( (event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))
            quit = true;

        if( leftKeyPress )
            sprites->at(0)->Move(0,-10);
        if( rightKeyPress )
            sprites->at(0)->Move(0,10);
        if( upKeyPress )
            sprites->at(0)->Move(10,0);
        if( downKeyPress )
            sprites->at(0)->Move(-10,0);
    }
    

    //Player->update
}

void draw()
{
    std::vector<sf::Sprite*>::iterator it = sprites->begin(); 

    app->Clear();

    for( it = sprites->begin(); it < sprites->end(); it++ )
    {
        app->Draw( **it );
    }

	app->Display();
}

void cleanup()
{
    delete img_loader;
    delete imgs;
    delete sprites;
    delete app;
}
