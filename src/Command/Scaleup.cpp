//
// Created by Afonso Lima on 21/05/2025.
//

#include "Command/Scaleup.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {

        Scaleup::Scaleup(int x, int y)  :Command("Scaleup"), x(x), y(y) {}

        /// @brief Applies the scaleup command to the image
        Image *Scaleup::apply(Image *img) {
            Image* final = new Image(img->width() * x, img->height() * y);
            for (int i = 0; i < img->width(); i++) {
                for (int j = 0; j < img->height(); j++) {
                    Color pixel = img->at(i, j);
                    for (int k = 0; k < x; k++) {
                        for (int l = 0; l < y; l++) {
                            final->at(i * x + k, j * y + l) = pixel;
                        }
                    }
                }
            }
            return final;
        };
    }
}
