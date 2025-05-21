//
// Created by danielramaa on 5/14/25.
//
#ifndef PROJECT_INVERT_HPP
#define PROJECT_INVERT_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Invert : public Command {
        public:
            ///@brief Inverts the colors of the image
            Invert();
            Image *apply(Image *img) override;
        };
    }
}

#endif //PROJECT_INVERT_HPP