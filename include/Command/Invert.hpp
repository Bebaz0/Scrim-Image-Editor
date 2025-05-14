#ifndef PROJECT_INVERT_HPP
#define PROJECT_INVERT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Invert : public Command {
        public:
            Invert();
            Image *apply(Image *img) override;
        };
    }
}

#endif //PROJECT_INVERT_HPP