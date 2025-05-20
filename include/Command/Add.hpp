//
// Created by limaa on 19/05/2025.
//

#ifndef ADD_H
#define ADD_H

#include "Command.hpp"
#include "Color.hpp"
#include "Image.hpp"
#include <string>

namespace prog {
    namespace command {
        class Add : public Command {
        public:

            Add(std::string& filename,int r,int g,int b, int x, int y);

            Image *apply(Image *img) override;



        private:
            std::string filename; //The png file to copy
            Color neutral; //Neutral color
            int x;
            int y;
        };
    }
}

#endif //ADD_H
