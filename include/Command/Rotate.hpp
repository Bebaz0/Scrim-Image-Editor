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
            ///@brief Used to initialize the command with the name of the inherited command
            Rotate(const std::string& name);

            ///@brief Changes the direction of the pixel depending on the rotation
            ///@param x coordinates of the original pixel
            ///@param y coordinates of the original pixel
            ///@param width dimensions of the image
            ///@param height dimensions of the image
            ///@param new_x coordinates of the rotated pixel
            ///@param new_y coordinates of the rotated pixel
            virtual void direction(int x, int y, int width, int height, int& new_x, int& new_y) const = 0;

        public:
            Image *apply(Image *img) override;
        };
    }
}

#endif //ROTATE_H
