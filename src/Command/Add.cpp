//
// Created by limaa on 19/05/2025.
//

#include "Command/Add.hpp"
#include "Color.hpp"
#include "Image.hpp"
#include "PNG.hpp"

namespace prog {
    namespace command {

        Add::~Add() {};

        Add::Add(std::string& filename,rgb_value r,rgb_value g,rgb_value b, int x, int y) : Command("Add"),filename(filename), neutral(r,g,b),x(x),y(y){}

        Image *Add::apply(Image *img) {
            Image* source = loadFromPNG(filename); //upload file to the variable source

            for (int sy = 0; sy<source->height();sy++) {
                for (int sx = 0; sx<source->width();sx++) {
                    //coordenates for the final image
                    int dx = x + sx;
                    int dy = y + sy;

                    const Color& pixel_color = source->at(sx,sy); //color at that pixel on the source img

                    //Checks if it is neutral color and if not then copy color to final
                    if (pixel_color.red() != neutral.red() ||
                       pixel_color.green() != neutral.green() ||
                       pixel_color.blue() != neutral.blue()) {
                        img->at(dx, dy) = pixel_color;
                       }

                }
            }
            return img;
        }
    }
}
