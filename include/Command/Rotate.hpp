//
// Created by Afonso Lima on 21/05/2025.
//

#ifndef ROTATE_H
#define ROTATE_H


#include "Command.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {
        class Rotate : public Command {
        protected:
            Rotate(const std::string& name);

            // Changes the direction of the pixel depending on the rotation
            virtual void direction(int x, int y, int width, int height, int& new_x, int& new_y) const = 0;

        public:
            Image *apply(Image *img) override;
        };
    }
}

#endif //ROTATE_H
