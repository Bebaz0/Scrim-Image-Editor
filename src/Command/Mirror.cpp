//
// Created by limaa on 23/05/2025.
//

#include "Command/Mirror.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        Mirror::Mirror(const std::string& name) : Command(name) {}

        Image* Mirror::apply(Image* img) {
            // Create a new image with the same dimensions as the original
            Image* new_img = new Image(img->width(), img->height());
            for (int y = 0; y < img->height(); ++y) {
                for (int x = 0; x < img->width(); ++x) {
                    int new_x, new_y;
                    direction(x, y, img->width(), img->height(), new_x, new_y);
                    new_img->at(new_x,new_y)= img->at(x,y);
                }
            }
            return new_img;
        }
    }
}