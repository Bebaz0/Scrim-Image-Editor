//
// Created by danielramaa on 5/21/25.
//

#ifndef PROJECT_SLIDE_HPP
#define PROJECT_SLIDE_HPP
#include "Command.hpp"

namespace prog{
    namespace command{
        class Slide : public Command{
        public:
            Slide(int x, int y);
            Image *apply(Image *img) override;

        private:
            int x_;
            int y_;

        };

    }
}

#endif //PROJECT_SLIDE_HPP
