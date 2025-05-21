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
            ///@brief Rotates the image 90º to the left with center as the pivot
            Rotate_left();

        protected:
            ///@brief Implementation for left rotation details for the function are in Rotate.hpp
            virtual void direction(int x, int y, int width, int height, int& new_x, int& new_y) const;
        };
    }
}



#endif //ROTATE_LEFT_H
