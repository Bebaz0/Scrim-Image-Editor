//
// Created by Diogo Coelho on 20/05/2025.
//

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include "Command.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {

    class Replace : public Command {
    private:
        Color from;
        Color to;

    public:
        ///@brief Replaces the color of the image
        ///r1,g1,b1 color to be replaced
        ///r2,g2,b2 color to replace
        Replace(int r1, int g1, int b1, int r2, int g2, int b2);
        Image* apply(Image* img) override;
    };

}


#endif //REPLACE_HPP
