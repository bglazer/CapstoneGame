#include "../include/StaticBlock.h"

StaticBlock::StaticBlock(b2Vec2* position, float32 angle, b2World* world, sf::RenderWindow* app, ImageLoader *img_loader, std::string filename)
{   
    this->app = app;

    img_flyweight* block_fw = img_loader->load_image( filename ); 
    fwimg = &block_fw->get();
    img = &fwimg->getImage();

    b2Vec2 size(img->GetWidth(), img->GetHeight());

    //Ground Body Def
    staticBodyDef = new b2BodyDef();
    staticBodyDef->position.Set(position->x, position->y);
    staticBodyDef->angle = angle;
    staticBody = world->CreateBody(staticBodyDef);

    //Ground Polygon
    b2PolygonShape staticBox;

    staticBox.SetAsBox(size.x/PX_PER_METER/2, size.y/PX_PER_METER/2);

//    std::cout << size.x/PX_PER_METER/2 << " " <<  size.y/PX_PER_METER/2 << std::endl;

    staticBody->CreateFixture(&staticBox, 0.0f);

    sprite = new sf::Sprite(*img);

    sprite->SetPosition(position->x*PX_PER_METER, position->y*PX_PER_METER);
    sprite->SetCenter(size.x/2, size.y/2);
}

void StaticBlock::render()
{
    app->Draw( *sprite);
}

