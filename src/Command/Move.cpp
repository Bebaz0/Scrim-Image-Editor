//
// Created by danielramaa on 5/19/25.
//


#include "Command/Move.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include "Command.hpp"
#include "Command/Fill.hpp"


namespace prog {
    namespace command {
        Move::Move(int x, int y, Color fill) : Command("Move"), x_(x), y_(y), fill_(fill) {} //initialize members

        Image* Move::apply(Image* img) {
            int width = img->width();
            int height = img->height();

            Image* new_img = new Image(width, height, fill_);

            //iterate through the destination image
            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    //calculate source coordinates
                    int src_x = x - x_;
                    int src_y = y - y_;

                    //copy pixels from source if in bounds
                    if (src_x >= 0 && src_x < width && src_y >= 0 && src_y < height) {
                        new_img->at(x, y) = img->at(src_x, src_y);
                    }
                    //else the pixel keeps the fill color from constructor
                }
            }

            delete img;
            return new_img;
        }
    }
}