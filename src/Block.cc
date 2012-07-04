#include "../include/Block.h"

Block::Block(b2Vec2* position, float32 angle, b2World* world, sf::RenderWindow* app, ImageLoader *img_loader, std::string filename)
{
    this->app = app;

    img_flyweight* block_fw = img_loader->load_image( filename ); 
    fwimg = &block_fw->get();
    img = &fwimg->getImage();

    b2Vec2 size(img->GetWidth(), img->GetHeight());

//    std::cout << size.x << " " << size.y << std::endl;

    sprite = new sf::Sprite(*img);

    //Block Body Def
    blockBodyDef = new b2BodyDef();
    blockBodyDef->type = b2_dynamicBody;
    blockBodyDef->position.Set(position->x, position->y);
    blockBodyDef->angle = angle;
    
    sprite->SetCenter(size.x/2, size.y/2);

    //Block Body
    blockBody = world->CreateBody(blockBodyDef);

    //Block Polygon
    b2PolygonShape blockBox;
    blockBox.SetAsBox(size.x/PX_PER_METER/2, size.y/PX_PER_METER/2);
    
//    std::cout << size.x/PX_PER_METER << " " << size.y/PX_PER_METER << std::endl;

    //Block Fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &blockBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    blockBody->CreateFixture(&fixtureDef);
}

void Block::update()
{
    b2Vec2 position = blockBody->GetPosition();
    b2Vec2 velocity = blockBody->GetLinearVelocity();
    float32 angle_vel = blockBody->GetAngularVelocity();
    float32 angle = blockBody->GetAngle();

    sprite->SetPosition(position.x*PX_PER_METER, position.y*PX_PER_METER);
    sprite->SetRotation(-(angle * 180.0f)/3.14f);

    //std::cout << position.x << " " << position.y << std::endl;
    //std::cout << velocity.x << " " << velocity.y << std::endl << std::endl;
}

void Block::render()
{
    app->Draw( *sprite );
}
