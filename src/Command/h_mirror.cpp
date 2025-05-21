#include "Command/h_mirror.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        H_mirror::H_mirror() : Command("h_mirror") {}

        Image* H_mirror::apply(Image* input) {
            for (int y = 0; y < input->height(); ++y) {
                for (int x = 0; x < input->width() / 2; ++x) {
                    std::swap(input->at(x, y), input->at(input->width() - 1 - x, y));
                }
            }
            return input;
        }
    }
}