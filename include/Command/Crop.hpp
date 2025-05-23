//
// Created by danielramaa on 5/21/25.
//

#ifndef PROJECT_CROP_HPP
#define PROJECT_CROP_HPP

#include "Command.hpp"


namespace prog{
    namespace command{
        class Crop : public Command {
            public:
                ///@brief Crops the image to the specified dimensions.
                ///@param x X coordinate of the top-left corner of the crop.
                ///@param y Y coordinate of the top-left corner of the crop.
                ///@param width Width of the crop.
                ///@param height Height of the crop.
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
