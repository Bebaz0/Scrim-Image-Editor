#include "Command/Resize.hpp"

namespace prog {
    namespace command {

        Resize::Resize(int x, int y, int w, int h) : Command("resize"), x_(x), y_(y), w_(w), h_(h) {
        }

        Image *Resize::apply(Image *img) {
            Color fill(255, 255, 255);

            Image *new_img = new Image(w_, h_, fill);

            for (int i = 0; i < h_; ++i) {
                for (int j = 0; j < w_; ++j) {
                    int old_x = x_ + j;
                    int old_y = y_ + i;

                    if (old_x >= 0 && old_x < img->width() && old_y >= 0 && old_y < img->height()) {
                        new_img->at(j, i) = img->at(old_x, old_y);
                    }
                }
            }

            delete img;
            return new_img;
        }
    }
}
