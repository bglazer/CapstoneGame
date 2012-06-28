#include <boost/flyweight.hpp>
#include <boost/flyweight/key_value.hpp>

/* Header file that contains typedefs and forward declarations common to most files */

typedef boost::flyweight< boost::flyweights::key_value<
                            std::string,
                            sf::Image>
                        > img_flyweight;
