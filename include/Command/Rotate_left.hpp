//
// Created by limaa on 20/05/2025.
//

#ifndef ROTATE_LEFT_H
#define ROTATE_LEFT_H

#include "Command.hpp"
#include "Color.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {
        class Rotate_left : public Command {

        public:
            Rotate_left(); //Function to rotate the image to the left no arguments needed
            Image *apply(Image *img) override;
        };
    }
}

#endif //ROTATE_LEFT_H
