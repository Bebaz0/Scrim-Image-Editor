
#ifndef __prog_Color_hpp__
#define __prog_Color_hpp__

#include <iostream>

namespace prog {
    typedef unsigned char rgb_value;

    ///@brief Class to represent a color in RGB format
    class Color {


    public:
        ///@brief Constructor for Color class
        Color();

        /// @brief Copy constructor for Color class
        Color(const Color &c);

        /// @brief Constructor for Color class
        Color(rgb_value r, rgb_value g, rgb_value b);

        ///@return Red value of the color
        rgb_value red() const;

        ///@return Red value of the color
        rgb_value &red();

        /// @return Green value of the color
        rgb_value green() const;

        ///@return Green value of the color
        rgb_value &green();

        /// @return Blue value of the color
        rgb_value blue() const;

        ///@return Blue value of the color
        rgb_value &blue();

    private:
        rgb_value red_ ,green_,blue_; //variables to store the color values
    };
}



std::istream &operator>>(std::istream &input, prog::Color &c);

std::ostream &operator<<(std::ostream &output, const prog::Color &c);


#endif
