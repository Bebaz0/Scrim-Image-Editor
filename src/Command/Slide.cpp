//
// Created by danielramaa on 5/21/25.
//


#include "Command/Slide.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog{
    namespace command{
        Slide::Slide(int x, int y) : Command("Slide"), x_(x), y_(y) {}
        Image *Slide::apply(Image *img) {
            int width = img->width();
            int height = img->height();

            Image* new_img = new Image(width, height);
            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    //calculate source coordinates with wrapp
                    int src_x = (x - x_ + width) % width;  //subtract x_ to get src pixels
                    int src_y = (y - y_ + height) % height; // Subtract y_ to get src pixels
                    new_img->at(x, y) = img->at(src_x, src_y);
                }
            }

            return new_img;
        }
    }
}