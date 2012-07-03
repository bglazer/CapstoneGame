#include "../include/Block.h"

Block::Block(b2Vec2* position, float32 angle, b2World* world, sf::RenderWindow* app, ImageLoader *img_loader, std::string filename)
{
    this->app = app;

    img_flyweight* block_fw = img_loader->load_image( filename ); 
    block_fwimg = &block_fw->get();
    block_img = &block_fwimg->getImage();

    b2Vec2 size(block_img->GetWidth(), block_img->GetHeight());

    std::cout << size.x << " " << size.y << std::endl;

    sprite = new sf::Sprite(*block_img);
    sprite->SetCenter(size.x/2, size.y/2);

    //Block Body Def
    blockBodyDef = new b2BodyDef();
    blockBodyDef->type = b2_dynamicBody;
    blockBodyDef->position.Set(position->x, position->y);

    //Block Body
    blockBody = world->CreateBody(blockBodyDef);

    //Block Polygon
    b2PolygonShape blockBox;
    blockBox.SetAsBox(size.x, size.y);

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

    std::cout << position.x << " " << position.y << std::endl;
    std::cout << velocity.x << " " << velocity.y << std::endl << std::endl;
}

void Block::render()
{
    app->Draw( *sprite );
}
