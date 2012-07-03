#include "./SFML/Graphics.hpp"
#include <string>

#ifndef FWIMAGE
#define FWIMAGE

class FwImage
{
    public:
        FwImage(std::string filename);
        const std::string& getName() const;
        const sf::Image& getImage() const;

    private:
        const std::string& name;
        sf::Image img;
}; 

#endif
