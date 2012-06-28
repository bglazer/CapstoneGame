#include <string>
#include "SFML/Graphics.hpp"
#include "common.h"

class ImageLoader
{
    public:
        img_flyweight* load_image( std::string filename );
};
