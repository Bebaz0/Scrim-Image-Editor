#include "Color.hpp"
#include <iostream>

using std::istream;

namespace prog {
    Color::Color() : red_(0),green_(0),blue_(0){
    } //"Resets" the rgb values of a color to 0 (becomes dark)

    Color::Color(const Color &other) :red_(other.red()),green_(other.green()),blue_(other.blue()){
    } //Copys the rgb values of a color to another

    Color::Color(rgb_value red, rgb_value green, rgb_value blue) : red_(red), green_(green), blue_(blue) {
    } //Constructor

    rgb_value Color::red() const {
        return red_;
    } //Returns the red value

    rgb_value Color::green() const {
        return green_;
    } //Returns de green value

    rgb_value Color::blue() const {
        return blue_;
    } //Returns the blue value

    //Returns as a refrence:

    rgb_value &Color::red() {
        return red_;
    }

    rgb_value &Color::green() {
        return green_;
    }

    rgb_value &Color::blue() {
        return blue_;
    }
}


// Use to read color values from a script file.
istream &operator>>(istream &input, prog::Color &c) {
    int r, g, b;
    input >> r >> g >> b;
    c.red() = r;
    c.green() = g;
    c.blue() = b;
    return input;
}

std::ostream &operator<<(std::ostream &output, const prog::Color &c) {
    output << (int) c.red() << ":" << (int) c.green() << ":" << (int) c.blue();
    return output;
}
