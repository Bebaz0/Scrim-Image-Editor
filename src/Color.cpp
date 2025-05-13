#include "Color.hpp"
#include <iostream>

using std::istream;

namespace prog {
    Color::Color() : red_(0),green_(0),blue_(0){
    } //Dá "reset" dos valores rgb da cor

    Color::Color(const Color &other) :red_(other.red()),green_(other.green()),blue_(other.blue()){
    } //Copia os valores rgb de uma cor

    Color::Color(rgb_value red, rgb_value green, rgb_value blue) : red_(red), green_(green), blue_(blue) {
    } //Construtor

    rgb_value Color::red() const {
        return red_;
    } //Retorna o valor "red" da cor

    rgb_value Color::green() const {
        return green_;
    } //Retorna o valor "green" da cor

    rgb_value Color::blue() const {
        return blue_;
    } //Retorna o valor "blue" da cor

    // TODO:Acho que é assim que deve ficar mas not sure yet é preciso verificar

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
