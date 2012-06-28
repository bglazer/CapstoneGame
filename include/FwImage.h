#include "./SFML/Graphics.hpp"
#include <string>

class FwImage
{
    public:
        FwImage(std::string filename);
        std::string getName();

    private:
        std::string name;
}; 
