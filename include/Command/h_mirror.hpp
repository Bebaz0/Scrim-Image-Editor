#ifndef H_MIRROR_HPP
#define H_MIRROR_HPP

#include "Command.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {

        class H_mirror : public Command {
        public:

            ///@brief Mirrors the image horizontally
            H_mirror();

            Image *apply(Image *img) override;

        };

    }
}

#endif // H_MIRROR_HPP


