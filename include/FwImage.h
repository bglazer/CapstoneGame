#include "./SFML/Graphics.hpp"
#include <string>

#ifndef FWIMAGE
#define FWIMAGE

class FwImage
{
    public:
        FwImage(std::string filename);
        const std::string& getName() const;
        sf::Image& getImage();

    private:
        const std::string& name;
        sf::Image img;
}; 

#endif
