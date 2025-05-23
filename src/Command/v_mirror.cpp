#include "Command/v_mirror.hpp"

namespace prog {
    namespace command {
        V_mirror::V_mirror() : Mirror("V_mirror") {}

        void V_mirror::direction(int x, int y, int width, int height, int& new_x, int& new_y) const {
            // For vertical mirror
            new_x = x;
            new_y = height - 1 - y;
        }
    }
}