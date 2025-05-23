//
// Created by Daniel on 22/05/2025.
//

#include "Command/Chain.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {

        std::set<std::string> Chain::visited_files_;

        Chain::Chain(const std::vector<std::string> &scrim_files): Command("Chain") {}
        Image *Chain::apply(Image *img) {

            Image* current_image = img;

        }
    }
}
