#include "../include/FwImage.h"
#include <iostream>

FwImage::FwImage(std::string filename) : name(filename)
{

    if( !img.LoadFromFile(filename) )
    {
        std::cout<<"Image: " << filename << " failed to load." << std::endl;
    }
}

const std::string& FwImage::getName() const
{
   return FwImage::name; 
}
