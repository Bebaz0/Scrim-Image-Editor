//
// Created by Afonso Lima on 19/05/2025.
//

#ifndef FILL_H
#define FILL_H

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Fill : public Command {
        public:
            Fill();

            Fill(int x,int y,int w, int h, rgb_value r,rgb_value g,rgb_value b);

            Image *apply(Image *img) override;

            //returns the string representation of this com
            std::string toString() const override;

        private:
            int w;
            int h;
            Color fill;
            int x;
            int y;
        };
    }
}


#endif //FILL_H
