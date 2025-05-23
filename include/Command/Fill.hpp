//
// Created by Afonso Lima on 19/05/2025.
//

#ifndef FILL_H
#define FILL_H

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Fill : public Command {
        public:

            ///@brief Fills a rectangular area of the image with a color
            ///@param x The coordinates to start filling
            ///@param y The coordinates to start filling
            ///@param w  The width and height of the area to fill
            ///@param h  The width and height of the area to fill
            ///@param r  The color to fill
            ///@param g  The color to fill
            ///@param b  The color to fill

            Fill(int x,int y,int w, int h, int r,int g,int b);

            Image *apply(Image *img) override;

        private:
            int x;
            int y;
            int w;
            int h;
            Color fill;
        };
    }
}


#endif //FILL_H
