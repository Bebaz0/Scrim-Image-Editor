//
// Created by limaa on 23/05/2025.
//


#ifndef MIRROR_H
#define MIRROR_H

#include <Command.hpp>
#include "Image.hpp"

namespace prog {
    namespace command {
        class Mirror : public Command {
        protected:
            ///@brief Used to initialize the command with the name of the inherited command
            Mirror(const std::string& name);

            /// @brief Changes the direction of the pixel depending on if it is a horizontal or vertical mirror
            /// @param x x-coordinate of the original pixel
            /// @param y y-coordinate of the original pixel
            /// @param width dimensions of the image
            /// @param height dimensions of the image
            ///@return new_x,new_y coordinates of the mirrored pixel
            virtual void direction(int x, int y, int width, int height, int& new_x, int& new_y)const = 0;

        public:
            Image *apply(Image *img) override;
        };
    }
}

#endif //MIRROR_H
