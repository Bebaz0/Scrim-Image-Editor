//
// Created by Afonso Lima on 21/05/2025.
//

#ifndef ROTATE_RIGHT_H
#define ROTATE_RIGHT_H

#include "Rotate.hpp"

namespace prog {
    namespace command {
        class Rotate_right : public Rotate {
        public:
            Rotate_right();

        protected:
            // Implementation for right rotation
            virtual void direction(int x, int y, int width, int height, int& new_x, int& new_y) const;

        };
    }
}

#endif //ROTATE_RIGHT_H
