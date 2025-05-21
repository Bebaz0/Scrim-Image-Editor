//
// Created by limaa on 20/05/2025.
//

#include "Command/Rotate_left.hpp"


namespace prog {
    namespace command {
        Rotate_left::Rotate_left() : Rotate("Rotate_left") {}

        void Rotate_left::direction(int x, int y, int width, int height, int& new_x, int& new_y) const{
            // For 90° left rotation
            new_x = y;
            new_y = width - 1 - x;
        }
    }
}
