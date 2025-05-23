#include <Command/h_mirror.hpp>


namespace prog {
    namespace command {
        H_mirror::H_mirror() : Mirror("H_mirror") {}

        void H_mirror::direction(int x, int y, int width, int height, int& new_x, int& new_y) const {
            // For horizontal mirror
            new_x = width - 1 - x;
            new_y = y;
        }
    }
}
