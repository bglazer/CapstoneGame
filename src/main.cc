#include "../include/SFML/Window/Window.hpp"
#include "../include/SFML/Graphics.hpp"
#include "../include/Box2D/Box2D.h"
#include "../include/Player.h"
#include "../include/Block.h"
#include "../include/StaticBlock.h"
#include "../include/ImageLoader.h"
#include <string>
#include <iostream>

//Screen attributes
const float32 SCREEN_WIDTH_MKS = 10.0f;
const float32 SCREEN_HEIGHT_MKS = 10.0f;
const int SCREEN_WIDTH_PX = SCREEN_WIDTH_MKS * PX_PER_METER;
const int SCREEN_HEIGHT_PX = SCREEN_HEIGHT_MKS * PX_PER_METER;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 60;

ImageLoader *img_loader;
sf::RenderWindow *app;
sf::Clock gameClock;
b2Vec2* gravity;
b2World* world;
b2BodyDef *groundBodyDef;
b2Body *groundBody;

Block *block;
Block *block2;

bool quit = false;

bool initialize();
void update();
void draw();
void cleanup();

int main( int argc, char* argv[] )
{
	B2_NOT_USED(argc);
	B2_NOT_USED(argv);

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
	app =  new sf::RenderWindow( sf::VideoMode(SCREEN_WIDTH_PX, SCREEN_HEIGHT_PX, SCREEN_BPP), "SFML Window" );
    img_loader = new ImageLoader();

    gravity = new b2Vec2(0.0f, 1.0f);
    world = new b2World(*gravity);

    block = new Block(new b2Vec2(1.6,-1), 5.14, world, app, img_loader, "./resources/block.png");
    block2 = new Block(new b2Vec2(1,5), 3.14, world, app, img_loader, "./resources/block.png");
    
    //Ground Body Def
    groundBodyDef = new b2BodyDef();
    groundBodyDef->position.Set(0.0f, 10.0f);
    groundBody = world->CreateBody(groundBodyDef);

    //Ground Polygon
    b2PolygonShape groundBox;
    groundBox.SetAsBox(60.0f, 1.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    return 1;
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
   
    world->Step(1.0f/FRAMES_PER_SECOND, 6, 2);

    block->update();
    block2->update();

	while( app->GetEvent(event) )
	{
        if( event.Type == sf::Event::Closed )
            quit = true;

        if( (event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))
            quit = true;
    }
}

void draw()
{
    app->Clear(sf::Color(255,255,255));

    block->render();
    block2->render();

	app->Display();
}

void cleanup()
{
    delete world;
    delete gravity;
    delete app;
}
