#include "../include/SDL/SDL.h"
#include "../include/SDL/SDL_image.h"
#include "../include/ImageLoader.h"
#include <string>
#include <iostream>

SDL_Surface* ImageLoader::load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }
    else
    {
        printf("IMG_Load: %s\n", IMG_GetError());
    }

    //Return the optimized surface
    return optimizedImage;
}
