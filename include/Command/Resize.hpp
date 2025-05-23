#ifndef RESIZE_HPP
#define RESIZE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Resize : public Command {
        public:
            ///@brief Resizes the selection of the image to the width and height of the original image
            ///@param x area to resize
            ///@param y area to resize
            ///@param w width of the area to resize
            ///@param h height of the area to resize
            Resize(int x, int y, int w, int h);

            Image *apply(Image *img) override;

        private:
            int x_;
            int y_;
            int w_;
            int h_;
        };
    }
}

#endif //RESIZE_HPP
