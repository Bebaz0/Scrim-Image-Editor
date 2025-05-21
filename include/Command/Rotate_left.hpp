//
// Created by limaa on 20/05/2025.
//

#ifndef ROTATE_LEFT_H
#define ROTATE_LEFT_H

#include "Rotate.hpp"

namespace prog {
    namespace command {
        class Rotate_left : public Rotate {
        public:
            Rotate_left();

        protected:
            // Implementation for left rotation
            virtual void direction(int x, int y, int width, int height, int& new_x, int& new_y) const;
        };
    }
}



#endif //ROTATE_LEFT_H
