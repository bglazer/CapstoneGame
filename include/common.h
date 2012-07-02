#include <boost/flyweight.hpp>
#include <boost/flyweight/key_value.hpp>
#include "FwImage.h"

/* Header file that contains typedefs and forward declarations common to most files */

#ifndef COMMON
#define COMMON 

struct img_filename_extractor
{
    const std::string& operator()(const FwImage& x)const
    {
        return x.getName();
    }
};

typedef boost::flyweight< boost::flyweights::key_value<
                            std::string,
                            FwImage,
                            img_filename_extractor>
                        > img_flyweight;

#endif                        
