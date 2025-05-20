//
// Created by Diogo Coelho on 20/05/2025.
//

#include "Command/Replace.hpp"
#include "Color.hpp"
#include "Image.hpp"

namespace prog {

    Replace::Replace(int r1, int g1, int b1, int r2, int g2, int b2) : Command("replace"), from(r1, g1, b1), to(r2, g2, b2) {}

    Image* Replace::apply(Image* img) {
        int total1;
        total1=from.red()+from.green()+from.blue();
        for (int y = 0; y < img->height(); ++y) {
            for (int x = 0; x < img->width(); ++x) {
                int totalat=img->at(x,y).red()+img->at(x,y).green()+img->at(x,y).blue();
                if (totalat == total1) {
                    img->at(x, y) = to;
                }
            }
        }
        return img;
    }

}