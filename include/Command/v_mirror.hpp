#ifndef V_MIRROR_HPP
#define V_MIRROR_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {
        class V_mirror : public Command {
        public:
            ///brief Mirrors the image vertically
            V_mirror();
            Image *apply(Image *img) override;
        };

    }
}

#endif //V_MIRROR_HPP