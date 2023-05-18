#ifndef TYPES_H
#define TYPES_H

#include <iostream>

namespace meliora{

    namespace types{
        using vecint = std::vector<int>;
        using vecvec = std::vector<vecint>;
        using mapRD = std::map<vecint, float>;
    }
}

#endif //end TYPES_H