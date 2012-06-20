#include "../include/GameObject.h"

class PhysicalObject : public GameObject
{
    public:
        PhysicalObject();
        virtual ~PhysicalObject();
        virtual void render() = 0;
    protected:
    private:
        
};