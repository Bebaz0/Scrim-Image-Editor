//
// Created by danielramaa on 5/21/25.
//

#ifndef PROJECT_CROP_HPP
#define PROJECT_CROP_HPP

#include "Command.hpp"


namespace prog{
    namespace crop{
        class Crop : public Command {
            public:
                Crop(int x, int y, int width, int height);
                Image *apply(Image *img) override;
            private:
                int x_;
                int y_;
                int width_;
                int height_;
        };
    }
}

#endif //PROJECT_CROP_HPP
