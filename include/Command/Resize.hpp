#ifndef RESIZE_HPP
#define RESIZE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Resize : public Command {
        public:
            Resize(int x, int y, int w, int h);

            Image *apply(Image *img) override;

        private:
            int x_;
            int y_;
            int w_;
            int h_;
        };
    }
}

#endif //RESIZE_HPP
