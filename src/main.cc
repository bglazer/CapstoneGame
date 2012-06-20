#include "../include/SDL/SDL_image.h"
#include "../include/SDL/SDL.h"
#include "../include/Player.h"
#include "../include/Timer.h"
#include "../include/Block.h"
#include "../include/StaticBlock.h"
#include "../include/ImageLoader.h"
#include "../include/chipmunk/chipmunk.h"
#include <string>

//Screen attributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 60;

SDL_Event event;
SDL_Surface *screen = NULL;
SDL_Surface *player_img = NULL, *block_img = NULL;
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
    cpInitChipmunk();
    
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Move the Dot", NULL );

    //load_content();

    cpVect gravity = cpv(0, 100);
   
    space = cpSpaceNew();
    
    cpSpaceInit(space); 
    
    cpSpaceSetGravity(space, gravity);
    
    cpVect player_pos = cpv(0,0);
    
    player = new Player(space, screen, player_pos);
    
    block = new Block(space, screen, cpv(50,50), 10, 1);
    
    ground = new StaticBlock(space, screen, cpv(0,150), 1);
    
    return true;
}

void update()
{
   //Start the frame timer
    fps.start();

    while( SDL_PollEvent( &event ) )
    {
        //Handle events for the dot
        player->handle_input( &event );

        //If the user has Xed out the window
        if( event.type == SDL_QUIT )
        {
            //Quit the program
            quit = true;
        }
    }

    player->update();
    block->update();

    cpFloat timeStep = 1.0/FRAMES_PER_SECOND; 

    cpSpaceStep(space, timeStep);

    //Cap the frame rate
    if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
    {
        SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
    }
}

void draw()
{
    SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xff, 0xff, 0xff ) );
    player->render();
    block->render();
    ground->render();
    
    if( SDL_Flip( screen ) == -1 )
    {
        quit = true;
    }
}
