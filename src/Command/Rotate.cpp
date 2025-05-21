//
// Created by Afonso Lima on 21/05/2025.
//

#include "Command/Rotate.hpp"
#include "Color.hpp"
#include "Image.hpp"


namespace prog {
    namespace command {

        Rotate::Rotate(const std::string& name) : Command(name) {}

        Image *Rotate::apply(Image *img) {
            int width = img->width();
            int height = img->height();

            Image *final_image = new Image(height, width); // Create a new image with rotated dimensions
            for (int x = 0; x < width; ++x) {
                for (int y = 0;  y < height; ++y) {
                    Color pixel = img->at(x, y);
                    // Rotate the pixel to the new position (inverse coordinates)
                    int new_x, new_y;
                    //defines the direction of the rotation depending on who´s calling:
                    direction(x, y, width, height, new_x, new_y);
                    final_image->at(new_x, new_y) = pixel;
                }
            }
            return final_image;
        }
    }
}