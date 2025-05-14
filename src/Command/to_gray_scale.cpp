//
// Created by danielramaa on 5/14/25.
//

#include "Command/to_gray_scale.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        to_gray_scale::to_gray_scale() : Command("to_gray_scale") {}

        Image *to_gray_scale::apply(Image *img) {
            int width = img->width();
            int height = img->height();
            for (int x = 0; x < width; ++x) {
                for (int y = 0; y < height; ++y) {
                    Color pixel = img->at(x, y);

                    //trasnform each pixel to (v,v,v)
                    int v = (pixel.red() + pixel.green() + pixel.blue()) / 3;

                }

            }
            return img;
        }
    }
}