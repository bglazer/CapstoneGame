#include <string>
#include <iostream>
#include <boost/flyweight.hpp>
#include <boost/flyweight/key_value.hpp>
#include "../include/SFML/Graphics.hpp"
#include "../include/ImageLoader.h"
#include "../include/common.h"

img_flyweight* ImageLoader::load_image( std::string filename )
{
    img_flyweight* img_fw = new img_flyweight( filename );
    return img_fw;
}
