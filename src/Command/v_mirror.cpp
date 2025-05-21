#include "Command/v_mirror.hpp"
#include "Image.hpp"
#include "Color.hpp"
namespace prog {
    namespace command {
        V_mirror::V_mirror() : Command("v_mirror") {}

        Image* V_mirror::apply(Image* img) {
            if (!img) return img;
            
            for (int x = 0; x < img->width(); ++x) {
                for (int y = 0; y < img->height() / 2; ++y) {
                    std::swap(img->at(x, y), img->at(x, img->height() - 1 - y));
                }
            }
            return img;
        }
    }
}