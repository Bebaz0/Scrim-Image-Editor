//
// Created by limaa on 20/05/2025.
//

#include "Command/Rotate_left.hpp"
#include "Color.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {

    Rotate_left::Rotate_left() : Command("Rotate_left")  {}

    Image *Rotate_left::apply(Image *img) {
            int width = img->width();
            int height = img->height();

            Image *final_image = new Image(height, width); // Create a new image with rotated dimensions
            for (int x = 0; x < width; ++x) {
                for (int y = 0;  y < height; ++y) {
                    Color pixel = img->at(x, y);
                    // Rotate the pixel to the new position (inverse coordinates)
                    final_image->at(y, width-1-x) = pixel;
                }
            }
            return final_image;
            }
        }
    }

