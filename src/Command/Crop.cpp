//
// Created by Daniel on 21/05/2025.
//


#include "Command/Crop.hpp"
#include "Image.hpp"
#include "Color.hpp"


namespace prog {
    namespace command {
        Crop::Crop(int x, int y, int width, int height) : Command("Crop"), x_(x), y_(y), width_(width), height_(height) {}

        Image* Crop::apply(Image* img) {
            int img_width = img->width();
            int img_height = img->height();

            //crop boundaries coordinates
            int start_x = std::max(0, x_);
            int start_y = std::max(0, y_);
            int end_x = std::min(img_width, x_ + width_);
            int end_y = std::min(img_height, y_ + height_);

            //crop dimension
            int real_width = end_x - start_x;
            int real_height = end_y - start_y;

            /*exclusions:
             - crop is out of image bounds;
             - crop with a width and height of 0;
             - crop with negative dimensions.
             */
            if (real_width <= 0 || real_height <= 0 || start_x >= img_width || start_y >= img_height) {
                return img;
            }

            Image* cropped = new Image(real_width, real_height);
            for (int x = 0; x < real_width; ++x) {
                for (int y = 0; y < real_height; ++y) {
                    cropped->at(x, y) = img->at(start_x + x, start_y + y);
                }
            }
            return cropped;
        }
    }
}