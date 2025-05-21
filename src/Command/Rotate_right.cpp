//
// Created by Afonso Lima on 21/05/2025.
//

#include "Command/Rotate.hpp"
#include "Command/Rotate_right.hpp"

namespace prog {
    namespace command {
        Rotate_right::Rotate_right() : Rotate("Rotate_right") {}

        void Rotate_right::direction(int x, int y, int width, int height, int& new_x, int& new_y) const {
            // For 90° right rotation
            new_x = height - 1 - y;
            new_y = x;
        }


    }
};
