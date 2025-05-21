//
// Created by danielramaa on 5/14/25.
//

#ifndef PROJECT_TO_GRAY_SCALE_HPP
#define PROJECT_TO_GRAY_SCALE_HPP

#include "Command.hpp"

namespace prog{
    namespace command{
        class to_gray_scale : public Command{
        public:
            ///brief Applies the gray scale filter to the image
            to_gray_scale();


            Image *apply(Image *img) override;

        };

    }
}


#endif //PROJECT_TO_GRAY_SCALE_HPP
