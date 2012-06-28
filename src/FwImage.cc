#include "../include/FwImage.h"
#include <iostream>

FwImage::FwImage(std::string filename)
{
    sf::Image img;
    
    name = filename;

    if( !img.LoadFromFile(filename) )
    {
        std::cout<<"Image: " << filename << " failed to load." << std::endl;
    }
}

std::string FwImage::getName()
{
   return name; 
}
