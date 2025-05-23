#ifndef V_MIRROR_HPP
#define V_MIRROR_HPP

#include "Command/Mirror.hpp"

namespace prog {
    namespace command {
        /// @brief Class to apply a vertical mirror effect on an image
        class V_mirror : public Mirror {
        public:
            /// @brief Constructor to initialize the command with the name of the inherited command
            V_mirror();
        protected:
            /// @brief Changes the direction of the pixel for a vertical mirror
            void direction(int x, int y, int width, int height, int& new_x, int& new_y) const override;
        };
    }
}

#endif //V_MIRROR_HPP