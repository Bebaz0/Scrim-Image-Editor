#ifndef H_MIRROR_HPP
#define H_MIRROR_HPP

#include "Command/Mirror.hpp"

namespace prog {
    namespace command {

        class H_mirror : public Mirror {
        public:

            ///@brief Mirrors the image horizontally
            H_mirror();

        protected:
            /// @brief Changes the direction of the pixel for a vertical mirror
            void direction(int x, int y, int width, int height, int& new_x, int& new_y) const;

        };
    }
}

#endif // H_MIRROR_HPP


