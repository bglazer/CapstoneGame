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

sf::RenderWindow *app;
sf::Clock gameClock;
ImageLoader* img_loader;
std::vector<const sf::Image*>* imgs;
std::vector<sf::Sprite*>* sprites;
b2Vec2* gravity;
b2World* world;
b2BodyDef *groundBodyDef, *dynamicBodyDef;
b2Body *groundBody, *dynamicBody;

const FwImage* block_fwimg;
const sf::Image* block_img;
sf::Sprite* block_sprite;

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

    imgs = new std::vector<const sf::Image*>();
    sprites = new std::vector<sf::Sprite*>();

    gravity = new b2Vec2(0.0f, 1.0f);
    world = new b2World(*gravity);

    //Ground Body Def
    groundBodyDef = new b2BodyDef();
    groundBodyDef->position.Set(0.0f, 10.0f);
    groundBody = world->CreateBody(groundBodyDef);

    //Ground Polygon
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 1.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    //Block Body Def
    dynamicBodyDef = new b2BodyDef();
    dynamicBodyDef->type = b2_dynamicBody;
    dynamicBodyDef->position.Set(0.0f, 4.0f);

    //Block Body
    dynamicBody = world->CreateBody(dynamicBodyDef);
    dynamicBody->SetAngularVelocity( 3.14f );

    //Block Polygon
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    //Block Fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    dynamicBody->CreateFixture(&fixtureDef);

    img_flyweight* block_fw = img_loader->load_image( "./resources/block.png" ); 
    block_fwimg = &block_fw->get();
    block_img = &block_fwimg->getImage();

    block_sprite = new sf::Sprite(*block_img);
    block_sprite->SetCenter(0.5f*PX_PER_METER,0.5f*PX_PER_METER);

    imgs->push_back(block_img);

    sprites->push_back(block_sprite);

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

    b2Vec2 position = dynamicBody->GetPosition();
    b2Vec2 velocity = dynamicBody->GetLinearVelocity();
    float32 angle_vel = dynamicBody->GetAngularVelocity();
    float32 angle = dynamicBody->GetAngle();

    //std::cout<< "x: " << position.x << " y: " << position.y << std::endl;

    sprites->at(0)->Move(velocity.x, velocity.y);
    sprites->at(0)->SetRotation(-(angle * 180.0f)/3.14f);

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
    std::vector<sf::Sprite*>::iterator it = sprites->begin(); 

    app->Clear(sf::Color(255,255,255));

    for( it = sprites->begin(); it < sprites->end(); it++ )
    {
        app->Draw( **it );
    }

	app->Display();
}

void cleanup()
{
    delete img_loader;
    delete world;
    delete gravity;
    delete imgs;
    delete sprites;
    delete app;
}
