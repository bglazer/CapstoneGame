#include <string>
#include "SFML/Graphics.hpp"
#include "common.h"

#ifndef IMAGE_LOADER
#define IMAGE_LOADER

class ImageLoader
{
    public:
        img_flyweight* load_image( std::string filename );
};

#endif
