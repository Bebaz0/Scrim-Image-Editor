//
// Created by danielramaa on 5/14/25.
//
#include "Command/Invert.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        Invert::Invert() : Command("Invert") {}

            Image *Invert::apply(Image *img) {
                int width = img->width();
                int height = img->height();

                for (int x = 0; x < width; ++x) {
                    for (int y = 0; y < height; ++y) {
                        Color pixel = img->at(x, y);

                        // Invert each color (255 - value)
                        int r = 255 - pixel.red();
                        int g = 255 - pixel.green();
                        int b = 255 - pixel.blue();

                        img->at(x, y) = Color(r, g, b);
                    }
                }
                return img;
            }
        }
    }

